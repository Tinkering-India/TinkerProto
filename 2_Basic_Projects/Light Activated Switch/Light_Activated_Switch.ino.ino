const int ldrPin = A0;  // LDR connected to Analog Pin A0
const int ledPin = 9;   // LED connected to Digital Pin 9

void setup() {
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int ldrValue = analogRead(ldrPin);  // Read LDR value (0-1023)

    Serial.print("LDR Value: ");
    Serial.println(ldrValue);  // Print LDR value for debugging

    if (ldrValue < 500) {  // Adjust threshold based on environment
        digitalWrite(ledPin, HIGH);  // Turn LED ON in darkness
        Serial.println("Dark! LED ON");
    } else {
        digitalWrite(ledPin, LOW);  // Turn LED OFF in light
        Serial.println("Bright! LED OFF");
    }

    delay(500);  // Short delay for stability
}
