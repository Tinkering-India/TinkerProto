const int motorPin = 9;     // Motor control pin (connected to transistor base)
const int potPin = A0;      // Potentiometer connected to Analog Pin A0

void setup() {
  pinMode(motorPin, OUTPUT);  // Set motor pin as output
  Serial.begin(9600);         // Start serial communication for debugging
}

void loop() {
  int potValue = analogRead(potPin);  // Read potentiometer value (0-1023)

  // Map the potentiometer value to a PWM range (0-255)
  int motorSpeed = map(potValue, 0, 1023, 0, 255);
  
  // Write PWM value to motor control pin
  analogWrite(motorPin, motorSpeed);

  // Print the potentiometer and motor speed to the Serial Monitor
  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(" -> Motor Speed: ");
  Serial.println(motorSpeed);

  delay(100);  // Small delay for stability
}