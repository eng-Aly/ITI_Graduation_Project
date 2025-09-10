import serial

port = serial.Serial("/dev/ttyUSB0", baudrate=115200, timeout=3.0)

while True:
    port.write(b"\r\nSay something:")
    rcv = port.read(30)
    port.write(b"\r\nYou sent:" + repr(rcv).encode())
