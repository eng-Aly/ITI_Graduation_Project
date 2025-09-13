from Drivers.UART.UART import UART 
from Drivers.Kinematics.Mecanum_kinematics import KinematicsMecanum
from Drivers.Kinematics.Differential_kinematics import Differential
import time as Time
import serial  # Use pySerial for serial communication
import time

#Conrtoller_USB = '/dev/ttyUSB1'
Movement_USB = '/dev/ttyUSB0'

#UART_Controller = UART(port=Conrtoller_USB, baudrate=115200, timeout=0.1)
UART_Movement = UART("/dev/ttyUSB0", 9600, timeout=1)



mecanum_control = KinematicsMecanum(wheel_radius=0.076, lx=0.269, ly=0.2327)
# wheel diameter = 15.2 cm
# horizontal distance from the center of the robot
# vertical distance from the center of the robot
differential_control = Differential()

def main():
    while True:
        #data = UART_Controller.receive_data()
        data = input()  # Example data for testing
        if data:
            try:
                linear_x, linear_y, angular = map(float, data.split(','))
                robot_velocities = (linear_x, linear_y, angular)
                
                wheel_velocities_mecanum = mecanum_control.inverse_kinematics(robot_velocities)
                if max(abs(v) for v in wheel_velocities_mecanum) > 0:
                    wheel_velocities_mecanum = [v / max(abs(v) for v in wheel_velocities_mecanum) * 100 for v in wheel_velocities_mecanum]                
                
                wheel_velocities_differential = differential_control.inverse_kinematics(robot_velocities)
                if max(abs(v) for v in wheel_velocities_differential) > 0:
                    wheel_velocities_differential = [v / max(abs(v) for v in wheel_velocities_differential) * 100 for v in wheel_velocities_differential]                   
                
                command_mecanum = ",".join(f"{int(v)}" for v in wheel_velocities_mecanum) + "\n"                 #needs the params of shato   
                command_differential = f"{int(wheel_velocities_differential[0])},{int(wheel_velocities_differential[1])},{int(wheel_velocities_differential[2])},{int(wheel_velocities_differential[3])}\n"
                print(f"command mecanum = {command_mecanum}")
                print(f"command differential = {command_differential}")
                
                UART_Movement.send_data(command_differential)
                X=UART_Movement.receive_data()
                print(X)
                #print("recieved",UART_Movement.receive_data())    
            except ValueError:
                print("Invalid data format received.")

def main_2():
    while(1):
        UART_Movement.send_data(1)
        print("sent")
        Time.sleep(5)
def main_3():
    while(1):
        UART_Movement.send_data("a7a".encode())
        time.sleep(2)
        print("a7a")          

if __name__ == "__main__":
    main()                