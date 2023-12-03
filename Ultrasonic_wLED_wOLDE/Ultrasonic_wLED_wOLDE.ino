#define TRIG_PIN 9
#define ECHO_PIN 10
#define LED_PIN 13
#define SOUND_SPEED 0.034
#define THRESHOLD_DISTANCE 5  // distance in cm

#include <Arduino.h>
#include <U8g2lib.h>

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SH1106_128X64_NONAME_1_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);


void setup() {
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  u8g2.begin(); 
}

void loop() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance = duration * SOUND_SPEED / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < THRESHOLD_DISTANCE) {
    digitalWrite(LED_PIN, HIGH);
    u8g2.firstPage();
    do {
      u8g2.setFont(u8g2_font_ncenB10_tr);
      u8g2.drawStr(0,24,"TOO CLOSE!");
    } while ( u8g2.nextPage() );
  } else {
    digitalWrite(LED_PIN, LOW);
     u8g2.firstPage();
    do {
      u8g2.setFont(u8g2_font_ncenB10_tr);
      u8g2.drawStr(0,24,"You are great!");
    } while ( u8g2.nextPage() );
  }

  delay(100);
}

