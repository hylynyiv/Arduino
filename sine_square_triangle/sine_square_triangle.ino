const int speakerPin = 9;
const int numSamples = 100;
int sineData[numSamples];

void beep(int pin, int frequency, int duration) {
  unsigned long start = millis();
  while (millis() - start < duration) {
    analogWrite(pin, 255);
    delayMicroseconds(frequency);
    analogWrite(pin, 0);
    delayMicroseconds(frequency);
  }
}

void setup() {
  pinMode(speakerPin, OUTPUT);
  for (int i = 0; i < numSamples; i++) {
    sineData[i] = 127.5 + 127.5 * sin(2 * PI * i / numSamples);
  }
}


void loop() {
    // Drei kurze Pieptöne
  for (int i = 0; i < 3; i++) {
    beep(speakerPin, 500, 100);  // 500 Mikrosekunden Ton, 100 Millisekunden Dauer
    delay(100);  // Pause zwischen den Pieptönen
  }

  // Sinuston für 3 Sekunden
  unsigned long startMillis = millis();
  while(millis() - startMillis < 3000) {
    for (int i = 0; i < numSamples; i++) {
      analogWrite(speakerPin, sineData[i]);
      delayMicroseconds(50);
    }
  }

  // Rechteckton für 3 Sekunden
  startMillis = millis();
  while(millis() - startMillis < 3000) {
    analogWrite(speakerPin, 255);
    delayMicroseconds(1000);
    analogWrite(speakerPin, 0);
    delayMicroseconds(1000);
  }

  // Dreieckston für 3 Sekunden
  startMillis = millis();
  while(millis() - startMillis < 3000) {
    for (int i = 0; i < 255; i++) {
      analogWrite(speakerPin, i);
      delayMicroseconds(100);
    }
    for (int i = 255; i > 0; i--) {
      analogWrite(speakerPin, i);
      delayMicroseconds(100);
    }
  }
}