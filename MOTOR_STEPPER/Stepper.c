#include <Stepper.h>

#define A_MINUS 14
#define A_PLUS  13
#define B_PLUS  12
#define B_MINUS 11

const int stepsPerRevolution = 200;

Stepper myStepper(stepsPerRevolution, A_MINUS, A_PLUS, B_PLUS, B_MINUS);

void setup() {
  Serial.begin(115200);
  myStepper.setSpeed(30);
  Serial.println("Simulasi Stepper Bipolar dimulai...");
}

void loop() {
  Serial.println("Putar searah jarum jam...");
  myStepper.step(stepsPerRevolution);
  delay(1000);

  Serial.println("Putar berlawanan arah jarum jam...");
  myStepper.step(-stepsPerRevolution);
  delay(1000);
}
