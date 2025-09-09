#pip install serial
import serial
import time
import struct
import numpy as np

class UART:
    def __init__(self, port='COM3', baudrate=115200, timeout=1):
        self.ser = serial.Serial(port, baudrate, timeout=timeout)
    def send_data(self, data):
        if self.ser.is_open:
            packed_data = struct.pack('f' * len(data), *data)
            self.ser.write(packed_data)
        else:
            raise serial.SerialException("Serial port is not open.")
    def receive_data(self, num_floats):
        if self.ser.is_open:
            byte_data = self.ser.read(num_floats * 4)
            return struct.unpack('f' * num_floats, byte_data)
        else:
            raise serial.SerialException("Serial port is not open.")
    def close(self):
        if self.ser.is_open:
            self.ser.close()