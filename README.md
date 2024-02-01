# artefacten

## How to use
All ESP code (C++) was written using [JetBrains CLion](https://www.jetbrains.com/clion/) and [PlatformIO](https://docs.platformio.org/en/latest/core/installation/index.html). You can follow the linked guides to setup
your own environment.

All Client code (Python) was written using [JetBrains PyCharm](https://www.jetbrains.com/pycharm/). You can install any needed dependency via the `requirements.txt` file with the following command:
```shell
pip install -r ./requirements.txt
```

## Proof-of-Concept (PoC)
The `poc` directory contains all the code of the fastes solution that has been tested with the pressureplates. It has the same structure as the `test` directory.

## Test Results
> *Please note that results may vary.*

All results can be found within the `tests` directory. Here you will find `README.md` files which will include the results.

It is important to note that all results are based on a **well** used ESP-WROOM-32 and a PC with the following specifications:

| Component | Used |
|---|---|
| Motherboard | ASUS PRIME B650-PLUS |
| CPU | AMD Ryzen 7 7700X |
| GPU | ASUS Dual AMD RX 6750 XT OC |
| RAM | 32GB DDR5 5200MHz (Dual Channel) |
| Storage | 2x Samsung M.2 980 PRO 1TB |
| OS | Windows 10 (Atlas) |

## Final Notes
* We also tested jumboFrames, but with the ESP-WROOM-32 this is not possible. The RAM size is to small to contain the program itself + a jumbo frame (even as small as a jumbo frame of size 2). With `uint8_t` this is possible however. But we need to use `uint16_t`, since the max value returned by the pressureplate lane is 4095 and `uint8_t`'s max value is 255.
* We also started looking at a change only update system which would allow for smaller packets, however due to time limitations this has not been realised.

