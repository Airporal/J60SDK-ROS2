#include "reader.hpp"

int main(int argc, char **argv){
    rclcpp::init(argc, argv);
    auto node = std::make_shared<J60Reader>("j60_reader");
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;
}