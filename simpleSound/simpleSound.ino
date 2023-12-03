int speakerPin = 8;  // Speaker connected to digital pin 8
int toneFrequency = 260; // Frequency of the tone in Hz (440Hz is the A note)

void setup() {
  pinMode(speakerPin, OUTPUT); // Set speaker pin as an output
}

void loop() {
  long duration = 1000000 / toneFrequency / 2; // Calculate the duration of each toggle
  // This is half the period of the frequency

  while(true) {
    digitalWrite(speakerPin, HIGH); // Set the speaker pin to high
    delayMicroseconds(duration);    // Wait for 'duration' microseconds

    digitalWrite(speakerPin, LOW);  // Set the speaker pin to low
    delayMicroseconds(duration);    // Wait for 'duration' microseconds
  }
  // The loop runs indefinitely to continuously produce the tone
}  



