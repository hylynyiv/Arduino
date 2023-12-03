void setup() {
  pinMode(LED_BUILTIN, OUTPUT); // Initialize the LED_BUILTIN pin as an output
}

void loop() {
  // Send S: three short blinks
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
    delay(300);                      // wait for 300 milliseconds
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off
    delay(300);                      // wait for 300 milliseconds
  }

  // Wait between S and O
  delay(300);

  // Send O: three long blinks
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
    delay(900);                      // wait for 900 milliseconds
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off
    delay(300);                      // wait for 300 milliseconds
  }

  // Wait between O and S
  delay(300);

  // Send S again: three short blinks
  for (int i = 0; i < 3; i++) {
    digitalWrite(LED_BUILTIN, HIGH); // turn the LED on
    delay(300);                      // wait for 300 milliseconds
    digitalWrite(LED_BUILTIN, LOW);  // turn the LED off
    delay(300);                      // wait for 300 milliseconds
  }

  // Wait before repeating the SOS signal
  delay(3000);                       // wait for 3 seconds
}
