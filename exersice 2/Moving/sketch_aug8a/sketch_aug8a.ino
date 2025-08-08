#include "line_follow.h"
#include "velocity.h"

void setup() {
  pinMode(CLK, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLK), encoderISR, RISING);
  Serial.begin(9600);
  lastMeasureTime = millis();

  go_forward();
}

void loop() {
  float angularVelocity = getAngularVelocity();  // rad/s
  if (angularVelocity >= 0) {
    Serial.print("Angular Velocity: ");
    Serial.print(angularVelocity);
    Serial.println(" rad/s");
}}

