#Python code for connecting Arduino to Python
#That's Engineering
#29/04/2020

import serial
import time
import schedule
import math

def main_func():
    arduino = serial.Serial('/dev/cu.usbmodem14201', 9600)
    print('Established serial connection to Arduino')
    arduino_data = arduino.readline()
    decoded_values = str(arduino_data[0:len(arduino_data)].decode("utf-8")).strip()
    list_values = decoded_values.split('x')
    #print(decoded_values)
    #print(list_values.items())
    for item in list_values:
        if item == '':
            item = '0'
        list_in_floats.append(math.floor(float(item)))
    print(f'Collected readings from Arduino: {list_in_floats}')
    print("Average: " + str(average(list_in_floats)))
    print("Standard Deviation: " + str(std(list_in_floats)))
    print("Standard Error: " + str(st_error(list_in_floats)))
    arduino_data = 0
    list_values.clear()
    arduino.close()
    print('Connection closed')
    print('<----------------------------->')
def average(list_in_floats):
    sum = 0
    for item in list_in_floats:
        sum += item
    average = math.floor((sum) / len(list_in_floats))
    return average
def std(list_in_floats):
    numerator = 0
    for item in list_in_floats:
        numerator += ((float(item) - float(average(list_in_floats)))**2)
    std = math.floor(math.sqrt(numerator / len(list_in_floats)))
    return std
def st_error(list_in_floats):
    error = math.floor(std(list_in_floats)/len(list_in_floats))
    return error
# ----------------------------------------Main Code------------------------------------
# Declare variables to be used
list_values = []
list_in_floats = []
list_of_data = []

print('Program started')

# Setting up the Arduino
schedule.every(1).seconds.do(main_func)

while True:
    schedule.run_pending()
    time.sleep(1)


#average flow rate
#STD
#St Error
