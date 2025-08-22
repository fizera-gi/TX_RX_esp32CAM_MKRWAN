#include <Arduino.h>
#include <MKRWAN.h>
#include <LoRa.h>

LoRaModem modem;

void txPacket(const String& s) {
  LoRa.beginPacket();
  LoRa.print(s);
  LoRa.endPacket();
}

void setup() {
  Serial.begin(57600);
  while (!Serial);

  modem.dumb();

  // init SX1276 @434 MHz
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

  while (Serial1.available()) {
    char c = Serial1.read();
    if (c == '\n') {
      if (line.startsWith("SIZE:")) {
        Serial.println();
        Serial.println("[INFO] " + line);
        txPacket(line);
        inImage = true;

      } else if (line == "END") {
        Serial.println();
        Serial.println("[INFO] Transmission complete.");
        txPacket(line);
        inImage = false;

      } else if (inImage) {
        Serial.print(line);    // echo locally
        Serial.print(" ");     
        txPacket(line);
      }

      line = "\n";  // reset for next
    } 
    else {
      if (line.length() < 250) line += c;
    }
  }
}