# Imports
from paho.mqtt.client import Client, MQTTMessage
from datetime import datetime
from typing import Any
from numpy import frombuffer, uint16

# Variables
listener = Client("observer")
received = 0
start = datetime.now()

# Methods
def on_message(client: Client, userdata: Any, message: MQTTMessage):
    global received, start

    if received == 300:
        exit()

    matrix = frombuffer(
        message.payload,
        uint16
    )
    current = datetime.now()
    difference = (current - start).total_seconds()
    frequency = received / difference
    received += 1

    print(f"\rFrequency of {frequency}Hz based on {received} received matrix's.", end = '')

# Main
if __name__ == "__main__":
    try:
        listener.on_message = on_message
        listener.connect("<MQTT_HOST>", 1883)
        listener.subscribe("stressTest")
        listener.loop_forever()
    except (KeyboardInterrupt, Exception):
        listener.disconnect()
