import numpy as np

class Differential():
    """Class for handling kinematics of a mecanum wheel robot."""
    
    def __init__(self):
        self.ann = 0

    def inverse_kinematics(self, robot_velocities):
        linear_x, linear_y, angular = robot_velocities
        wheel_velocities = np.array([1.0, 1.0, 0.0, 0.0])
        
        wheel_velocities[0], wheel_velocities[1] =-( wheel_velocities[0]*linear_x - angular), (wheel_velocities[1]*linear_x + angular)
        return wheel_velocities

