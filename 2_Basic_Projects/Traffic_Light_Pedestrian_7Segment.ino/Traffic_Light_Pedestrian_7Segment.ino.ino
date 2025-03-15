/*
   Tinkering India - Inspiring Innovation Through Hands-on Learning
   Copyright (c) 2025 Tinkering India. All rights reserved.

   This code is provided for educational purposes under the Tinkering India initiative. 
   Redistribution, modification, and commercial use require explicit permission. 

   For more information, visit: https://tinkering.in
*/
// Define LED pins for traffic lights
const int redCar = 10;
const int yellowCar = 11;
const int greenCar = 12;

// Define pedestrian light & buzzer
const int pedestrianRed = 2;
const int pedestrianGreen = 13;
const int buzzer = A1;

// Define pedestrian button
const int buttonPin = A0;
bool pedestrianRequest = false;

// Define 7-segment display pins (Common Cathode)
const int segA = 3;
const int segB = 4;
const int segC = 5;
const int segD = 6;
const int segE = 7;
const int segF = 8;
const int segG = 9;

// Number representations for 7-segment display
const byte numbers[10][7] = {
  {1,1,1,1,1,1,0}, // 0
  {0,1,1,0,0,0,0}, // 1
  {1,1,0,1,1,0,1}, // 2
  {1,1,1,1,0,0,1}, // 3
  {0,1,1,0,0,1,1}, // 4
  {1,0,1,1,0,1,1}, // 5
  {1,0,1,1,1,1,1}, // 6
  {1,1,1,0,0,0,0}, // 7
  {1,1,1,1,1,1,1}, // 8
  {1,1,1,1,0,1,1}  // 9
};

// Function to display a number on the 7-segment display
void displayNumber(int num) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segA + i, numbers[num][i]); 
  }
}

void setup() {
  // Set LED pins as OUTPUT
  pinMode(redCar, OUTPUT);
  pinMode(yellowCar, OUTPUT);
  pinMode(greenCar, OUTPUT);
  pinMode(pedestrianRed, OUTPUT);
  pinMode(pedestrianGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);

  // Set 7-segment display pins as OUTPUT
  for (int i = segA; i <= segG; i++) {
    pinMode(i, OUTPUT);
  }

  // Set pedestrian button as INPUT with PULLUP
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize Serial Monitor
  Serial.begin(9600);
}

void loop() {
  // Check if pedestrian button is pressed
  if (digitalRead(buttonPin) == LOW) {
    pedestrianRequest = true;  // Store pedestrian request
    Serial.println("Pedestrian Button Pressed! Requesting Cross...");
  }

  // Normal Traffic Light Sequence if No Pedestrian Request
  if (!pedestrianRequest) {
    digitalWrite(greenCar, HIGH);
    digitalWrite(pedestrianRed, HIGH);
    delay(5000);

    digitalWrite(greenCar, LOW);
    digitalWrite(yellowCar, HIGH);
    delay(2000);

    digitalWrite(yellowCar, LOW);
    digitalWrite(redCar, HIGH);
    delay(5000);

    digitalWrite(redCar, LOW);
  } 
  else {
    Serial.println("Stopping Cars for Pedestrian Crossing...");
    
    // Stop vehicles: Turn red light ON for cars
    digitalWrite(greenCar, LOW);
    digitalWrite(yellowCar, LOW);
    digitalWrite(redCar, HIGH);

    // Warn pedestrians with buzzer
    Serial.println("Buzzer Alert: Pedestrians Wait...");
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);

    // Allow Pedestrian Crossing & Start Countdown
    Serial.println("Pedestrians Can Cross Now!");
    digitalWrite(pedestrianRed, LOW);
    digitalWrite(pedestrianGreen, HIGH);

    // Countdown from 10s on 7-Segment Display
    for (int i = 10; i >= 0; i--) {
      displayNumber(i);
      delay(1000);
    }

    // Flash Pedestrian Green Light before stopping
    for (int i = 0; i < 5; i++) {
      digitalWrite(pedestrianGreen, LOW);
      delay(300);
      digitalWrite(pedestrianGreen, HIGH);
      delay(300);
    }

    // Reset pedestrian lights
    digitalWrite(pedestrianGreen, LOW);
    digitalWrite(pedestrianRed, HIGH);

    // Resume normal traffic
    Serial.println("Resuming Normal Traffic...");
    delay(2000);
    digitalWrite(redCar, LOW);
    
    // Reset pedestrian request
    pedestrianRequest = false;
  }
}
