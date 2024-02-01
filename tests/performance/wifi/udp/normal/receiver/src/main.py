# Imports
from socket import socket, AF_INET, SOCK_DGRAM
from datetime import datetime
from numpy import frombuffer, uint16

# Variables
udpServer = socket(AF_INET, SOCK_DGRAM)
received = 0
start = datetime.now()

# Main
if __name__ == "__main__":
    try:
        udpServer.bind(("<HOST>", "<PORT(int)>"))

        while received != 300:
            try:
                matrix = frombuffer(
                    udpServer.recv(3200),
                    uint16
                )
                current = datetime.now()
                difference = (current - start).total_seconds()
                frequency = received / difference
                received += 1
            except Exception:
                continue

            print(f"\rFrequency of {frequency}Hz based on {received} received matrix's.", end = '')
    except (KeyboardInterrupt, Exception) as e:
        print(e)
        udpServer.close()
