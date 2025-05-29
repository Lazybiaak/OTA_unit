#include <Arduino.h>
#include <RemoteOTA.h>

// ==== Config ====
const char* ssid = "Apple";
const char* password = "123456789";

RemoteOTA ota(
  "0.0.2",
  "https://lazybiaak.github.io/OTA_unit/ota/version.txt",
  "https://lazybiaak.github.io/OTA_unit/ota/firmware.bin"
);

const int ledPin = LED_BUILTIN;  // usually GPIO2 on ESP32

void setup() {
  Serial.begin(115200);
  Serial.println("Starting Remote OTA Example...");
  pinMode(ledPin, OUTPUT);

  ota.begin(ssid, password);
  ota.check();  // Check OTA on boot
}

void loop() {
  Serial.println("This version is: 0.0.2");
  delay(2000);
}