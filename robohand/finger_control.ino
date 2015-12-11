#include "finger_control.h"


/**
 * pos is a value between 0-255, where 255 is maximum flexion (bending), and 0 is maximum extension (straightening)
 */
void move_finger(int pos) {
  int M1_flex = pos;
  int M1_relax = 255 - pos;
  
  int M2_flex = 255 - pos;
  int M2_relax = pos;

  analogWrite(M1_PIN_CONTRACT, M1_flex);
  analogWrite(M1_PIN_RELAX, M1_relax);
  analogWrite(M2_PIN_CONTRACT, M2_flex);
  analogWrite(M2_PIN_RELAX, M2_relax);
  delay(FLEX_TIME);
}

