#include <SoftwareSerial.h>
SoftwareSerial Bluetooth (10,5); // (rx,tx)
const byte flex_pins[] = {A0, A1, A2, A3, A4, A5, A6, A7};
long int starttime;
int tolerance_array[] = {20, 20, 20,20, 20, 20, 20, 20} ;
long unsigned flex1;
long unsigned flex2;
long unsigned flex3;
long unsigned flex4;
long unsigned flex5;
long int num_reading = 0;
int counter = 0;
long int flex_array[8];
long int flexposition[8];
int j;  //variable for looping through sensor values
int i;  //variable for looping through character values
int testtime = 2000;
char* prev_letter;
char* letter_list[] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J","K","L","M", "N","O","P","Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z" , "SPACE", "DUPLICATE"};
byte num_pins = sizeof(flex_pins) / (sizeof(flex_pins[1]));
int num_letters = sizeof(letter_list) / (sizeof(letter_list[1]));
int is_good;
long lastDebounceTime = 0;
long debounceDelay = 500;
#include <LiquidCrystal.h>
//initialize the library pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

int Matrix[28][8];

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("set up");
  Bluetooth.begin(9600);
  Bluetooth.println("set up");
//  lcd.begin(16, 2);
//  lcd.setCursor(0, 0);
//  lcd.clear();
  calibration();
}

void calibration() {
  for (i = 0; i < num_letters; i++) {
//    lcd.clear();
//    lcd.print("Hold:  ");
//    lcd.print(letter_list[i]);
    Serial.print("Hold:  ");
    Serial.println(letter_list[i]);
    Bluetooth.print("Hold:  ");
    Bluetooth.println(letter_list[i]);
    delay(2500);
//      lcd.setCursor(0, 1);
//    lcd.print("Reading:  ");
//      lcd.print(letter_list[i]);
     Serial.print("Reading:  ");
     Serial.println(letter_list[i]);
     Bluetooth.print("Reading:  ");
     Bluetooth.println(letter_list[i]);
    starttime = millis();
    num_reading = 0;
    for (int l = 0; l < num_pins; l++) flex_array[l] = 0;
    while (millis() - starttime < testtime) {
      
      for (j = 0; j < num_pins; j++) flex_array[j] += analogRead(flex_pins[j]);
      num_reading += 1;
    }

    //flexposition[]= {flex1/num_reading, flex2/num_reading, flex3/num_reading, flex4/num_reading, flex5/num_reading, i};
    for (j = 0; j < num_pins; j++) Matrix[i][j] = flex_array[j] / num_reading;


    // Matrix2[i][6]= flexposition;
  }
}

void loop() {
  // put your main code here, to run repeatedly:

//  if (counter == 15) {
//    lcd.setCursor(0, 1);
//  }
//  if (counter == 30) {
//    lcd.clear();
//    lcd.setCursor(0, 0);
//    counter = 0;
//  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    for (j = 0; j < num_pins; j++) flex_array[j] = analogRead(flex_pins[j]);
    for (i = 0; i < num_letters; i++) { //3 is size of matrix initalized above
      is_good = 0;
      for (j = 0; j < 8; j++) {   
        if (abs(flex_array[j] - Matrix[i][j]) <= tolerance_array[j])  {
          ++is_good;
          
        }
      }
      if (is_good == 8) {
        if(letter_list[i] != prev_letter){
        //for loop of actual values and calibration values
         if(letter_list[i] == "DUPLICATE"){
//              lcd.print(prev_letter);
             // Serial.print(Matrix[i][j]);
              Serial.print(prev_letter);
              Bluetooth.print(prev_letter);
              counter += 1;         
              lastDebounceTime = millis();
              break;
            }
         else if(letter_list[i] == "SPACE"){
//              lcd.print(" ");
              Serial.print(" ");
              Bluetooth.print(" ");
              counter += 1;         
              lastDebounceTime = millis();
              prev_letter = letter_list[i];
              break;
            }
         else{
//            lcd.print(letter_list[i]);
            Serial.print(letter_list[i]);
            Bluetooth.print(letter_list[i]);
            prev_letter = letter_list[i];
            counter += 1;
            lastDebounceTime = millis();
            break;
        }
        
        }
      }
    }
  }
}
