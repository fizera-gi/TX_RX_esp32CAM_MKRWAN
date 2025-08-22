#include <Arduino.h>
#include <MKRWAN.h>
#include <LoRa.h>

LoRaModem modem;

void setup() {
  Serial.begin(57600);
  while (!Serial);

  modem.dumb();
  if (!LoRa.begin(434E6)) {
    Serial.println("Erreur: LoRa.begin failed");
    while (1);
  }
  Serial.println("LoRa TX ready @434 MHz");


  Serial1.begin(57600);
  delay(5000);
}

void loop() {
  static bool inImage = false;
  static String line;
  if (Serial1.available()) {
    line = Serial1.readStringUntil('\n');
    if (!inImage && line.startsWith("BEGIN_IMAGE")) {
      inImage = true;
      line = Serial("IMAGE_DATA:");
    } else if (inImage && line.startsWith("END_IMAGE")) {
      inImage = false;
    }
    if (inImage) {
      Serial.print(line);
    }
  }
  delay(10);
}