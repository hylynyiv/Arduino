#include <LedControl.h>

// Pins für DIN, CLK, CS, Anzahl der Module
LedControl lc = LedControl(11, 13, 10, 1);

void setup() {
  lc.shutdown(0, false);       // Wake up displays
  lc.setIntensity(0, 8);       // Set brightness level (0 is min, 15 is max)
  lc.clearDisplay(0);          // Clear display register
}

void loop() {
  // Alle LEDs der Reihe nach aufleuchten lassen
  for (int row = 0; row < 8; row++) {
    for (int col = 0; col < 8; col++) {
      lc.setLed(0, row, col, true); // LED an
      delay(100);
      lc.setLed(0, row, col, false); // LED aus
    }
  }

  // Quadrat anzeigen
  for (int i = 0; i < 8; i++) {
    lc.setLed(0, i, 0, true); // Linke Seite des Quadrats
    lc.setLed(0, i, 7, true); // Rechte Seite des Quadrats
    lc.setLed(0, 0, i, true); // Obere Seite des Quadrats
    lc.setLed(0, 7, i, true); // Untere Seite des Quadrats
  }
  delay(2000); // Warten, um das Quadrat zu zeigen

  lc.clearDisplay(0); // Display löschen
  delay(500);
}