
import serial  # Use pySerial for serial communication
import time

# Access the camer

# Initialize serial communication (Replace COM7 with your port, adjust baud rate as needed)
My_Serial = serial.Serial("/dev/ttyUSB1", 9600, timeout=1)

while True:
        My_Serial.write("a7a".encode())
        time.sleep(2)
        print("a7a")        
