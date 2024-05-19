#ifndef ANGGITO_HANIFAH_H
#define ANGGITO_HANIFAH_H

#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>
#include <Wire.h>

class DHT22_SSD1306 {
public:
    DHT22_SSD1306(uint8_t dhtPin, uint8_t dhtType, int oledReset, uint8_t oledAddress);
    void begin();
    float readTemperature();
    float readHumidity();
    void displayDHT22(float temperature, float humidity);
    void displayDHT22(float temperature, float humidity, float textSize);

private:
    DHT dht;
    Adafruit_SSD1306 display;
    uint8_t oledAddress;
};

#endif
