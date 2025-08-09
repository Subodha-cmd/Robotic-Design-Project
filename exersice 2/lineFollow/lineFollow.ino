#include "moves.h"

int left_ir = 51;
int right_ir = 53;


void setup() {
  pinMode(left_ir,INPUT);
  pinMode(right_ir,INPUT);

  //LINE FOLLOW PART
  while(true){
    bool left = digitalRead(left_ir);
    bool right = digitalRead(right_ir);

    if(left == 1 && right == 1){
      go_forward(100);
    }
    else if(left == 0 && right == 1){
      turn_left(100);
    }
    else if(left == 1 && right == 0){
      turn_right(100);
    }
    else{
      stop();
    }
      }
}

void loop() {
  // put your main code here, to run repeatedly:

}
