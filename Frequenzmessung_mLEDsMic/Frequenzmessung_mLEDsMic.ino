const int micPin = A0;  // Mikrofon an A0
const int speakerPin = 10; // Lautsprecher an Pin 10 (ändern, wenn bereits belegt)
const int ledPins[] = {5, 6, 7, 8, 9}; // LEDs an diesen Pins

void setup() {
  pinMode(speakerPin, OUTPUT);
  pinMode(micPin, INPUT);
  for (int i = 0; i < 5; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  Serial.begin(9600);
}

void loop() {
  unsigned long duration = pulseIn(micPin, HIGH, 1000000); // Misst die Dauer eines HIGH-Signals
  int frequency = 1000000 / (2 * duration); // Berechnet die Frequenz

  Serial.println(frequency); // Gibt die Frequenz aus

  // LEDs entsprechend der Frequenz aktivieren
  for (int i = 0; i < 5; i++) {
    if (frequency > (i * 1000) && frequency <= ((i + 1) * 1000)) {
      digitalWrite(ledPins[i], HIGH);
    } else {
      digitalWrite(ledPins[i], LOW);
    }
  }

  tone(speakerPin, frequency, 100); // Spielt einen Ton mit der erfassten Frequenz
  delay(200); // Warten, um den Ton zu hören
}

