const int IN[] = {2, 3, 4, 5};
const int Pin[] = {A0, A1, A2, A3};

// CHNAGE THRESHOLD VALUES BELOW
// Define moisture threshold values for each sensor.
// A low number is dryer than a high number. 
// The pump will turn on when the value it is reading drops below the value set here.
const int moistureThresholds[] = {800,  // Sensor 1 threshold
                                   750,  // Sensor 2 threshold
                                   700,  // Sensor 3 threshold
                                   850}; // Sensor 4 threshold

// Constants for relay states
const int ON = LOW;
const int OFF = HIGH;

void setup() {
  Serial.begin(9600);

  for (int i = 0; i < 4; i++) {
    pinMode(IN[i], OUTPUT);
    pinMode(Pin[i], INPUT);
    digitalWrite(IN[i], OFF);
  }

  delay(500);
}

void loop() {
  float values[] = {0, 0, 0, 0};

  for (int i = 0; i < 4; i++) {
    // Read and print moisture level for each sensor
    values[i] = analogRead(Pin[i]);
    Serial.print("MOISTURE LEVEL Sensor " + String(i + 1) + ": " + values[i]);
    Serial.println();

    // Control relay based on moisture level
    digitalWrite(IN[i], (values[i] > moistureThresholds[i]) ? ON : OFF);
  }

  // Print an empty line for better readability
  Serial.println();
  
  // CHNAGE TIMMING BELOW
  // Delay for 10 seconds before reading the sensors again.
  // This is in milliseconds. 1,000 Milliseconds = 1 second.
  delay(10000);
}
