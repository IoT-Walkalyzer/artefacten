// Includes
#include <Arduino.h>
#include <WiFi.h>
#include <WiFiUdp.h>
#include "utilities.hpp"

// Variables
uint16_t matrix[1600] = {};
WiFiUDP udpClient;

// Methods
void setup() {
    Serial.begin(921600);
    WiFi.begin("<SSID>", "<PSWD>");

    while (WiFiClass::status() != WL_CONNECTED)
        delay(1000);
}

void loop() {
    udpClient.beginPacket("<HOST>", "<PORT(int)>");
    for (uint16_t value : matrix)
        udpClient.write(integral_to_bytes<uint16_t>(value).bytes, 2);
    udpClient.endPacket();
}