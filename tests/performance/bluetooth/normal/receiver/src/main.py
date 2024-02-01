# Imports
from serial import Serial
from datetime import datetime
from numpy import frombuffer, uint16

# Variables
serial = Serial(
    port = "COM4",
    baudrate = 921600
)
received = 0
start = datetime.now()

# Main
if __name__ == "__main__":
    try:
        while received != 300:
            if serial.read(1) == b's':
                matrix = frombuffer(
                    serial.read(3200),
                    uint16
                )

                current = datetime.now()
                difference = (current - start).total_seconds()
                frequency = received / difference
                received += 1

                print(f"\rFrequency of {frequency}Hz based on {received} received matrix's.", end = '')
    except KeyboardInterrupt:
        serial.close()
