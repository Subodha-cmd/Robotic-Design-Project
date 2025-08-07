int ir_sensor_right = 51;
int ir_sensor_left = 53;

#include <AFMotor.h>
#include "line_follow.h"

void setup(){

  pinMode(ir_sensor_right,INPUT);
  pinMode(ir_sensor_left,INPUT);
  Serial.begin(9600);


  // line follower
  while(true){
    int right = digitalRead(ir_sensor_right);
    int left = digitalRead(ir_sensor_left);

  if (right == HIGH && left == HIGH) {
    go_forward();
  } 
  else if (right == LOW && left == HIGH) {
    turn_right();
  } 
  else if (right == HIGH && left == LOW) {
    turn_left();
  } 
  else {
    stop(); // If both sensors detect black/no line
  }

  delay(80);
    }
}

void loop(){

   }


