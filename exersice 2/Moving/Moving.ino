#include "line_follow.h"
#include "velocity.h"

void setup() {
  pinMode(CLK, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLK), encoderISR, RISING);
  Serial.begin(9600);
  lastMeasureTime = millis();
  go_forward_distance(100);
}

void loop() {
}

