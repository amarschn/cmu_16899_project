// Muscle identifiers
#define M1 1
#define M2 2

// Muscle 1 pins
#define M1_PIN_CONTRACT 3
#define M1_PIN_RELAX 11

// Muscle 2 pins
#define M2_PIN_CONTRACT 9
#define M2_PIN_RELAX 10

void pwm_muscle(float duty_cycle, int seconds, bool contract);
