#include <Stepper.h>

// --- Konfigurasi pin sesuai koneksi di Wokwi ---
#define A_MINUS 14
#define A_PLUS  13
#define B_PLUS  12
#define B_MINUS 11

// --- Jumlah langkah per putaran (umum untuk motor bipolar) ---
const int stepsPerRevolution = 200;

// --- Inisialisasi objek Stepper ---
// Urutan: IN1, IN2, IN3, IN4
Stepper myStepper(stepsPerRevolution, A_MINUS, A_PLUS, B_PLUS, B_MINUS);

void setup() {
  Serial.begin(115200);
  myStepper.setSpeed(30); // RPM
  Serial.println("Simulasi Stepper Bipolar dimulai...");
}

void loop() {
  Serial.println("Putar searah jarum jam...");
  myStepper.step(stepsPerRevolution);   // 1 putaran CW
  delay(1000);

  Serial.println("Putar berlawanan arah jarum jam...");
  myStepper.step(-stepsPerRevolution);  // 1 putaran CCW
  delay(1000);
}
