const int flexpin = 0; 
int Matrix[3][5] = { {770 ,770,770,770, 770},
                    {800,800,800,800, 800},
                    {850,850,850,850, 850}
                     };

//int flexposition[] =  {600, 600, 600, 600, 600};
int tolerance = 5;   
int long flex;

                
void setup() {
  // put your setup code here, to run once:
  Serial.begin(250000);
  Serial.println("set up");
}

void loop() {
  // put your main code here, to run repeatedly:

  flex = analogRead(flexpin);
  int flexposition[] = {flex, flex, flex, flex, flex};
  for (int i =0; i < 3; i++) {  //3 is size of matrix initalized above
    for (int j =0; j < 5; j++) {
      if ((flexposition[j] <= Matrix[i][j] + tolerance)  && (flexposition[j] >= Matrix[i][j] - tolerance) ){
        if ( j == 4){
          if( Matrix[i][j] == 770){
             Serial.print("open");
             Serial.print(" ");
             Serial.println(flexposition[1]);
             i = 0;
             j = 0;
             break;
            }
          else if( Matrix[i][j] == 800){
             Serial.print("bent");
             Serial.print(" ");
             Serial.println(flexposition[1]);
             i = 0;
             j = 0;
             break;
            }

          else if ( Matrix[i][j] == 850){
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
