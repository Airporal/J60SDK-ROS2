#include "Mymaster.hpp"


int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<J60Master>("j60_master");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}