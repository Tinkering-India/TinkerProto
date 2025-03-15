#include <Servo.h>

const int buttonPin = 2;   // Pin connected to the push button
const int servoPin = 9;    // Pin connected to the Servo

Servo doorLock;            // Create Servo object to control the door lock

bool buttonState = false;  // State of the button (pressed or not)

void setup() {
    pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input with internal pull-up resistor
    doorLock.attach(servoPin);         // Attach the Servo to the defined pin
    doorLock.write(0);                 // Start with the door locked (0 degrees)
}

void loop() {
    buttonState = digitalRead(buttonPin);  // Read the state of the button

    if (buttonState == LOW) {  // If the button is pressed (LOW due to pull-up resistor)
        doorLock.write(90);    // Unlock the door (90 degrees)
        delay(500);            // Wait for 0.5 seconds before locking again
        doorLock.write(0);     // Lock the door (0 degrees)
        delay(500);            // Wait for 0.5 seconds before checking again
    }
}