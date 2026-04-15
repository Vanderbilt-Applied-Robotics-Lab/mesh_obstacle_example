#ifndef MESH_OBSTACLE_PLANNER
#define MESH_OBSTACLE_PLANNER

#include <rclcpp/rclcpp.hpp>
#include <string>

// INSERT INCLUDES HERE

class MeshObstaclePlanner : public rclcpp::Node
{
public:
    /**
     * Main constructor
     * sets up the publisher for the /display_planned_path topic
     */
    MeshObstaclePlanner();

    /**
     * Destructor
     */
    ~MeshObstaclePlanner() = default;

    /**
     * main robot motion code
     */
    void mainRobotMotion();

    /**
     * initializes the movegroup
     * sets the max planning time
     * sets the max number of planning attempts
     */
    void initMoveGroup();

    /**
     * adds mesh collision object
     */
    void addMeshObstacle();

    /**
     * plan a path to the input joint angles
     * if successful, visualize the path plan by publishing to the /display_planned_path topic
     * @param joints The target joint angles
     * @return true if the plan succeeds
     */
    bool planMotionAndVisualize(std::vector<double> & joints);

    /**
     * execute the computed path plan
     */
    void moveJoints();
    
private:

    // insert planning scene interface here

    // insert path plan object here
    
    // insert move group object here
    
    // insert starting joint angles here
    
    // insert goal joint angles here
    
    // insert publisher for /display_planned_path topic here
};

#endif // MESH_OBSTACLE_PLANNER