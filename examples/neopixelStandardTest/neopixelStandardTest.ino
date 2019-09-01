#include <Arduino.h>
#include <pins_arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include <Wire.h>
//#### Screen SETUP ######
#include "SPI.h"
#include <TFT_eSPI.h>
#define BACKLIGHT_CHANNEL   ((uint8_t)1)
#define TFT_BL              12
TFT_eSPI tft = TFT_eSPI();   // Invoke library
//########################
#include "Adafruit_NeoPixel.h"

#define PIN            21
#define NUMPIXELS      4
Adafruit_NeoPixel NeoPixel1 = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);



void setup()
{
  // Wire.begin(TOUCH_SDA, TOUCH_SCL);
  // Wire1.begin(SENSOR_SDA, SENSOR_SCL);
  SPI.begin(TFT_SCLK, TFT_MISO, TFT_MOSI, -1); 

  ledcAttachPin(TFT_BL, 1);
  ledcSetup(BACKLIGHT_CHANNEL, 12000, 8);
  ledcWrite(BACKLIGHT_CHANNEL, 255);

  tft.init();
  tft.fillScreen(0xFFFF);
  tft.setRotation(0);
  tft.setTextSize(1);
  tft.setSwapBytes(true);

  
  NeoPixel1.begin();



    NeoPixel1.setBrightness(128);
    NeoPixel1.show();

}
void loop()
{
      for (uint16_t i = 0; i < NeoPixel1.numPixels(); i++) {
      NeoPixel1.setPixelColor(i, NeoPixel1.Color(204, 0, 0));
      NeoPixel1.show();
      delay(25);
    }
    delay(1000);
    for (uint16_t i = 0; i < NeoPixel1.numPixels(); i++) {
      NeoPixel1.setPixelColor(i, NeoPixel1.Color(51, 204, 0));
      NeoPixel1.show();
      delay(25);
    }
    delay(1000);
    for (uint16_t i = 0; i < NeoPixel1.numPixels(); i++) {
      NeoPixel1.setPixelColor(i, NeoPixel1.Color(51, 51, 255));
      NeoPixel1.show();
      delay(25);
    }
    delay(1000);

  
}
