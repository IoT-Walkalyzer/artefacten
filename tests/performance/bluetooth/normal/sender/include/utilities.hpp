#ifndef SENDER_UTILITIES_HPP
#define SENDER_UTILITIES_HPP

// Includes
#include <cstdint>

// Types
struct ByteArray {
    uint8_t* bytes;
};

// Methods
template<typename Input = int>
ByteArray integral_to_bytes(const Input& input) {
    constexpr uint8_t size = sizeof(Input);
    uint8_t bytes[size];

    for (uint8_t i = 0; i < (uint8_t)size; ++i)
        bytes[(size - 1) - i] = (uint8_t)((input >> (i * 8)) & 0xFF);
    return ByteArray{ bytes };
}

template<typename Output = int>
Output bytes_to_integral(const ByteArray& byteArray) {
    Output output;

    for (uint8_t byteIndex = 0; byteIndex < (uint8_t)sizeof(byteArray.bytes); ++byteIndex)
        output = (output << 8) | ((Output)byteArray.bytes[byteIndex] & 0xFF);
    return output;
}

#endif
