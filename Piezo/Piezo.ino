const int piezoPin = A1;  // Piezo connected to analog pin A0

void setup() {
  Serial.begin(9600);     // Start the Serial communication
}

void loop() {
  int sensorValue = analogRead(piezoPin);  // Read the value from the piezo
  Serial.println(sensorValue);             // Print the value to the Serial Monitor

  delay(100);   // Short delay for stability
}