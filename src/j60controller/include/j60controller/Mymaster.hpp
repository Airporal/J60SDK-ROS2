#ifndef MYMASTER_HPP
#define MYMASTER_HPP
#include <rclcpp/rclcpp.hpp>
#include "j60interfaces/msg/move_j60.hpp"
#include "j60interfaces/msg/state_j60.hpp"

extern "C" {
    #include "deep_motor_sdk.h"
}
/*
    本节点负责使用Can总线控制J60运动，根据SDK提供的接口，通过发布订阅的方式控制J60的运动
    订阅MoveJ60消息，获取运动指令，并将指令发送给Can总线控制J60运动
*/

class J60Master:public rclcpp::Node{
public:
// 初始化节点
    J60Master(std::string node_name);


// 根据运动指令使用SDK控制J60运动

    void move_motor(DrMotorCan *can, MotorCMD *motor_cmd, int motor_id, MotorDATA *motor_data,float position, float velocity, float torque, float kp, float kd);
    ~J60Master();
private:
    DrMotorCan *can;
    MotorCMD *motor_cmd;
    MotorDATA *motor_data;
    MotorCheckThreadParam param;
    uint8_t motor_id;
    

// 订阅MoveJ60消息,转化为SDK的控制指令
    rclcpp::Subscription<j60interfaces::msg::MoveJ60>::SharedPtr motor_master_sub_;
// 控制J60运动并发布StateJ60消息,表示J60的运动状态控制指令
    rclcpp::Publisher<j60interfaces::msg::StateJ60>::SharedPtr motor_master_public_;
// 每隔一秒钟检查一次关节状态,并发布StateJ60消息
    rclcpp::TimerBase::SharedPtr timer_;

    
    void motor_master_sub_callback_(const j60interfaces::msg::MoveJ60::SharedPtr msg);
    void timer_callback();
    // void data_parse(struct can_frame * state_frame,j60interfaces::msg::StateJ60::SharedPtr message);
// 打开can设备
    void open_can_device();
    
    
};

extern volatile sig_atomic_t break_flag;
void sigint_handler(int sig);


#endif