const int ledPin = 6;  // Verwenden Sie einen PWM-fähigen Pin

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // LED langsam heller werden lassen
  for (int i = 0; i <= 255; i++) {
    analogWrite(ledPin, i);
    delay(10);  // Verzögerung für den Fadeneffekt anpassen
  }

  // Kurze Pause
  delay(500);

  // LED langsam dunkler werden lassen
  for (int i = 255; i >= 0; i--) {
    analogWrite(ledPin, i);
    delay(10);  // Verzögerung für den Fadeneffekt anpassen
  }

  // Kurze Pause
  delay(500);
}