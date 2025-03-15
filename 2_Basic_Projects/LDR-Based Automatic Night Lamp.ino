const int ldrPin = A0;  // LDR connected to Analog Pin A0
const int ledPin = 13;  // LED connected to Digital Pin 13

// Threshold value to turn ON the LED (lower value = more sensitive to light)
int threshold = 300;  

void setup() {
    pinMode(ledPin, OUTPUT);   // Set LED pin as OUTPUT
    Serial.begin(9600);        // Start serial communication
}

void loop() {
    int ldrValue = analogRead(ldrPin);  // Read LDR value (0-1023)
    
    // Print LDR value for debugging
    Serial.print("LDR Value: ");
    Serial.println(ldrValue);  

    // If LDR value is below threshold (dark environment), turn ON the LED
    if (ldrValue < threshold) {
        digitalWrite(ledPin, HIGH);  // Turn ON the LED
    } else {
        digitalWrite(ledPin, LOW);   // Turn OFF the LED
    }

    delay(100);  // Short delay for stable readings
}
