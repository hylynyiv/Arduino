int speakerPin = 9;  // Use a PWM capable pin
const int numSamples = 50;  // Number of sample points
int sineData[numSamples];   // Array to hold sine wave data points

void setup() {
  pinMode(speakerPin, OUTPUT);

  // Create sine wave data
  for (int i = 0; i < numSamples; i++) {
    sineData[i] = 127.5 + 127.5 * sin(2 * PI * i / numSamples);
  }
}

void loop() {
  for (int i = 0; i < numSamples; i++) {
    analogWrite(speakerPin, sineData[i]);
    delayMicroseconds(100);  // Adjust the frequency by changing the delay
  }
}

