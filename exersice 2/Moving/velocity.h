#ifndef VELOCITY_H
#define VELOCITY_H

#define CLK 21 // Interrupt-capable pin
#define PPR 30  // Pulses per revolution
#include <Arduino.h>

volatile long pulseCount = 0;
unsigned long lastMeasureTime = 0;


float getAngularVelocity() {
  unsigned long currentTime = millis();
  float deltaTime = (currentTime - lastMeasureTime) / 1000.0; // seconds

  if (deltaTime >= 0.1) {  // Calculate every 100 ms
    noInterrupts();
    long count = pulseCount;
    pulseCount = 0;
    interrupts();

    float revolutions = (float)count / PPR;
    float omega = (revolutions / deltaTime) * 2.0 * PI;  // rad/s

    lastMeasureTime = currentTime;
    return omega;
  }

  return -1.0;  // Not ready yet
}
void encoderISR() {

  pulseCount++;
  }


/*

sample code here

void setup() {
  pinMode(CLK, INPUT);
  attachInterrupt(digitalPinToInterrupt(CLK), encoderISR, RISING);

  Serial.begin(9600);
  lastMeasureTime = millis();
}

void loop() {
  float angularVelocity = getAngularVelocity();  // rad/s
  if (angularVelocity >= 0) {
    Serial.print("Angular Velocity: ");
    Serial.print(angularVelocity);
    Serial.println(" rad/s");
  }
}

*/

#endif