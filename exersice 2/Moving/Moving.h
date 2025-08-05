#ifndef MOVING_H
#define MOVING_H

#include <AFMotor.h>
#include <NewPing.h>
#include <Arduino.h> 

#define TRIGGER_PIN 53
#define ECHO_PIN 51
#define MAX_DISTANCE 200

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);

AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
AF_DCMotor motor3(3);
AF_DCMotor motor4(4);

void go_forward(int time=100, int speed= 90){
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);

  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(FORWARD);
  motor4.run(FORWARD);

  delay(time*1000);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
};
void go_backward(int time=100, int speed= 90){
  motor1.setSpeed(speed);
  motor2.setSpeed(speed);
  motor3.setSpeed(speed);
  motor4.setSpeed(speed);

  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);

  delay(time*1000);

  motor1.run(RELEASE);
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);

};
void go_backward_obstacal_ahead(){
  unsigned int distance = sonar.ping_cm();
  if(distance < 10 && distance != 0){
    go_backward(1,100);
    Serial.print(distance);
  }

}

#endif