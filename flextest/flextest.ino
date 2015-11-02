const int flexpin = 0; 
int mappedposition = 0;



void setup() 
{ 
  // Use the serial monitor window to help debug our sketch:

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int flexposition;

  flexposition = analogRead(flexpin);
  //mappedposition = map(flexposition, 700, 800, 0, 200);
  Serial.println(flexposition);
  
  
  delay(100);
}
