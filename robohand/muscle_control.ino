#include "muscle_control.h"

/*
 * PWM the muscle for contraction or relaxation
 *  muscle: which muscle to use, either M1 or M2
 *  duty_cycle: Duty cycle at which to pwm the muscle, in the range 0.0 - 1.0
 *  seconds: How long the muscle contracts/relaxes in milliseconds
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
