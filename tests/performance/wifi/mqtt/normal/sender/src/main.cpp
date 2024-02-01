// Includes
#include <Arduino.h>
#include <WiFi.h>
#include <mqtt_client.h>
#include "utilities.hpp"

// Variables
uint16_t matrix[1600] = {};
const esp_mqtt_client_config_t mqttConf = {
        .host = "<MQTT_HOST>",
        .port = 1883,
        .client_id = "esp-wroom-32",
        .buffer_size = 3200
};
esp_mqtt_client_handle_t mqttClient;

// Methods
void setup() {
    Serial.begin(921600);
    WiFi.begin("<SSID>", "<PSWD>");

    while (WiFi.status() != WL_CONNECTED)
        delay(1000);

    mqttClient = esp_mqtt_client_init(&mqttConf);
    esp_mqtt_client_start(mqttClient);
}

void loop() {
    uint8_t matrixBytes[2 * 1600];

    for (uint16_t valueIndex = 0; valueIndex < 1600; ++valueIndex)
        memcpy(matrixBytes + (valueIndex * 2), integral_to_bytes<uint16_t>(matrix[valueIndex]).bytes, 2);

    esp_mqtt_client_publish(
            mqttClient,
            "stressTest",
            (const char*)matrixBytes,
            sizeof(matrix),
            0,
            0
    );
}