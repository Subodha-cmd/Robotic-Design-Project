#ifndef MOVES_H
#define MOVES_H

#include <Arduino.h>
#include <AFMotor.h>

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);

void go_forward(int speed){
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
}

void go_backward(int speed){
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
}

void turn_right(int speed){
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);

  motor1.run(BACKWARD);
  motor2.run(FORWARD);
}

void turn_left(int speed){
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);

  motor1.run(FORWARD);
  motor2.run(BACKWARD);
}

void stop(){
  
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}

#endif
