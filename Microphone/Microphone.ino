const int micPin = 2;   // Der Pin, an den der digitale Ausgang des Mikrofons angeschlossen ist
const int ledPin = 13;  // Die eingebaute LED an Pin 13

void setup() {
  pinMode(micPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int micValue = digitalRead(micPin);  // Liest den digitalen Zustand des Mikrofons
  if (micValue == HIGH) {
    digitalWrite(ledPin, HIGH);        // Schaltet die LED ein, wenn Lärm erkannt wird
    Serial.println("Lärm erkannt!");
  } else {
    digitalWrite(ledPin, LOW);         // Schaltet die LED aus, wenn kein Lärm
  }
  delay(100);                           // Kurze Verzögerung zwischen den Messungen
}