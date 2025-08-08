// Include the Servo Library
#include <Servo.h>

// Rotary Encoder Inputs
#define CLK 21
#define DT 20

Servo servo;
int counter = 0;
int currentStateCLK;
int lastStateCLK;
String currentDir = "";

void setup() {
  // Set encoder pins as inputs
  pinMode(CLK, INPUT);
  pinMode(DT, INPUT);

  // Setup Serial Monitor
  Serial.begin(9600);

  // Attach servo on pin 9 to the servo object
  servo.attach(10);
  servo.write(counter);

  // Read the initial state of CLK
  lastStateCLK = digitalRead(CLK);

  // Call updateEncoder() when a change is seen on CLK pin
  attachInterrupt(digitalPinToInterrupt(CLK), updateEncoder, CHANGE);
}

void loop() {
  //Do some useful stuff here
}

void updateEncoder() {
  // Read the current state of CLK
  currentStateCLK = digitalRead(CLK);

  // If last and current state of CLK are different, then pulse occurred
  // React to only 1 state change to avoid double count
  if (currentStateCLK != lastStateCLK && currentStateCLK == 1) {

    // If the DT state is different than the CLK state then
    // the encoder is rotating CCW so decrement
    if (digitalRead(DT) != currentStateCLK) {
      counter--;
      if (counter < 0)
        counter = 0;
    } else {
      // Encoder is rotating CW so increment
      counter++;
      if (counter > 179)
        counter = 179;
    }
    // Move the servo
    servo.write(counter);
    Serial.print("Position: ");
    Serial.println(counter);
  }

  // Remember last CLK state
  lastStateCLK = currentStateCLK;
}