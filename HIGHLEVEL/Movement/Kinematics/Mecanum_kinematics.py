import numpy as np
from kinematics.Kinematics import Kinematics

class KinematicsMecanum(Kinematics):
    """Class for handling kinematics of a mecanum wheel robot."""
    
    def __init__(self, lx, ly, wheel_radius):
        """
        Initialize the KinematicsMecanum class.
        
        Parameters:
        lx (float): Half the distance between the left and right wheels.
        ly (float): Half the distance between the front and rear wheels.
        wheel_radius (float): Radius of the wheels.
        """
        super().__init__(wheel_radius)
        self.lx = lx
        self.ly = ly
        self.no_of_wheels = 4
        self.lxplusly = lx + ly
        
        # Define inverse kinematics matrix for mecanum wheel robot
        self.inverse_kinematics_matrix = np.array([
            [1, -1, -1/self.lxplusly],
            [1,  1,  1/self.lxplusly],
            [1,  1, -1/self.lxplusly],
            [1, -1,  1/self.lxplusly],
        ])
        
        # Define forward kinematics matrix for mecanum wheel robot
        self.forward_kinematics_matrix = np.array([
            [ 1,               1,                1,               1],
            [-1,               1,                1,              -1],
            [-1/self.lxplusly, 1/self.lxplusly, -1/self.lxplusly, 1/self.lxplusly]
        ])
