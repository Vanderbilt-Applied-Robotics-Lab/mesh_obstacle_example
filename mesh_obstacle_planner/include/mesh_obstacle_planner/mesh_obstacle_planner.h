#ifndef MESH_OBSTACLE_PLANNER
#define MESH_OBSTACLE_PLANNER

#include <rclcpp/rclcpp.hpp>
#include <string>

#include <moveit_msgs/msg/collision_object.hpp>
#include <moveit_msgs/msg/display_trajectory.hpp>

#include <geometric_shapes/shape_operations.h>
#include <geometric_shapes/mesh_operations.h>

#include <shape_msgs/msg/mesh.hpp>
#include <geometry_msgs/msg/pose.hpp>

#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit/move_group_interface/move_group_interface.h>


class MeshObstaclePlanner : public rclcpp::Node
{
public:
    /**
     * Main constructor
     */
    MeshObstaclePlanner();

    /**
     * Destructor
     */
    ~MeshObstaclePlanner() = default;

    void mainRobotMotion();

    void initMoveGroup();

    void addMeshObstacle();

    bool planMotionAndVisualize(std::vector<double> & joints);

    void moveJoints();
    
private:

    moveit::planning_interface::PlanningSceneInterface psi_;

    moveit::planning_interface::MoveGroupInterface::Plan plan_;
    std::shared_ptr<moveit::planning_interface::MoveGroupInterface> move_group_;
    std::vector<double> start_joints_ = {-M_PI/2.0, M_PI/4.0,  0.0, 0.0, 0.0, 0.0};
    std::vector<double> goal_joints_ = {M_PI/2.0, M_PI/2.0,  0.0, 0.0, 0.0, 0.0};

    rclcpp::Publisher<moveit_msgs::msg::DisplayTrajectory>::SharedPtr display_pub_;
    
};

#endif // MESH_OBSTACLE_PLANNER