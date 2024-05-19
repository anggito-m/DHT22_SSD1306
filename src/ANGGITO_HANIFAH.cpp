#include "ANGGITO_HANIFAH.h"

DHT22_SSD1306::DHT22_SSD1306(uint8_t dhtPin, uint8_t dhtType, int oledReset, uint8_t oledAddress)
    : dht(dhtPin, dhtType), display(Adafruit_SSD1306(128, 64, &Wire, oledReset)), oledAddress(oledAddress) {}

void DHT22_SSD1306::begin() {
    dht.begin();
    if(!display.begin(SSD1306_SWITCHCAPVCC, oledAddress)) {
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    display.clearDisplay();
    display.setTextColor(SSD1306_WHITE);
}

float DHT22_SSD1306::readTemperature() {
    float temperature = dht.readTemperature();
    if (isnan(temperature)) {
        Serial.println(F("Failed to read temperature from DHT sensor!"));
        return NAN;
    }
    return temperature;
}

float DHT22_SSD1306::readHumidity() {
    float humidity = dht.readHumidity();
    if (isnan(humidity)) {
        Serial.println(F("Failed to read humidity from DHT sensor!"));
        return NAN;
    }
    return humidity;
}

void DHT22_SSD1306::displayDHT22(float temperature, float humidity) {
    display.clearDisplay();
    display.setTextSize(1);
    display.setCursor(0, 0);
    display.print(F("Temp: "));
    display.print(temperature);
    display.print(F(" C"));
    display.setCursor(0, 10);
    display.print(F("Hum: "));
    display.print(humidity);
    display.print(F(" %"));
    display.display();
}

void DHT22_SSD1306::displayDHT22(float temperature, float humidity, float textSize) {
    display.clearDisplay();
    display.setTextSize(textSize);
    display.setCursor(0, 0);
    display.print(F("Temp: "));
    display.print(temperature);
    display.println(F(" C"));
    display.print(F("Hum: "));
    display.print(humidity);
    display.print(F(" %"));
    display.display();
};


