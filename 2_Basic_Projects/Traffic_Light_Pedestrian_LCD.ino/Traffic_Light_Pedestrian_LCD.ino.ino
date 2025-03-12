/*
   Tinkering India - Inspiring Innovation Through Hands-on Learning
   Copyright (c) 2025 Tinkering India. All rights reserved.

   This code is provided for educational purposes under the Tinkering India initiative. 
   Redistribution, modification, and commercial use require explicit permission. 

   For more information, visit: https://tinkering.in
*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (I2C Address 0x27 or 0x3F, 16x2 Display)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define LED pins for Traffic Lights
const int redCar = 8;
const int yellowCar = 9;
const int greenCar = 10;

// Define Pedestrian Light & Buzzer
const int pedestrianRed = 4;
const int pedestrianGreen = 5;
const int buzzer = 6;

// Define Pedestrian Button
const int buttonPin = 2;
bool pedestrianRequest = false;

void setup() {
  // Set LED Pins as OUTPUT
  pinMode(redCar, OUTPUT);
  pinMode(yellowCar, OUTPUT);
  pinMode(greenCar, OUTPUT);
  pinMode(pedestrianRed, OUTPUT);
  pinMode(pedestrianGreen, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  // Set Button as INPUT with PULLUP
  pinMode(buttonPin, INPUT_PULLUP);

  // Initialize Serial Monitor
  Serial.begin(9600);

  // Initialize LCD
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Traffic Light");
  lcd.setCursor(0, 1);
  lcd.print("System Ready!");
  delay(2000);
  lcd.clear();
}

void loop() {
  // Check if pedestrian button is pressed
  if (digitalRead(buttonPin) == LOW) {
    pedestrianRequest = true;  // Store pedestrian request
    Serial.println("Pedestrian Button Pressed! Requesting Cross...");
  }

  // Normal Traffic Light Sequence if No Pedestrian Request
  if (!pedestrianRequest) {
    lcd.setCursor(0, 0);
    lcd.print("Cars: GREEN      ");
    lcd.setCursor(0, 1);
    lcd.print("Pedestrians: WAIT");

    digitalWrite(greenCar, HIGH);
    digitalWrite(pedestrianRed, HIGH);
    delay(5000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cars: YELLOW     ");
    lcd.setCursor(0, 1);
    lcd.print("Prepare to STOP");

    digitalWrite(greenCar, LOW);
    digitalWrite(yellowCar, HIGH);
    delay(2000);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cars: RED        ");
    lcd.setCursor(0, 1);
    lcd.print("Pedestrians: WAIT");

    digitalWrite(yellowCar, LOW);
    digitalWrite(redCar, HIGH);
    delay(5000);

    lcd.clear();
    digitalWrite(redCar, LOW);
  } 
  else {
    Serial.println("Stopping Cars for Pedestrian Crossing...");
    
    // Stop Vehicles: Turn Red Light ON for Cars
    digitalWrite(greenCar, LOW);
    digitalWrite(yellowCar, LOW);
    digitalWrite(redCar, HIGH);

    // Warn Pedestrians with Buzzer
    Serial.println("Buzzer Alert: Pedestrians Wait...");
    lcd.setCursor(0, 0);
    lcd.print("Buzzer: WARNING  ");
    lcd.setCursor(0, 1);
    lcd.print("Wait to Cross!");
    digitalWrite(buzzer, HIGH);
    delay(2000);
    digitalWrite(buzzer, LOW);

    // Allow Pedestrian Crossing & Start Countdown
    Serial.println("Pedestrians Can Cross Now!");
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Cars: STOP       ");
    lcd.setCursor(0, 1);
    lcd.print("Cross: ");

    digitalWrite(pedestrianRed, LOW);
    digitalWrite(pedestrianGreen, HIGH);

    // Countdown from 10s on LCD
    for (int i = 10; i >= 0; i--) {
      lcd.setCursor(8, 1);
      lcd.print("     ");  // Clear previous number
      lcd.setCursor(8, 1);
      lcd.print(i);
      delay(1000);
    }

    // Flash Pedestrian Green Light before stopping
    for (int i = 0; i < 5; i++) {
      digitalWrite(pedestrianGreen, LOW);
      delay(300);
      digitalWrite(pedestrianGreen, HIGH);
      delay(300);
    }

    // Reset Pedestrian Lights
    digitalWrite(pedestrianGreen, LOW);
    digitalWrite(pedestrianRed, HIGH);

    // Resume Normal Traffic Lights
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Resuming Traffic");
    Serial.println("Resuming Normal Traffic...");
    delay(2000); // Small buffer time
    digitalWrite(redCar, LOW);
    
    // Reset Pedestrian Request
    pedestrianRequest = false;
  }
}
