// Pin-Konfiguration
const int buzzerPin = 10; // Piezo-Buzzer an Pin 8

// Notenfrequenzen (in Hertz)
#define NOTE_B4  494
#define NOTE_A4  440
#define NOTE_G4  392
#define NOTE_F4  349
#define NOTE_E4  330

// Noten und Pausen für "Last Christmas"
int melody[] = {
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, 
  NOTE_B4, NOTE_A4, NOTE_G4, NOTE_A4, 
  NOTE_B4, NOTE_A4, NOTE_B4, NOTE_E4, 
  NOTE_F4, NOTE_G4, NOTE_E4, NOTE_F4
};

// Dauern der Noten: 4 = Viertelnote, 8 = Achtelnote usw.
int noteDurations[] = {
  4, 8, 8, 4, 
  4, 8, 8, 4, 
  4, 8, 8, 4, 
  4, 4, 4, 4
};

void setup() {
  // nichts zu initialisieren
}

void loop() {
  for (int thisNote = 0; thisNote < 16; thisNote++) {
    // Notenlänge berechnen
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(buzzerPin, melody[thisNote], noteDuration);

    // Eine kleine Pause zwischen den Noten
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);

    // Stoppen der Tonwiedergabe
    noTone(buzzerPin);
  }

  // Pause am Ende des Lieds
  delay(2000);
}