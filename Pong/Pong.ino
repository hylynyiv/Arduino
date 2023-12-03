#include <LedControl.h>

LedControl lc = LedControl(12, 11, 10, 1);

const int pot1Pin = A4;
const int pot2Pin = A5;
int ballX = 4, ballY = 4; 
int ballDirX = 1, ballDirY = 1;
int player1Y = 4, player2Y = 4;
int playerHeight = 3;

void setup() {
  lc.shutdown(0, false);
  lc.setIntensity(0, 8);
  lc.clearDisplay(0);
}

void drawPaddle(int paddleY, bool isPlayer1) {
  for (int i = 0; i < 8; i++) {
    if (i >= paddleY && i < paddleY + playerHeight) {
      lc.setLed(0, i, isPlayer1 ? 0 : 7, true);
    } else {
      lc.setLed(0, i, isPlayer1 ? 0 : 7, false);
    }
  }
}

void drawBall() {
  lc.setLed(0, ballY, ballX, true);
}

void updateBall() {
  lc.setLed(0, ballY, ballX, false);
  ballX += ballDirX;
  ballY += ballDirY;

  if (ballY == 0 || ballY == 7) ballDirY *= -1;
  if (ballX == 0 || ballX == 7) ballDirX *= -1;

  if (ballX == 1 && ballY >= player1Y && ballY < player1Y + playerHeight) ballDirX *= -1;
  if (ballX == 6 && ballY >= player2Y && ballY < player2Y + playerHeight) ballDirX *= -1;
}

void loop() {
  player1Y = map(analogRead(pot1Pin), 0, 1023, 0, 5);
  player2Y = map(analogRead(pot2Pin), 0, 1023, 0, 5);

  drawPaddle(player1Y, true);
  drawPaddle(player2Y, false);

  updateBall();
  drawBall();

  delay(200); // Geschwindigkeit des Spiels
}