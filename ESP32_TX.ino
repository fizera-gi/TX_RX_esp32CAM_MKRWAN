#include "esp_camera.h"
#include <Arduino.h>

#define TXD_PIN 1  // Try not to link noth of the GNDs if it is not working
#define RXD_PIN 3

void setup() {
  Serial.begin(57600);
  Serial2.begin(57600, SERIAL_8N1, RXD_PIN, TXD_PIN);

  camera_config_t config;
  memset(&config, 0, sizeof(config));

  config.ledc_channel = LEDC_CHANNEL_0;
  config.ledc_timer   = LEDC_TIMER_0;
  config.pin_d0       = 5;
  config.pin_d1       = 18;
  config.pin_d2       = 19;
  config.pin_d3       = 21;
  config.pin_d4       = 36;
  config.pin_d5       = 39;
  config.pin_d6       = 34;
  config.pin_d7       = 35;
  config.pin_xclk     = 0;
  config.pin_pclk     = 22;
  config.pin_vsync    = 25;
  config.pin_href     = 23;
  config.pin_sscb_sda = 26;
  config.pin_sscb_scl = 27;
  config.pin_pwdn     = 32;
  config.pin_reset    = -1;           
  config.xclk_freq_hz = 20000000;
  config.pixel_format = PIXFORMAT_JPEG;
  config.frame_size   = FRAMESIZE_VGA;
  config.jpeg_quality = 20;
  config.fb_count     = 1;
  config.fb_location  = CAMERA_FB_IN_PSRAM;
  config.grab_mode    = CAMERA_GRAB_LATEST;

  esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    while (true) delay(1000);
  }
}

void loop() {
  camera_fb_t *fb = esp_camera_fb_get();
  if (!fb) {
    delay(100);
    return;
  }

  String header = "SIZE:" + String(fb->len);
  Serial2.println(header);

  const size_t chunkSize = 64;
  for (size_t i = 0; i < fb->len; i += chunkSize) {
    String hexLine;
    size_t thisChunk = min(chunkSize, fb->len - i);

    for (size_t j = 0; j < thisChunk; j++) {
      char buf[3];
      sprintf(buf, "%02X", fb->buf[i + j]);
      hexLine += buf;
      if (j + 1 < thisChunk) hexLine += ' ';
    }

    Serial2.println(hexLine);
    delay(750);  // give MKR WAN time for each packet
  }

  Serial2.println("END");
  esp_camera_fb_return(fb);

  //pause between frames
  delay(50000);
}
