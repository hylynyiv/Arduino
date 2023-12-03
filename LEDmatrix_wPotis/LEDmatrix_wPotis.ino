#include <LedControl.h>

LedControl lc = LedControl(11, 13, 10, 1); // Pins für DIN, CLK und CS

const int potXPin = A5; // Potentiometer für die X-Achse
const int potYPin = A4; // Potentiometer für die Y-Achse

void setup() {
  lc.shutdown(0, false);       // Display einschalten
  lc.setIntensity(0, 8);       // Helligkeit einstellen
  lc.clearDisplay(0);          // Display löschen
}

void loop() {
  int x = map(analogRead(potXPin), 0, 1023, 0, 7); // X-Position lesen und umwandeln
  int y = map(analogRead(potYPin), 0, 1023, 0, 7); // Y-Position lesen und umwandeln

  lc.clearDisplay(0);          // Display löschen für die neue Position
  lc.setLed(0, y, x, true);    // LED an der Position (x, y) einschalten

  delay(100);                  // Kurze Verzögerung für bessere Steuerung
}