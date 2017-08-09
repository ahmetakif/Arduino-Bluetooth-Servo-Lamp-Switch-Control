#include <Servo.h>

Servo steer;

const int buzzer = 11;
String readString;

int val1 = 120;
int val2 = 50;
int val3 = 88;

void setup() 
{
  Serial.begin(9600); 
  pinMode(buzzer , OUTPUT);
  steer.attach(3);   
}
void loop() 
{
  while (Serial.available()) 
  {
    delay(3);  
    char c = Serial.read();
    readString += c; 
  }
  if (readString.length() >0) 
  {
    Serial.println(readString);
    if (readString == "k")
    {
      steer.write(val1);
    }
    else if (readString == "a")
    {
      steer.write(val2);
    }
    else
    {
      steer.write(val3);
    }
    if (readString == "x")
    {
      digitalWrite(buzzer , 1);
    }
    else
    {
      digitalWrite(buzzer , 0);
    }
    readString="";
  } 
}
