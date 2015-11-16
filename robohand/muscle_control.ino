#include "muscle_control.h"

/*
 * PWM the muscle for contraction or relaxation
 *  duty_cycle: Duty cycle at which to pwm the muscle
 *  seconds: How long the muscle contracts/relaxes
 *  contract: Boolean value determining whether to use the contraction valve or the relaxation valve
 */
void pwm_muscle(int muscle, float duty_cycle, int milliseconds, bool contract) {
  
  int pin;
  
  // Determine which pin to pwm
  if (muscle == M1) {
    if (contract) {
      pin = M1_PIN_CONTRACT;
    } else {
      pin = M1_PIN_RELAX;
    }
  } else if (muscle == M2){
    if (contract) {
      pin = M2_PIN_CONTRACT;
    } else {
      pin = M2_PIN_RELAX;
    }
  }
  
  // Convert pwm duty cycle into integer value for use with the analogWrite function
  int pwm_value = (int)(duty_cycle * 255);
  analogWrite(pin, pwm_value);
  delay(milliseconds);
  analogWrite(pin, 0);
  return;
}
