#include <SoftwareSerial.h>
SoftwareSerial Bluetooth (10,5); // (rx,tx)
const byte flex_pins[] = {A0, A1, A2, A3, A4, A5, A6, A7};  //correspond to analog pins on Arduino mini
long int starttime;  //variable for debouncing starttime
int tolerance_array[] = {17 ,15, 20,3, 3, 3, 22, 22};  //tolerances correspond to how different the reading can be from the calibration reading
long int num_reading = 0;  //used to calculate average for calibration array
long int flex_array[8];  //array used to hold sensor data
int j;  //variable for looping through sensor values
int i;  //variable for looping through character values
int testtime = 2000;  // calibration time
char* prev_letter;  //variable to remember last signed letter for duplicate function
char* letter_list[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K","L","M", "N","O","P","Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" , "SPACE", "DUPLICATE", "NEWLINE"};
byte num_pins = sizeof(flex_pins) / (sizeof(flex_pins[1]));  //calculate number of analog pins used
int num_letters = sizeof(letter_list) / (sizeof(letter_list[1]));  //calculate number of letters signed
int is_good;  //used to check if the current reading matches all of the calibration readings in a row
long lastDebounceTime = 0;  //variable for debouncing
long debounceDelay = 200;  //variable for debouncing

int Matrix[29][8];  //matrix to load calibration data

void setup() {
  // put your setup code here, to run once:
  delay(7000); //let bluetooth figure things out
  Bluetooth.begin(9600);  //set up bluetooth serial
  Bluetooth.println("set up");
  calibration();  //run calibration function to create Matrix
}

void calibration() {
  for (i = 0; i < num_letters; i++) {
    Bluetooth.print("Hold:  ");  //tell user what letter to hold
    Bluetooth.println(letter_list[i]);
    delay(2500);
     Bluetooth.print("Reading:  ");
     Bluetooth.println(letter_list[i]);
    starttime = millis();  //start millis
    num_reading = 0;  
    for (int l = 0; l < num_pins; l++) flex_array[l] = 0;
    while (millis() - starttime < testtime) {
      //add reading values to flex_array array
      for (j = 0; j < num_pins; j++) flex_array[j] +=analogRead(flex_pins[j]);
      num_reading += 1;  //keep track of the number of times values are added to the array
    }
    for (j = 0; j < num_pins; j++) Matrix[i][j] = flex_array[j] / num_reading;
    //add an averaged sensor value array to the matrix
  }
}

void loop() {

  //start bouncing
  if ((millis() - lastDebounceTime) > debounceDelay) {
    //create array of current sensor values
    for (j = 0; j < num_pins; j++) flex_array[j] = analogRead(flex_pins[j]);
    //start looping thoughrows
    for (i = 0; i < num_letters; i++) { //3 is size of matrix initalized above
      is_good = 0;
      for (j = 0; j < 8; j++) {   
        //if sensor value is within a given tolerance
        if (abs(flex_array[j] - Matrix[i][j]) <= tolerance_array[j])  {
          ++is_good;
          
        }
      }
      if (is_good == 8) {  //if it reaches the final sensor value and it is correct
        if(letter_list[i] != prev_letter){  //if current letter is not the prevoid letter
        //for loop of actual values and calibration values
         if(letter_list[i] == "DUPLICATE"){  //if the letter signed indicates duplicate
            if (prev_letter =="NEWLINE")  //if the previous letter was newline
            {
              Serial.println(prev_letter);  //print previous letter on a new line
            Bluetooth.println(prev_letter);
            prev_letter = letter_list[i];  //reset letter
            lastDebounceTime = millis();  //reset debounce time
            break; //start checking values again
              }
            else{
              Bluetooth.print(prev_letter);  //otherwise print letter next to previous letter
              lastDebounceTime = millis();
              break;
            }}
         else if(letter_list[i] == "SPACE"){  //if letter indicates space
              if (prev_letter =="NEWLINE")
            {
            Bluetooth.println("_");
            prev_letter = letter_list[i];
            lastDebounceTime = millis();
            break;
              }
            else{
              Bluetooth.print("_");
              lastDebounceTime = millis();
              prev_letter = letter_list[i];
              break;
            }}
         else if(letter_list[i]=="NEWLINE"){  //if letter indicates newline, just set previous letter to new line so the next letter will print on a new line
              prev_letter = letter_list[i];
              break;
         }
         
         else{  //otherwise print the current letter
            if (prev_letter =="NEWLINE")
            {
            Bluetooth.println(letter_list[i]);
            prev_letter = letter_list[i];
            lastDebounceTime = millis();
            break;
              }
            else{
            Bluetooth.print(letter_list[i]);
            prev_letter = letter_list[i];
            lastDebounceTime = millis();
            break;
        }
        
        }
      }
    }
  }
}
}
