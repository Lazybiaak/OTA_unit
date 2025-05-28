#include <Arduino.h>
#include <RemoteOTA.h>

// ==== Config ====
const char* ssid = "Apple";
const char* password = "123456789";

RemoteOTA ota(
  "0.0.0",
  "https://lazybiaak.github.io/OTA_unit/ota/version.txt",
  "https://lazybiaak.github.io/OTA_unit/ota/firmware.bin"
);

const int ledPin = LED_BUILTIN;  // usually GPIO2 on ESP32

void setup() {
  pinMode(ledPin, OUTPUT);

  ota.begin(ssid, password);
  ota.check();  // Check OTA on boot
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delay(500);
  digitalWrite(ledPin, LOW);
  delay(500);
}