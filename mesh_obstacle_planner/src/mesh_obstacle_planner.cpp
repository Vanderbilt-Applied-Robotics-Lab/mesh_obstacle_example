#include <mesh_obstacle_planner/mesh_obstacle_planner.h>

MeshObstaclePlanner::MeshObstaclePlanner() : Node("mesh_obstacle_planner")
{
    display_pub_ = this->create_publisher<moveit_msgs::msg::DisplayTrajectory>("/display_planned_path", 10);
}


void MeshObstaclePlanner::mainRobotMotion()
{

    initMoveGroup();

    bool success = planMotionAndVisualize(start_joints_);

    rclcpp::sleep_for(std::chrono::seconds(3)); // wait for visualization
    if (success)
    {
        moveJoints();
    }

    addMeshObstacle();

    success = planMotionAndVisualize(goal_joints_);
    rclcpp::sleep_for(std::chrono::seconds(5)); // wait for visualization
    if (success)
    {
        moveJoints();
    }
}

void MeshObstaclePlanner::initMoveGroup()
{
    // initialize movegroup
    move_group_ = std::make_shared<moveit::planning_interface::MoveGroupInterface>(
            shared_from_this(), "rv_3s_arm");

    move_group_->setNumPlanningAttempts(1000);
    move_group_->setPlanningTime(300.0);

}


void MeshObstaclePlanner::addMeshObstacle()
{
    moveit_msgs::msg::CollisionObject obj;
    obj.header.frame_id = "world";
    obj.id = "mesh_obstacle";

    const std::string mesh_resource =
        "package://mesh_obstacle_planner/meshes/obstacle.stl";

    std::unique_ptr<shapes::Mesh> mesh(
        shapes::createMeshFromResource(mesh_resource));

    if (!mesh)
    {
        RCLCPP_ERROR(this->get_logger(), "Failed to load mesh");
        return;
    }

    shapes::ShapeMsg shape_msg;
    shapes::constructMsgFromShape(mesh.get(), shape_msg);

    shape_msgs::msg::Mesh mesh_msg =
        boost::get<shape_msgs::msg::Mesh>(shape_msg);


    geometry_msgs::msg::Pose pose;
    pose.position.x = 0.200;
    pose.position.y = 0.0;
    pose.position.z = 0.100;
    pose.orientation.w = 0.7071068;
    pose.orientation.x = 0.7071068;
    pose.orientation.y = 0.0;
    pose.orientation.z = 0.0;

    obj.meshes.push_back(mesh_msg);
    obj.mesh_poses.push_back(pose);
    obj.operation = obj.ADD;

    psi_.applyCollisionObject(obj);

    RCLCPP_INFO(this->get_logger(), "Mesh obstacle added");
}

bool MeshObstaclePlanner::planMotionAndVisualize(std::vector<double> & joints)
{
    // message to display trajectory
    moveit_msgs::msg::DisplayTrajectory display_msg;
    
    // set movegroup to target joint angles
    move_group_->setJointValueTarget(joints);

    // if move plan succeeded, move robot
    if (move_group_->plan(plan_) == moveit::core::MoveItErrorCode::SUCCESS)
    {
        display_msg.trajectory_start = plan_.start_state_;
        display_msg.trajectory.push_back(plan_.trajectory_);
        display_pub_->publish(display_msg);

        return true;
    }
    else // print error otherwise
    {
        RCLCPP_INFO(this->get_logger(), "Plan failed");
        return false;
    }
}

void MeshObstaclePlanner::moveJoints()
{
    move_group_->execute(plan_);
}

int main(int argc, char** argv)
{
    rclcpp::init(argc, argv);

    auto node = std::make_shared<MeshObstaclePlanner>();

    node->mainRobotMotion();

    rclcpp::shutdown();
    

    return 0;
}