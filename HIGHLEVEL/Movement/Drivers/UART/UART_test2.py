import time
from UART import UART
#port = serial.Serial("/dev/ttyUSB0", baudrate=115200, timeout=1)

#time.sleep(2)
UART_movement = UART(port='/dev/ttyUSB0', baudrate=115200, timeout=1)
port = UART_movement.ser
time.sleep(2)  # wait for the serial connection to initialize

while True:
    msg = "Hello UART!\n"
    port.write(msg.encode())  # send
    print("Sent:", msg.strip())

    rcv = port.readline().decode(errors="ignore")  # read line
    print("Received:", rcv.strip())
    time.sleep(1)
