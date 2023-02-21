import serial
import time
import schedule
import math
import smtplib

def sendEmail():
    FROM = 'fluidflowfindersk@gmail.com'
    TO = ["fluidflowfinders@gmail.com"]
    SUBJECT = "Hello!"
    TEXT = "This message was sent with Python's smtplib."
    message = 'hi'
    server = smtplib.SMTP('myserver')
    server.sendmail(FROM, TO, message)
    server.quit()
sendEmail()