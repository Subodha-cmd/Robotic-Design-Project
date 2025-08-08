#include <Servo.h>

Servo servo;  // Servo on port 1 of the motor shield

void setup() {
  servo.attach(52);   // Attach servo to port 1
  servo.write(90);   // Move servo to center position (90 degrees)
}

void loop() {
  // Sweep servo from 0 to 180 degrees
  for (int pos = 0; pos <= 180; pos++) {
    servo.write(pos);
    delay(15);
  }

  // Sweep servo back from 180 to 0 degrees
  for (int pos = 180; pos >= 0; pos--) {
    servo.write(pos);
    delay(15);
  }
}
