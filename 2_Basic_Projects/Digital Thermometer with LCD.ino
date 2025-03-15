#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Initialize LCD (Address 0x27, 16x2 LCD)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// LM35 pin
const int lm35Pin = A0;  // Temperature sensor connected to analog pin A0

void setup() {
  lcd.begin(16,2);             // Initialize LCD
  lcd.backlight();         // Turn on the backlight
  Serial.begin(9600);      // Start serial communication for debugging
}

void loop() {
  // Read the analog value from LM35 (0-1023)
  int analogValue = analogRead(lm35Pin);  
  
  // Convert the analog value to voltage (5V is the reference)
  float voltage = analogValue * (5.0 / 1023.0);
  
  // Convert the voltage to temperature in Celsius (1mV = 1°C)
  float temperature = voltage * 100;  
  
  // Display the temperature on the LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature: ");
  lcd.print(temperature);  // Display temperature in Celsius
  lcd.print(" C");
  
  // Send temperature data to Serial Monitor for debugging
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" C");

  delay(1000);  // Wait 1 second before updating the display
}