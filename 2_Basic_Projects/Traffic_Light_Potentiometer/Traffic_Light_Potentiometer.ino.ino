/*
   Tinkering India - Inspiring Innovation Through Hands-on Learning
   Copyright (c) 2025 Tinkering India. All rights reserved.

   This code is provided for educational purposes under the Tinkering India initiative. 
   Redistribution, modification, and commercial use require explicit permission. 

   For more information, visit: https://tinkering.in
*/
// Define LED pins
const int red = 8;
const int yellow = 9;
const int green = 10;

// Define Potentiometer pin
const int potPin = A0; // Potentiometer connected to Analog Pin A0

// Timing variables (default values)
int redTime, yellowTime, greenTime;

void setup() {
  // Set LED pins as OUTPUT
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
  
  // Initialize Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Read potentiometer value (0 - 1023) and map to delay range (2 - 10 seconds)
  int potValue = analogRead(potPin);
  int mappedTime = map(potValue, 0, 1023, 2000, 10000); // Maps to range 2s - 10s

  // Assign mapped time to each light (red, yellow, green)
  redTime = mappedTime;
  yellowTime = mappedTime / 3;  // Yellow light duration is 1/3rd of red & green
  greenTime = mappedTime;

  // Print the times for debugging
  Serial.print("Red Time: ");
  Serial.print(redTime);
  Serial.print(" ms, Yellow Time: ");
  Serial.print(yellowTime);
  Serial.print(" ms, Green Time: ");
  Serial.print(greenTime);
  Serial.println(" ms");

  // Green Light ON
  digitalWrite(green, HIGH);
  delay(greenTime);
  digitalWrite(green, LOW);

  // Yellow Light ON (Caution)
  digitalWrite(yellow, HIGH);
  delay(yellowTime);
  digitalWrite(yellow, LOW);

  // Red Light ON (Stop)
  digitalWrite(red, HIGH);
  delay(redTime);
  digitalWrite(red, LOW);
}
