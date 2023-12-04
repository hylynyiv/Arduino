const int irSensorPin = A0; // IR-Sensor an Pin A0

void setup() {
  Serial.begin(9600);       // Starten der seriellen Kommunikation
  pinMode(irSensorPin, INPUT); // Setzen des Sensorpins als Eingang
}

void loop() {
  int sensorValue = analogRead(irSensorPin); // Lesen des Werts vom Sensor
  Serial.println(sensorValue); // Ausgabe des Werts im Serial Monitor
  delay(100); // Kurze Verzögerung zwischen den Messungen
}
