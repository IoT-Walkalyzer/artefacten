// Includes
#include <Arduino.h>
#include <BluetoothSerial.h>
#include "utilities.hpp"

// Variables
uint16_t matrix[1600] = {};
BluetoothSerial SerialBT;

// Methods
void setup() {
    Serial.begin(921600);
    SerialBT.begin("iotStressTest");
}

void loop() {
    SerialBT.write('s'); // Start of matrix Header

    for (uint16_t value : matrix)
        SerialBT.write(integral_to_bytes<uint16_t>(value).bytes, 2);
}
