import serial
import time

def python_to_arduino():
    for i in range(10):
        with serial.Serial('/dev/cu.usbmodem14201',9800,timeout=1) as ser:
            ser.write(b"lmao")
python_to_arduino()