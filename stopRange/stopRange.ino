// Robot backs up and turns right when range sensor outputs 0

int distPin = 3; // Range sensor connected to digital pin 3

//Standard PWM DC control
int speed1 = 5;     //M1 Speed Control (left side)
int speed2 = 6;     //M2 Speed Control (right side)
int direction1 = 4;    //M1 Direction Control
int direction2 = 7;    //M1 Direction Control

void stop()  //Stop
{
  digitalWrite(speed1,LOW);   
  digitalWrite(speed2,LOW);      
}   

void advance(char a,char b)  //Move forward
{
  analogWrite (speed1,a);      
  digitalWrite(direction1,HIGH);    
  analogWrite (speed2,b);    
  digitalWrite(direction2,HIGH);
}  

void back_off (char a,char b)   //Move backward
{
  analogWrite (speed1,a);
  digitalWrite(direction1,LOW);   
  analogWrite (speed2,b);    
  digitalWrite(direction2,LOW);
}
void turn_L ()             //Turn Left
{
  analogWrite (speed1, 25);
  digitalWrite(direction1,HIGH);    
  analogWrite (speed2, 255);    
  digitalWrite(direction2,HIGH);
}

void turn_R ()    //Turn Right
{
  analogWrite (speed1, 255);
  digitalWrite(direction1,HIGH);    
  analogWrite (speed2, 25);    
  digitalWrite(direction2, HIGH);
}

void setup() {
  pinMode(distPin, INPUT);
  int i;
  for(i=4;i<=7;i++)
    pinMode(i, OUTPUT);
}

void loop() {
  int value = digitalRead(distPin);
  if (value == 0) {
    stop();
    back_off(100, 100);
    delay(3000);
    turn_R();
    delay(500);
  }
  else advance(100, 100);
  delay(500);
}
