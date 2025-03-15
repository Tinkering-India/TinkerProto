const int relayPin = 7;    // Relay control pin (connected to relay IN)
const int buttonPin = 2;   // Button pin (Optional, for manual control)

bool relayState = false;   // Relay state (ON or OFF)
bool buttonStatconst int relayPin = 7;    // Relay control pin (connected to relay IN)
const int buttonPin = 2;   // Button pin (Optional, for manual control)

bool relayState = false;   // Relay state (ON or OFF)
bool buttonState = false;  // Button state

void setup() {
    pinMode(relayPin, OUTPUT);   // Set relay pin as OUTPUT
    pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input (with pull-up resistor)
    Serial.begin(9600);           // Start Serial communication
}

void loop() {
    // Check if the button is pressed
    buttonState = digitalRead(buttonPin) == LOW;  // Button pressed means LOW (because of pull-up resistor)
    
    // Toggle relay state if button is pressed
    if (buttonState) {
        relayState = !relayState;  // Toggle relay state (ON/OFF)
        digitalWrite(relayPin, relayState ? HIGH : LOW);  // Turn relay ON/OFF
        Serial.print("Relay State: ");
        Serial.println(relayState ? "ON" : "OFF");
        delay(500);  // Debounce delay for the button
    }
    
    // Optionally, you can control the relay automatically based on time, sensor input, etc.
    // Example: Automatically turn on the appliance for 5 seconds every 10 seconds
    // if (millis() % 10000 < 5000) {
    //     digitalWrite(relayPin, HIGH);  // Turn ON
    // } else {
    //     digitalWrite(relayPin, LOW);   // Turn OFF
    // }

    delay(100);  // Short delay to ensure stable reading
}
e = false;  // Button state

void setup() {
    pinMode(relayPin, OUTPUT);   // Set relay pin as OUTPUT
    pinMode(buttonPin, INPUT_PULLUP);  // Set button pin as input (with pull-up resistor)
    Serial.begin(9600);           // Start Serial communication
}

void loop() {
    // Check if the button is pressed
    buttonState = digitalRead(buttonPin) == LOW;  // Button pressed means LOW (because of pull-up resistor)
    
    // Toggle relay state if button is pressed
    if (buttonState) {
        relayState = !relayState;  // Toggle relay state (ON/OFF)
        digitalWrite(relayPin, relayState ? HIGH : LOW);  // Turn relay ON/OFF
        Serial.print("Relay State: ");
        Serial.println(relayState ? "ON" : "OFF");
        delay(500);  // Debounce delay for the button
    }
    
    // Optionally, you can control the relay automatically based on time, sensor input, etc.
    // Example: Automatically turn on the appliance for 5 seconds every 10 seconds
    // if (millis() % 10000 < 5000) {
    //     digitalWrite(relayPin, HIGH);  // Turn ON
    // } else {
    //     digitalWrite(relayPin, LOW);   // Turn OFF
    // }

    delay(100);  // Short delay to ensure stable reading
}
