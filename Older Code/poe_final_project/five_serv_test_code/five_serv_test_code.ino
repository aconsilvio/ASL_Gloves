#include <Servo.h>

const int buttonPin1 = 2;     // the number of the pushbutton pin
//const int buttonPin2 = 3; 

unsigned int rotation = 90;
int buttonState1 = LOW;  
unsigned long start_millis;
unsigned long current_millis;
//int buttonState2 = LOW;  

Servo servo1; // create servo object
Servo servo2; // create servo object
Servo servo3; // create servo object
Servo servo4; // create servo object
Servo servo5; // create servo object

Servo list[] ={servo1, servo3, servo5}; 

void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  
  servo1.attach(9);
//  servo2.attach(10);
  servo3.attach(11);
//  servo4.attach(12);  
  servo5.attach(13);
  
  servo1.write(0);
//  servo2.write(0);
  servo3.write(0);
//  servo4.write(0);
  servo5.write(0);
  pinMode(buttonPin1, INPUT);
//  pinMode(buttonPin2, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  buttonState1 = digitalRead(buttonPin1);
//  buttonState2 = digitalRead(buttonPin2);

//  if (buttonState2 == HIGH) 
//    {
//      // turn LED on:
//      delay(50);
//      servo1.write(rotation);
//      Serial.println("button 2 pressed - rotate 1");
//    } 
//  else 
//    {
//      // turn LED off:
//      servo1.write(0);
//      Serial.println("button 2 not pressed - no rotation");
//    }

    if (buttonState1 == HIGH) 
      {
        Serial.println("button 1 pressed - rotate");
          for (int i=0; i <= 5; i++) 
          {
              list[i].write(rotation);
              Serial.print(i);
              delay(100);
            }
       }
      

       if (buttonState1 == LOW)
       {
        Serial.println("button not pressed - no rotate");
          for (int i=0; i <= 5; i++) 
          {
              list[i].write(0);
              Serial.print(i);
              delay(100);
            }
       }
        
}


