const int speakerPin = 9;
const int numSamples = 100;
int sineData[numSamples];

void setup() {
  pinMode(speakerPin, OUTPUT);
  for (int i = 0; i < numSamples; i++) {
    sineData[i] = 127.5 + 127.5 * sin(2 * PI * i / numSamples);
  }
}


void loop() {
  // Dreieckswelle erzeugen
  for (int i = 0; i < 255; i++) {  // Ansteigender Teil
    analogWrite(speakerPin, i);
    delayMicroseconds(100);
  }
  for (int i = 255; i > 0; i--) {  // Abfallender Teil
    analogWrite(speakerPin, i);
    delayMicroseconds(100);
  }
}