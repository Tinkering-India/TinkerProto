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
[/code]

// Define pins for the Red, Yellow, and Green LEDs
const int red = 8;
const int yellow = 9;
const int green = 10;

// Define timing variables (in milliseconds)
const int redTime = 5000;     // Red light duration (5 seconds)
const int yellowTime = 2000;  // Yellow light duration (2 seconds)
const int greenTime = 5000;   // Green light duration (5 seconds)

void setup() {
  // Set LED pins as OUTPUT
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop() {
  // Turn ON the Green light
  digitalWrite(green, HIGH);
  delay(greenTime);  // Wait for green time duration
  digitalWrite(green, LOW); // Turn OFF Green light

  // Turn ON the Yellow light (Caution)
  digitalWrite(yellow, HIGH);
  delay(yellowTime); // Wait for yellow time duration
  digitalWrite(yellow, LOW); // Turn OFF Yellow light

  // Turn ON the Red light (Stop)
  digitalWrite(red, HIGH);
  delay(redTime); // Wait for red time duration
  digitalWrite(red, LOW); // Turn OFF Red light
}
