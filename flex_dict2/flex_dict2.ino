const int flexpin1 = 0; 
const int flexpin2 = 2; 
const int flexpin3 = 3; 
const int flexpin4 = 4; 
const int flexpin5 = 5; 
int Matrix[3][5] = { {777 ,777,777,777, 777},
                    {820,820,820,820, 820},
                    {860,860,860,860, 860}
                     };

//int flexposition[] =  {600, 600, 600, 600, 600};
int tolerance = 5;    
long unsigned flex;

                
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
