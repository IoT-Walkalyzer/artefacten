// Includes
#include <Arduino.h>
#include "utilities.hpp"

// Variables
uint16_t matrix[1600] = {};

// Methods
void setup() {
    Serial.begin(921600);
}

void loop() {
    Serial.write('s'); // Start of matrix Header

    for (uint16_t value : matrix)
        Serial.write(integral_to_bytes<uint16_t>(value).bytes, 2);
}
