const int flexpin1 = A1; // thumb
const int flexpin2 = A2; // index
const int flexpin3 = A3; // the bird
const int flexpin4 = A4; // ring
const int flexpin5 = A5; // pinky
int Matrix[3][5] = { {675, 686, 650, 660, 700},    //open
                     {660, 640, 585, 580, 620},    // bent 
                     {630, 554, 477, 520, 530}     // closed
                     };

//int flexposition[] =  {600, 600, 600, 600, 600};
int tolerance = 10;    
long unsigned flex1;
long unsigned flex2;
long unsigned flex3;
long unsigned flex4;
long unsigned flex5;
                
void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  Serial.println("set up");
}

void loop() {
  // put your main code here, to run repeatedly:

 
  for (int i =0; i < 3; i++) {  //3 is size of matrix initalized above
    for (int j =0; j < 5; j++) {
       flex1 = analogRead(flexpin1);
       flex2 = analogRead(flexpin2);
       flex3 = analogRead(flexpin3);
       flex4 = analogRead(flexpin4);
       flex5 = analogRead(flexpin5);
  int flexposition[] = {flex1, flex2, flex3, flex4, flex5};
      if ((flexposition[j] <= Matrix[i][j] + tolerance)  && (flexposition[j] >= Matrix[i][j] - tolerance) ){
        if ( j == 4){
          if( Matrix[i][j] == 777){
             Serial.print("open");
             Serial.print(" ");
             Serial.println(flexposition[1]);
             i = 0;
             j = 0;
             break;
            }
          else if( Matrix[i][j] == 820){
             Serial.print("bent");
             Serial.print(" ");
             Serial.println(flexposition[1]);
             i = 0;
             j = 0;
             break;
            }

          else if ( Matrix[i][j] == 860){
             Serial.print("closed");
             Serial.print(" ");
             Serial.println(flexposition[1]);
             i = 0;
             j = 0;
             break;
            }
            break;
          }
                     
        }
      else{
        j = 0;
        i += 1;
        }
       if ( i  == 3)
       {
        break;
        }
    }
  }
}
