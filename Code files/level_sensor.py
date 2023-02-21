import serial
import time
import schedule
import math

#in case need to refresh
#https://py3.codeskulptor.org/#user307_HkTHle8EG4_4.py

#wifi number thingy
#'/dev/cu.usbserial-1420'
def main_func():
    arduino = serial.Serial('/dev/cu.usbmodem14201', 9600)
    #print(arduino)
    print('Established serial connection to Arduino')
    arduino_data = arduino.readline()
    decoded_values = str(arduino_data[0:len(arduino_data)], 'latin-1').strip()
    print(decoded_values)
    list_values = decoded_values.split(',')
    list_numbers = [x[-1] for x in list_values]
    #print(list_values)
    #print(list_numbers)

    for item in list_numbers:
        list_in_floats.append(int(item))

    print(f'Collected readings from Arduino: {list_in_floats}')
    print("Highest sensor position: " + str(sensor_position(list_in_floats)))
    print("Calculated water flow: " + str(water_flow(list_in_floats)))
    if water_flow(list_in_floats) > 3:
        python_to_arduino(arduino)
    #arduino_data = 0
    list_in_floats.clear()
    list_values.clear()
    arduino.close()
    print('Connection closed')
    print('<----------------------------->')

def sensor_position(list_of_ints):
    if list_in_floats.count(0)==0:
        return len(list_of_ints)
    else:
        return list_in_floats.index(0)

def water_flow(list_of_ints):
    #Constants:
    diameter = 0.125  #in feet
    n = 0.009 
    gallons_convert = 448.831169
    
    #Inputs:
    number_of_sensors = 11
    radius = diameter/2
    height_constant = (diameter)/number_of_sensors
    water_height = (sensor_position(list_of_ints)*height_constant) #in feet
    slope = 0.15
    theta = (2*math.pi)-(2*math.acos((radius-water_height)/radius))
    a_var = (math.pi*(radius**2)) - ((radius**2)*(theta-math.sin(theta)))/2
    wetted_perimeter = (2*math.pi*radius) - (radius*theta)

    if wetted_perimeter == 0:
        rh = 0
    else:
        rh = a_var/wetted_perimeter
    
    #Flow 
    flow_rate_ft = (1.49/n)*a_var*(rh**(2/3))*(math.sqrt(slope))
    flow_rate_gals = 448.831169 * flow_rate_ft
    return flow_rate_gals

def python_to_arduino(serialport):
    print('leak')
    serialport.write(b"A leak has been detected")

#def water_flow(list_of_ints):
#    water_height = height_constant * sensor_position(list_of_ints)
#    print(water_height)
#    theta = 2*math.pi-2*(math.acos((radius-water_height)/ radius))
#    print(theta)
#    A_var = (radius**2)*math.pi-((radius**2)/2)*(theta - math.sin(theta))
#    print(A_var)
#    if theta == 0:
#        rh = 0
#    else:
#        rh = A_var / (2*math.pi*radius-radius*theta)
#    water_flow = (1.49/n)*A_var*(rh**(3/2))*(slope**(1/2))
#    return water_flow


# ----------------------------------------Main Code------------------------------------
# Declare variables to be used
list_values = []
list_in_floats = []

print('Program started')

# Setting up the Arduino
schedule.every(0.5).seconds.do(main_func)

while True:
    schedule.run_pending()
    time.sleep(0.5)