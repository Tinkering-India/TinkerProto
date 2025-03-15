#include <Servo.h>

const int potPin = A0;      // Potentiometer connected to Analog Pin A0
const int servoPin = 9;     // Servo motor connected to Digital Pin 9

Servo myServo;              // Create a Servo object to control the servo motor

void setup() {
  myServo.attach(servoPin);  // Attach the servo to pin 9
}

void loop() {
  int potValue = analogRead(potPin);  // Read the potentiometer value (0-1023)
  
  // Map the potentiometer value to a range suitable for the servo (0-180 degrees)
  int angle = map(potValue, 0, 1023, 0, 180);
  
  myServo.write(angle);  // Set the servo to the calculated angle
  
  delay(15);  // Wait for the servo to reach the desired position
}