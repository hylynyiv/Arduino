const int ledPin = 6;        // PWM-Pin für die LED
const int sensorPin = A0;    // Pin, an dem der Fotowiderstand angeschlossen ist

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);     // Liest den Wert des Lichtsensors
  int brightness = map(sensorValue, 0, 1023, 0, 255);  // Passt den Wert für die LED an
  
  analogWrite(ledPin, brightness);  // Setzt die Helligkeit der LED
  delay(10);  // Kurze Verzögerung für Stabilität
}