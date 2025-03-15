/*
   Tinkering India - Inspiring Innovation Through Hands-on Learning
   Copyright (c) 2025 Tinkering India. All rights reserved.

   This code is provided for educational purposes under the Tinkering India initiative. 
   Redistribution, modification, and commercial use require explicit permission. 

   For more information, visit: https://tinkering.in
*/
// Define LED pins for traffic lights
const int redCar = 8;
const int yellowCar = 9;
const int greenCar = 10;

// Define pedestrian crossing LED & buzzer
const int pedestrianRed = 4;
const int pedestrianGreen = 5;
const int buzzer = 6;

// Define pedestrian button
const int buttonPin = 2;
bool pedestrianRequest = false;

void setup() {
  // Set LED pins as OUTPUT
  pinMode(redCar, OUTPUT);
  pinMode(yellowCar, OUTPUT);
  pinMode(greenCar, OUTPUT);
  pinMode(pedestrianRed, OUTPUT);
  pinMode(pedestrianGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Set button as INPUT with PULLUP (to avoid floating state)
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

  // Normal Traffic Light Sequence if no pedestrian request
  if (!pedestrianRequest) {
    digitalWrite(greenCar, HIGH);
    digitalWrite(pedestrianRed, HIGH);  // Pedestrians must wait
    delay(5000);

    digitalWrite(greenCar, LOW);
    digitalWrite(yellowCar, HIGH);
    delay(2000);

    digitalWrite(yellowCar, LOW);
    digitalWrite(redCar, HIGH);
    delay(5000);

    digitalWrite(redCar, LOW);
  } 
  
  // If pedestrian request is active
  else {
    Serial.println("Stopping Cars for Pedestrian Crossing...");
    
    // Stop vehicles: Turn red light ON for cars
    digitalWrite(greenCar, LOW);
    digitalWrite(yellowCar, LOW);
    digitalWrite(redCar, HIGH);

    // Warn pedestrians with a buzzer before allowing crossing
    Serial.println("Buzzer Alert: Pedestrians Wait...");
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);

    // Allow pedestrians to cross (Green LED for Walk)
    Serial.println("Pedestrians Can Cross Now!");
    digitalWrite(pedestrianRed, LOW);
    digitalWrite(pedestrianGreen, HIGH);
    delay(5000);  // Give time to cross

    // Flash pedestrian light before turning red again
    for (int i = 0; i < 5; i++) {
      digitalWrite(pedestrianGreen, LOW);
      delay(300);
      digitalWrite(pedestrianGreen, HIGH);
      delay(300);
    }

    // Reset pedestrian lights
    digitalWrite(pedestrianGreen, LOW);
    digitalWrite(pedestrianRed, HIGH);

    // Resume normal traffic light sequence
    Serial.println("Resuming Normal Traffic...");
    delay(2000); // Small buffer time
    digitalWrite(redCar, LOW);
    
    // Reset pedestrian request
    pedestrianRequest = false;
  }
}
