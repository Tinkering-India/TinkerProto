const int ledPins[] = {2, 3, 4, 5};  // Pins connected to LEDs
const int numLeds = 4;               // Number of LEDs
const int buttonPin = 6;             // Push button connected to pin 6
int buttonState = 0;                 // Variable to store button state

void setup() {
  // Set LED pins as OUTPUT
  for (int i = 0; i < numLeds; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  
  pinMode(buttonPin, INPUT);  // Set button pin as input
}

void loop() {
  // Read the state of the push button
  buttonState = digitalRead(buttonPin);
  
  if (buttonState == HIGH) {  // If the button is pressed, change LED pattern
    // Pattern 1: All LEDs blink at the same time
    allLedsBlinking();

    // Pattern 2: LEDs blink one by one
    oneByOneBlinking();

    // Pattern 3: LEDs blink in a sequence
    sequenceBlinking();
  } else {
    // Default: LEDs OFF if no button is pressed
    for (int i = 0; i < numLeds; i++) {
      digitalWrite(ledPins[i], LOW);
    }
  }
}

// Function for Pattern 1: All LEDs blinking at the same time
void allLedsBlinking() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);
  }
  delay(500);  // Wait for 0.5 seconds
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], LOW);
  }
  delay(500);  // Wait for 0.5 seconds
}

// Function for Pattern 2: LEDs blinking one by one
void oneByOneBlinking() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);  // Turn LED on
    delay(500);  // Wait for 0.5 seconds
    digitalWrite(ledPins[i], LOW);   // Turn LED off
  }
}

// Function for Pattern 3: LEDs blinking in a sequence
void sequenceBlinking() {
  for (int i = 0; i < numLeds; i++) {
    digitalWrite(ledPins[i], HIGH);  // Turn on LED
    delay(200);  // Wait for 0.2 seconds
    digitalWrite(ledPins[i], LOW);   // Turn off LED
  }
}
