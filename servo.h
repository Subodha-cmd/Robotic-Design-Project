#ifndef SERVO_H
#define SERVO_H
#include <Arduino.h>
#include <Servo.h>

Servo myservo1;

void servoturn(){
  for (int pos = 0 ; pos < 180 ; pos++){
    myservo1.write(pos);
    delay(20);
  }
  for (int pos = 180 ; pos > 0 ; pos--){
    myservo1.write(pos);
    delay(20);
  }
};

#endif 