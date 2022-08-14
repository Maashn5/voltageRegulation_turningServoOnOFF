#include <Servo.h>

int a;//the switich indicator


Servo myServo;
void setup()
{
  pinMode(7, INPUT);
  pinMode(4, OUTPUT);

  myServo.attach(3);
}

void loop()
{
 a=digitalRead(7);//reading the switich value


  

  
  digitalWrite(4,a);// powering the servo by the switich


   if (a==HIGH){// if a is high then move the servo


  myServo.write(90);
  
  }

  
    
    
    
    
    

  
}
