#include "reader.hpp"

// 打印电机状态即可,话题发布者不明确
void J60Reader::motor_reader_callback_(const j60interfaces::msg::StateJ60::SharedPtr msg){
    RCLCPP_INFO(this->get_logger(),

    "Motor ID: %d, Motor Cmd: %d, Position: %f, Velocity: %f, Torque: %f, temp: %f, flag: %d", 
    msg->motor_id, msg->cmd, 
    msg->position, msg->velocity, msg->torque, msg->temp, msg->flag);
}

J60Reader::~J60Reader(){
    RCLCPP_INFO(this->get_logger(), "J60Reader node is destroyed");
}