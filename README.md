# DHT22_SSD1306

This library allows for easy interfacing with a DHT22 temperature and humidity sensor and displays the readings on an SSD1306 OLED display.

## Installation

1. Download the library as a ZIP file.
2. Open Arduino IDE.
3. Go to `Sketch` > `Include Library` > `Add .ZIP Library...`.
4. Select the downloaded ZIP file.

## Usage

```cpp
#include <ANGGITO_HANIFAH.h>
// Define your pins and addresses
#define DHTPIN 27
#define DHTTYPE DHT22
#define OLED_ADDR 0x3C
#define OLED_RESET -1  // Use -1 if no reset pin is used

DHT22_SSD1306 dhtOled(DHTPIN, DHTTYPE, OLED_RESET, OLED_ADDR);

void setup() {
    Serial.begin(115200);
    dhtOled.begin();
}

void loop() {
    float temperature = dhtOled.readTemperature();
    float humidity = dhtOled.readHumidity();

    dhtOled.displayDHT22(temperature, humidity, 2);

    delay(2000);  // Read every 2 seconds
}
