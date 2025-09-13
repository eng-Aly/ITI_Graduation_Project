#pip install pyserial
import serial
import time


class UART:
    def __init__(self, port='COM3', baudrate=115200, timeout=1):
        self.ser = serial.Serial(port, baudrate, timeout=timeout)
    def send_data(self, data):
            msg=str(data)+'\n'
            self.ser.write(msg.encode())  # send
    def receive_data(self):
            rcv = self.ser.readline().decode(errors="ignore")
            return rcv.strip()
    def close(self):
        if self.ser.is_open:
            self.ser.close()

