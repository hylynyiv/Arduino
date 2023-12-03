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
  for (int i = 0; i < numSamples; i++) {
    analogWrite(speakerPin, sineData[i]);
    delayMicroseconds(50); // Reduzierte Verzögerung für höhere Frequenz
  }
}