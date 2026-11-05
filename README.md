# mesh_obstacle_example
In-class example for mesh obstacles and visualizing path plans programmatically

## Downloading Code
1. Navigate to examples workspace source folder: `cd ~/workspaces/examples_ws/src`
2. Download code: `git clone https://github.com/Vanderbilt-Applied-Robotics-Lab/mesh_obstacle_example.git`

## Compiling Code
1. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
2. Compile the code: `colcon build`

## Running Code
1. Navigate to the mitsubishi workspace: `cd ~/workspaces/mitsubishi_ws/`
2. Source the mitsubishi workspace: `source install/setup.bash`
3. Run the mitsubishi code: `ros2 launch mitsubishi_robot_bringup moveit.launch.py simulation:=true`
4. Make sure the MotionPlanning is enabled in RVIZ
5. Open a new terminal window
6. Navigate to the examples workspace: `cd ~/workspaces/examples_ws`
7. Source the examples workspace: `source install/setup.bash`
8. Run the code: `ros2 run mesh_obstacle_planner mesh_obstacle_planner`



