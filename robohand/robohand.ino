#include "robohand.h"

void setup() {
  pinMode(M1_PIN_CONTRACT, OUTPUT);
  pinMode(M1_PIN_RELAX, OUTPUT);
  pinMode(M2_PIN_CONTRACT, OUTPUT);
  pinMode(M2_PIN_RELAX, OUTPUT);

  pinMode(FLEX_PIN_1, INPUT);
  pinMode(FLEX_PIN_2, INPUT);
  
  // set timer 1 divisor to  1024 for PWM frequency of    30.64 Hz
  TCCR1B = TCCR1B & B11111000 | B00000101;
  // set timer 2 divisor to  1024 for PWM frequency of 30.64 Hz
  // See https://arduino-info.wikispaces.com/Arduino-PWM-Frequency for details
  TCCR2B = TCCR2B & B11111000 | B00000111;
  Serial.begin(9600);
}

void loop() {
  int flex1 = analogRead(FLEX_PIN_1);
  int pos1 = map(flex1, 650, 800, 0, 255);
  pos1 = constrain(pos1, 0, 255);

  Serial.println(pos1);
  
  move_finger(pos1);
}
