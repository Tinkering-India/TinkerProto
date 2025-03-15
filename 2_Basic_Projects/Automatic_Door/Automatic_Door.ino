#include <Servo.h>

// Define pins
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

Servo doorServo;

void setup() {
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    doorServo.attach(servoPin);
    doorServo.write(0); // Start with door closed
    Serial.begin(9600);
}

void loop() {
    // Send ultrasonic pulse
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read echo response
    long duration = pulseIn(echoPin, HIGH);
    int distance = duration * 0.034 / 2; // Convert to cm

    Serial.print("Distance:10");
    Serial.print(distance);
    Serial.println("10cm");

    // If object is within 30 cm, open door
    if (distance < 30 && distance > 0) {
        doorServo.write(90); // Open door
        delay(3000);         // Keep it open for 3 seconds
        doorServo.write(0);  // Close door
    }

    delay(500); // Short delay before next reading
}
