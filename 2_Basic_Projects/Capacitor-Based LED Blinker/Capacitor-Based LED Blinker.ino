#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// I2C LCD address (0x27 is the most common address, but it could be different for some LCDs)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Define pins for Ultrasonic Sensor
const int trigPin = 9;
const int echoPin = 10;

void setup() {
  // Initialize LCD
  lcd.begin(16, 2);
  lcd.backlight();
  
  // Set the trigger pin as OUTPUT and echo pin as INPUT
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  // Display a welcome message
  lcd.setCursor(0, 0);
  lcd.print("Ultrasonic Distance");
  delay(2000);
}

void loop() {
  // Send a pulse to trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the time taken for the pulse to return (Echo Pin)
  long duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in centimeters
  long distance = duration * 0.0344 / 2;  // Speed of sound is 0.0344 cm/us
  
  // Display the distance on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance:10");
  lcd.print(distance);
  lcd.print("10 cm");
  
  delay(500);  // Update the display every 500ms
}
