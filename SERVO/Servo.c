#include <ESP32Servo.h>

Servo myServo;
TaskHandle_t ServoTaskHandle;

void ServoTask(void *pvParameters) {
  for (;;) {
    myServo.write(0);
    vTaskDelay(pdMS_TO_TICKS(500));  

    myServo.write(90);
    vTaskDelay(pdMS_TO_TICKS(500));

  }
}

void setup() {
  // Attach servo to GPIO 4, assign channel 0 explicitly for S3
  myServo.attach(4, 500, 2500);  
  // (500–2500 µs pulse width)

  xTaskCreatePinnedToCore(
    ServoTask,
    "ServoTask",
    2048,
    NULL,
    1,
    &ServoTaskHandle,
    0  // Run on core 0
  );
}

void loop() {
  // Empty - FreeRTOS handles tasks
}