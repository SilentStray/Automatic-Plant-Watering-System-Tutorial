// Define digital output pins for controlling relays
const int IN1 = 2;
const int IN2 = 3;
const int IN3 = 4;
const int IN4 = 5;

// Define analog input pins for connecting moisture sensors
const int Pin1 = A0;
const int Pin2 = A1;
const int Pin3 = A2;
const int Pin4 = A3;

// Define moisture threshold values for each sensor
// Threshold for Sensor 1
const int moistureThresholds[] = {800,  // Sensor 1 threshold
                                   750,  // Sensor 2 threshold
                                   700,  // Sensor 3 threshold
                                   850}; // Sensor 4 threshold

// Variables to store moisture values from sensors
float value1 = 0;
float value2 = 0;
float value3 = 0;
float value4 = 0;

// Constants for relay states
const int ON = LOW;
const int OFF = HIGH;

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Configure digital pins as OUTPUT for controlling relays
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Configure analog pins as INPUT for reading moisture values
  pinMode(Pin1, INPUT);
  pinMode(Pin2, INPUT);
  pinMode(Pin3, INPUT);
  pinMode(Pin4, INPUT);

  // Set initial state of digital pins to HIGH
  digitalWrite(IN1, OFF);
  digitalWrite(IN2, OFF);
  digitalWrite(IN3, OFF);
  digitalWrite(IN4, OFF);

  // Delay to ensure stability after initialization
  delay(500);
}

void loop() {
  // Read and print moisture level for Sensor 1
  Serial.print("MOISTURE LEVEL Sensor 1: ");
  value1 = analogRead(Pin1);
  Serial.println(value1);
  // Control relay based on moisture level
  if (value1 > moistureThresholds[0]) {
    digitalWrite(IN1, ON);
  } else {
    digitalWrite(IN1, OFF);
  }

  // Read and print moisture level for Sensor 2
  Serial.print("MOISTURE LEVEL Sensor 2: ");
  value2 = analogRead(Pin2);
  Serial.println(value2);
  // Control relay based on moisture level
  if (value2 > moistureThresholds[1]) {
    digitalWrite(IN2, ON);
  } else {
    digitalWrite(IN2, OFF);
  }

  // Read and print moisture level for Sensor 3
  Serial.print("MOISTURE LEVEL Sensor 3: ");
  value3 = analogRead(Pin3);
  Serial.println(value3);
  // Control relay based on moisture level
  if (value3 > moistureThresholds[2]) {
    digitalWrite(IN3, ON);
  } else {
    digitalWrite(IN3, OFF);
  }

  // Read and print moisture level for Sensor 4
  Serial.print("MOISTURE LEVEL Sensor 4: ");
  value4 = analogRead(Pin4);
  Serial.println(value4);
  // Control relay based on moisture level
  if (value4 > moistureThresholds[3]) {
    digitalWrite(IN4, ON);
  } else {
    digitalWrite(IN4, OFF);
  }

  // Print an empty line for better readability
  Serial.println();

  // Delay for 10 seconds before the next iteration
  delay(10000);
}
