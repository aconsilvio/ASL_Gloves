const int flexpin1 = A0; 
const int flexpin2= A1; 
const int flexpin3 = A2; 
const int flexpin4 = A3; 
const int flexpin5 = A6; 



void setup() 
{ 
  // Use the serial monitor window to help debug our sketch:

  Serial.begin(250000);
}

void loop() {
  // put your main code here, to run repeatedly:
  int flexposition1;
    int flexposition2;
      int flexposition3;
        int flexposition4;
          int flexposition5;

  flexposition1 = analogRead(flexpin1);
  flexposition2 = analogRead(flexpin2);
  flexposition3 = analogRead(flexpin3);
  flexposition4 = analogRead(flexpin4);
  flexposition5 = analogRead(flexpin5);
  //mappedposition = map(flexposition, 700, 800, 0, 200);
  Serial.print(flexposition1);
  Serial.print(", ");
    Serial.print(flexposition2);
  Serial.print(", ");
    Serial.print(flexposition3);
  Serial.print(", ");
    Serial.print(flexposition4);
  Serial.print(", ");
    Serial.println(flexposition5);
  
  
  delay(100);
}
