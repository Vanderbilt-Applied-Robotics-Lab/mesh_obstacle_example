#include <mesh_obstacle_planner/mesh_obstacle_planner.h>

MeshObstaclePlanner::MeshObstaclePlanner() : Node("mesh_obstacle_planner")
{
    // SETUP PUBLISHER FOR /display_planned_path TOPIC
}

void MeshObstaclePlanner::mainRobotMotion()
{
    rclcpp::sleep_for(std::chrono::seconds(1));

    // INITIALIZE MOVEGROUP

    rclcpp::sleep_for(std::chrono::seconds(2));

    // PLAN MOTION TO STARTING CONFIG

    rclcpp::sleep_for(std::chrono::seconds(10)); // wait to allow user to visualize plan

    // IF PLANNING SUCCEEDS, MOVE JOINTS

    // ADD IN MESH COLLISION OBJECT

    // PLAN MOTION TO GOAL CONFIG

    rclcpp::sleep_for(std::chrono::seconds(10));  // wait to allow user to visualize plan

    // IF PLANNING SUCCEEDS, MOVE JOINTS
}

void MeshObstaclePlanner::initMoveGroup()
{
    // SETUP MOVE GROUP WITH NAME "rv_3s_arm"

    // SET PLANNING ATTEMPTS TO 1000
    // SET PLANNING TIME TO 300 seconds
}


void MeshObstaclePlanner::addMeshObstacle()
{
    // SETUP AND PUBLISH MESH OBJECT
}

bool MeshObstaclePlanner::planMotionAndVisualize(std::vector<double> & joints)
{
    // SETUP MESSAGE OF TYPE moveit_msgs::msg::DisplayTrajectory
    
    // SET MOVEGROUP TO joints

    // IF PLAN SUCCEEDS (i.e. returns moveit::core::MoveItErrorCode::SUCCESS), PUBLISH TRAJECTORY TO /display_planned_path TOPIC AND RETURN TRUE
    // PRINT ERROR OTHERWISE
}

void MeshObstaclePlanner::moveJoints()
{
    // EXECUTE PLAN
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<MeshObstaclePlanner>();

    node->mainRobotMotion();

    rclcpp::shutdown();
    

    return 0;
}