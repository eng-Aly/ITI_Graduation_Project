import numpy as np

class Kinematics:
    """Parent kinematics class"""
    def __init__(self, wheel_radius):
        self.wheel_radius = wheel_radius
        self.no_of_wheels = 0
        self.inverse_kinematics_matrix = None
        self.forward_kinematics_matrix = None
        
    def forward_kinematics(self, wheel_velocities):
        """Calculates forward kinematics (robot velocities) based on wheel velocities."""
        if self.forward_kinematics_matrix is None:
            raise NotImplementedError("Forward kinematics matrix not defined.")
        
        return (self.wheel_radius / self.no_of_wheels) * (self.forward_kinematics_matrix @ np.array(wheel_velocities).reshape(-1, 1))
    
    def inverse_kinematics(self, robot_velocities):
        """Calculates inverse kinematics (wheel velocities) for a robot configuration."""
        if self.inverse_kinematics_matrix is None:
            raise NotImplementedError("Inverse kinematics matrix not defined.")
        
        return (60 / (2 * np.pi)/ self.wheel_radius) * (self.inverse_kinematics_matrix @ np.array(robot_velocities).reshape(-1, 1))