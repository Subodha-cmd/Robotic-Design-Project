#include <AFMotor.h>
#include <Servo.h>
#include "servo.h"
#include "arm.h"

int IR_sensor = 22;
int LED = 52;


void setup() {
  Serial.begin(9600);
  Serial.println("Working");
  pinMode(IR_sensor,INPUT);
  pinMode(LED,OUTPUT);

  // Limbs
  myservo1.attach(10);
  myservo2.attach(9);

  grab_the_box();
}

void loop() {
}
