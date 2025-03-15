const int irSensorPin = 2;  // IR Sensor connected to Digital Pin 2
const int ledPin = 8;       // LED connected to Digital Pin 8

void setup() {
    pinMode(irSensorPin, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
}

void loop() {
    int motionDetected = digitalRead(irSensorPin);  // Read IR Sensor value

    if (motionDetected == HIGH) {  // If motion is detected
        digitalWrite(ledPin, HIGH);  // Turn LED ON
        Serial.println("Motion Detected! LED ON");
        delay(5000);  // Keep LED ON for 5 seconds
    } else {
        digitalWrite(ledPin, LOW);  // Turn LED OFF
        Serial.println("No Motion. LED OFF");
    }

    delay(100);  // Small delay before next sensor check
}
