// array for open hand readings
// will be 8 total w/ all sensors
// this will be our list of 26 letters
//int openHand[] = {750, 750, 750};
// array for closed hand readings
//int closedHand[] = {900, 900,900};
//array for bent hand readings
//int bentHand[] = {820,820,820};
float  Matrix[][5] = {{751, 752, 753, 754, 755}, {901, 902,903, 904, 905}, {821,822,823, 824, 825}};
int flex[] =  {921, 922,925, 925, 925};
int tolerance = 20;
 
void setup() {
  Serial.begin(250000);
  Serial.println("set up");
  
  }
 
void loop() {
  flex[5] = Serial.read();
  for (int pos = 0; pos < 3; pos++)
    {
    for (int element = 0; element < 5; element++){
      //Serial.print(Matrix[pos][element]);
      if (Matrix[pos][element] <= flex[element] - tolerance)
      {
       Serial.println("no ");
       //Serial.print(flex[element] + tolerance);
       pos+=1;
  
        }
        else {
        //Serial.println("Position ");
        Serial.println("at a position");
             delay(1000);
          }
      }
     }
}
