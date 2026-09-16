#include <DabbleESP32.h>

void setup() {
  Serial.begin(115200);

  Dabble.begin("ESP32_abi");

  Serial.println("ESP32 started!");
  Serial.println("Bluetooth Name: ESP32_abi");
}

void loop() {
  Dabble.processInput();

  if (Terminal.available()) {
    String message = Terminal.readString();

    Serial.print("Received: ");
    Serial.println(message);

    Terminal.println("ESP32 received: " + message);
  }

  delay(50);
}
