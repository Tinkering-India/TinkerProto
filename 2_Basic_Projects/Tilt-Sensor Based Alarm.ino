// Define the pins for the 7-segment display
const int segmentPins[7] = {2, 3, 4, 5, 6, 7, 8}; // Pins for A, B, C, D, E, F, G

// Pin for the decimal point (optional)
const int dpPin = 9;

// Segment values for digits 0-9
const byte numbers[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  // 0
  {0, 1, 1, 0, 0, 0, 0},  // 1
  {1, 1, 0, 1, 1, 0, 1},  // 2
  {1, 1, 1, 1, 0, 0, 1},  // 3
  {0, 1, 1, 0, 0, 1, 1},  // 4
  {1, 0, 1, 1, 0, 1, 1},  // 5
  {1, 0, 1, 1, 1, 1, 1},  // 6
  {1, 1, 1, 0, 0, 0, 0},  // 7
  {1, 1, 1, 1, 1, 1, 1},  // 8
  {1, 1, 1, 1, 0, 1, 1}   // 9
};

void setup() {
  // Set all segment pins as output
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

  // Set DP pin as output (optional)
  pinMode(dpPin, OUTPUT);

  // Initialize all segments to LOW (off)
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], LOW);
  }
  digitalWrite(dpPin, LOW);  // Turn off decimal point initially
}

void loop() {
  // Example: Display 5 on the 7-segment display
  displayNumber(5);
  delay(2000);  // Show the number for 2 seconds

  // Display 8 on the 7-segment display
  displayNumber(8);
  delay(2000);  // Show the number for 2 seconds
}

void displayNumber(int num) {
  // Check if the number is within 0-9
  if (num >= 0 && num <= 9) {
    // Set each segment according to the number to be displayed
    for (int i = 0; i < 7; i++) {
      digitalWrite(segmentPins[i], numbers[num][i] ? HIGH : LOW);
    }
    digitalWrite(dpPin, LOW);  // Turn off decimal point
  }
}
