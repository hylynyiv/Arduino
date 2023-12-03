const int speakerPin = 9;    // PWM-Pin für den Lautsprecher
const int sensorPin = A0;    // Pin, an dem der Fotowiderstand angeschlossen ist

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(sensorPin, INPUT);
}

void loop() {
  int sensorValue = analogRead(sensorPin);     // Liest den Wert des Lichtsensors
  int toneFrequency = map(sensorValue, 0, 1023, 100, 2000);  // Passt den Wert für die Tonfrequenz an
  
  tone(speakerPin, toneFrequency, 100);  // Spielt einen Ton mit der angepassten Frequenz
  delay(150);  // Kurze Verzögerung zwischen den Tönen
}