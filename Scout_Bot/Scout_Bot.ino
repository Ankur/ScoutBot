const int trigpin = 11;
const int echopin = 10;
#define servo1 5
#define servo2 6
long Duration = 0;

void setup()
{
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  pinMode(servo1, OUTPUT);
  pinMode(servo2, OUTPUT);
  Serial.begin(9600);
}



void loop()
{
  digitalWrite(trigpin, LOW);
delayMicroseconds(2);
digitalWrite(trigpin, HIGH); 
delayMicroseconds(10); 
digitalWrite(trigpin, LOW);

Duration = pulseIn(echopin, HIGH);
long Distance_mm = Distance(Duration);
Serial.print("Distance = "); 
Serial.print(Distance_mm);
Serial.println(" mm");
delay(50);
}

long Distance(long time)
{
  long DistanceCalc;
  DistanceCalc = ((time/2.9)/2);
  
  if (DistanceCalc < 150) {
   analogWrite(servo1, -150);
  analogWrite(servo2, 150);
 delay (50);
 
  } 
    else {
    analogWrite (servo2, -230);
    analogWrite (servo1, 230);
    
    }  
  
  return DistanceCalc;
}





