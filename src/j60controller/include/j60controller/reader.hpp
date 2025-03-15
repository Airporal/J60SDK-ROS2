#pragma once
#include <rclcpp/rclcpp.hpp>
#include "j60interfaces/msg/move_j60.hpp"
#include "j60interfaces/msg/state_j60.hpp"
/*
    本节点负责根据SDK的接口，读取J60的状态
*/

class J60Reader:public rclcpp::Node{
public:
// 初始化节点
    J60Reader(std::string name) : Node(name){
        RCLCPP_INFO(this->get_logger(), "J60Reader node is created");
        this->motor_reader_sub_ = this->create_subscription<j60interfaces::msg::StateJ60>("MotorMoveState", 10, std::bind(&J60Reader::motor_reader_callback_, this, std::placeholders::_1));
    }
    
    ~J60Reader();

private:
    rclcpp::Subscription<j60interfaces::msg::StateJ60>::SharedPtr motor_reader_sub_;
// 订阅StateJ60数据话题并转化为十进制数打印
    void motor_reader_callback_(const j60interfaces::msg::StateJ60::SharedPtr msg);
};