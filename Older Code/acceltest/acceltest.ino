int pin0 = A0;    // middle select the input pin for the potentiometer
int pin1 = A1;    // thumb select the input pin for the potentiometer
int pin2 = A2;    // pointer select the input pin for the potentiometer
int pin3 = A3;    // select the input pin for the potentiometer
int pin4 = A4;    // select the input pin for the potentiometer
int pin5 = A5;    // select the input pin for the
int pin6 = A6;    // ring select the input pin for the potentiometer
int pin7 = A7;    // pinky select the input pin for the potentiometer
 
int value0 = 0;  // variable to store the value coming from the sensor
int value1 = 0;  // variable to store the value coming from the sensor
int value2 = 0;  // variable to store the value coming from the sensor
int value3 = 0;  // variable to store the value coming from the sensor
int value4 = 0;  // variable to store the value coming from the sensor
int value5 = 0;  // variable to store the value coming from the sensor
int value6 = 0;  // variable to store the value coming from the sensor
int value7 = 0;  // variable to store the value coming from the sensor
void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
}

void loop() {
  // read the value from the sensor:
  value0 = analogRead(pin0);
  value1 = analogRead(pin1);
  value2 = analogRead(pin2);
  value3 = analogRead(pin3);
  value4 = analogRead(pin4);
  value5 = analogRead(pin5);
  value6 = analogRead(pin6);
  value7 = analogRead(pin7);
  // turn the ledPin on
  Serial.print(value0);
  Serial.print(", ");
  Serial.print(value1);
  Serial.print(", ");
  Serial.print(value2);
  Serial.print(", ");
  Serial.print(value3);
  Serial.print(", ");
  Serial.print(value4);
  Serial.print(", ");
  Serial.print(value5);
  Serial.print(", ");
  Serial.print(value6);
  Serial.print(", ");
  Serial.println(value7);
}
