#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (Address: 0x27, 16x2 LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Pin Definitions
const int lm35Pin = A0;  // LM35 connected to Analog Pin A0
const int relayPin = 7;  // Relay control connected to Digital Pin 7

// Threshold Temperature (in Celsius)
const float thresholdTemp = 30.0;  // Fan will turn on when the temperature exceeds this

void setup() {
  // Set relay pin as OUTPUT
  pinMode(relayPin, OUTPUT);
  
  // Initialize Serial and LCD
  Serial.begin(9600);
  lcd.begin(16,2);
  lcd.backlight();
  
  // Display initial message on LCD
  lcd.setCursor(0, 0);
  lcd.print("Temp-Based Fan");
  lcd.setCursor(0, 1);
  lcd.print("Control System");
  delay(2000);  // Show the initial message for 2 seconds
}

void loop() {
  // Read temperature from LM35
  int lm35Value = analogRead(lm35Pin);
  float voltage = lm35Value * (5.0 / 1023.0);  // Convert ADC value to voltage (5V)
  float temperature = voltage * 100;  // Convert voltage to temperature in Celsius (LM35 = 10mV per degree)

  // Display Temperature on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(temperature);
  lcd.print(" C");

  // Turn on the fan (relay) if the temperature exceeds the threshold
  if (temperature > thresholdTemp) {
    digitalWrite(relayPin, HIGH);  // Turn the relay ON (fan ON)
    lcd.setCursor(0, 1);
    lcd.print("Fan ON");
    Serial.println("Fan ON");  // Output to Serial Monitor
  } else {
    digitalWrite(relayPin, LOW);  // Turn the relay OFF (fan OFF)
    lcd.setCursor(0, 1);
    lcd.print("Fan OFF");
    Serial.println("Fan OFF");  // Output to Serial Monitor
  }
  
  delay(1000);  // Wait for 1 second before updating the reading
}