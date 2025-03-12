/*
   Tinkering India - Inspiring Innovation Through Hands-on Learning
   Copyright (c) 2025 Tinkering India. All rights reserved.

   This code is provided for educational purposes under the Tinkering India initiative. 
   Redistribution, modification, and commercial use require explicit permission. 

   For more information, visit: https://tinkering.in
*/

// Blinking LED with adjustable delay and pin selection
const int ledPin = 13;  // Change this to any digital pin
const int delayTime = 500; // Adjust blinking speed

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(delayTime);
  digitalWrite(ledPin, LOW);
  delay(delayTime);
}
