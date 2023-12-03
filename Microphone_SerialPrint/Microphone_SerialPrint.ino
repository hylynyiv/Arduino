const int micPin = A0;  // Der analoge Ausgang des Mikrofons ist an A0 angeschlossen

void setup() {
  Serial.begin(9600);
  pinMode(micPin, INPUT);
}

void loop() {
  int micValue = analogRead(micPin);  // Liest den analogen Wert des Mikrofons
  Serial.println(micValue);            // Sendet den Wert über die serielle Schnittstelle
  delay(10);                           // Kurze Verzögerung zwischen den Messungen
}