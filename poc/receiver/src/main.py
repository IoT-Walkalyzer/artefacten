# Imports
from socket import socket, AF_INET, SOCK_DGRAM
from datetime import datetime
from sys import argv
from numpy import frombuffer, uint16

# Variables
udpServer = socket(AF_INET, SOCK_DGRAM)
received = 0
start = datetime.now()
count = argv[1]
index = {}

# Main
if __name__ == "__main__":
    try:
        udpServer.bind(("<HOST>", "<PORT(int)>"))

        while len(index) != count:
            raw_data, ip = udpServer.recvfrom(3200)
            matrix = frombuffer(raw_data, uint16)

            for cell in matrix:
                if cell > 2000:
                    index.update(ip)

        while True:
            try:
                # TODO index from and send onward
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
