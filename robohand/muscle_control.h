// Muscle identifiers
#define M1 1
#define M2 2

// Muscle 1 pins
#define M1_PIN_CONTRACT 11 
#define M1_PIN_RELAX 10

// Muscle 2 pins
#define M2_PIN_CONTRACT 9
#define M2_PIN_RELAX 3

void pwm_muscle(int muscle, float duty_cycle, int seconds, bool contract);
