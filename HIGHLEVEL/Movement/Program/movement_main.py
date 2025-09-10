from Drivers.UART.UART import UART 
from Drivers.Kinematics.Mecanum_kinematics import KinematicsMecanum
from Drivers.Kinematics.Differential_kinematics import Differential


Conrtoller_USB = '/dev/ttyUSB1'
Movement_USB = '/dev/ttyUSB0'

UART_Controller = UART(port=Conrtoller_USB, baudrate=115200, timeout=0.1)
UART_Movement = UART(port=Movement_USB, baudrate=115200, timeout=1)



mecanum_control = KinematicsMecanum(wheel_radius=0.05, lx=0.2, ly=0.2)
differential_control = Differential()

def main():
    while True:
        #data = UART_Controller.receive_data()
        data = "0.5,0.0,0.1"  # Example data for testing
        if data:
            try:
                linear_x, linear_y, angular = map(float, data.split(','))
                robot_velocities = (linear_x, linear_y, angular)
                
                wheel_velocities_mecanum = mecanum_control.inverse_kinematics(robot_velocities)
                wheel_velocities_differential = differential_control.inverse_kinematics(robot_velocities)
                
                command_mecanum = ",".join(f"{float(v):.2f}" for v in wheel_velocities_mecanum) + "\n"
                command_differential = f"{wheel_velocities_differential[0]:.2f},{wheel_velocities_differential[1]:.2f},{wheel_velocities_differential[2]:.2f},{wheel_velocities_differential[3]:.2f}\n"
                
                #UART_Movement.send_data(command_mecanum)
                UART_Movement.send_data(command_differential)
                print("recieved",UART_Movement.receive_data())    
            except ValueError:
                print("Invalid data format received.")
if __name__ == "__main__":
    main()                 