#ifndef ARM_H
#define ARM_H
#include <Arduino.h>
#include <Servo.h>

Servo myservo2;

void grab_the_box(){
  
  for (int pos = 0 ; pos < 90 ; pos++){
    myservo1.write(pos);
    delay(30);
  }
  for (int pos = 0 ; pos < 90 ; pos++){
    myservo2.write(pos);
    delay(30);
  }
  for (int pos = 90 ; pos > 0 ; pos--){
    myservo1.write(pos);
    delay(30);
  }
  for (int pos = 90 ; pos > 0 ; pos--){
    myservo2.write(pos);
    delay(30);
  }
};

#endif 