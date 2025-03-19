const int potPin = A0;   // Potentiometer connected to A0
const int ledPin = 9;    // LED connected to PWM Pin 9

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);  // For debugging
}

void loop() {
    int potValue = analogRead(potPin);  // Read potentiometer value (0-1023)
    int brightness = map(potValue, 0, 1023, 0, 255);  // Convert to PWM (0-255)
    
    analogWrite(ledPin, brightness);  // Adjust LED brightness

    Serial.print("Potentiometer Value: ");
    Serial.print(potValue);
    Serial.print(" -> LED Brightness: ");
    Serial.println(brightness);

    delay(10);  // Short delay for stability
}