int ir_sensor_right = 51;
int ir_sensor_left = 53;

int sw = 45;
int clk =49;
int dt = 47;

#include <AFMotor.h>
#include "line_follow.h"

void setup(){

  pinMode(ir_sensor_right,INPUT);
  pinMode(ir_sensor_left,INPUT);

  Serial.begin(9600);
  go_forward(100);
  delay(100);
  
  // line follower
    
}

void loop(){
  int right = digitalRead(ir_sensor_right);
  int left = digitalRead(ir_sensor_left);

  if (right == HIGH && left == HIGH) {
    
    go_forward(40);
  } 
  else if (right == LOW && left == HIGH) {
    
    turn_right(100);
  } 
  else if (right == HIGH && left == LOW) {
    
    turn_left(100);
   }
  else {
    stop(); // If both sensors detect black/no line
  }

  delay(10);
   }







