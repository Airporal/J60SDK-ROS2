#include "Mymaster.hpp"

J60Master::J60Master(std::string node_name) : Node(node_name) {
    RCLCPP_INFO(this->get_logger(), "启动J60Master节点:%s", node_name.c_str());
    this->open_can_device();
    RCLCPP_INFO(this->get_logger(), "设备已经打开");
    timer_ = this->create_wall_timer(std::chrono::milliseconds(1000), std::bind(&J60Master::timer_callback, this));
    RCLCPP_INFO(this->get_logger(), "开始监听指令");
    motor_master_sub_ = this->create_subscription<j60interfaces::msg::MoveJ60>("MotorMoveOrder", 10, std::bind(&J60Master::motor_master_sub_callback_, this, std::placeholders::_1));
    RCLCPP_INFO(this->get_logger(), "开始发布状态");
    motor_master_public_ = this->create_publisher<j60interfaces::msg::StateJ60>("MotorMoveState", 10);
}

void J60Master::move_motor(DrMotorCan *can, MotorCMD *motor_cmd, int motor_id, MotorDATA *motor_data,float position, float velocity, float torque, float kp, float kd)
{
    int ret = 0;
    struct can_frame state_frame;
    SetMotionCMD(motor_cmd, motor_id, CONTROL_MOTOR,position,velocity,torque,kp,kd);
    ret = SendRecv(can, motor_cmd, motor_data,&state_frame);
    RCLCPP_INFO(this->get_logger(),"can_ID:%d, MotorDlc:%d, Position:%.2f, Velocity:%.2f, Torque:%.2f, kp:%.2f, kd:%.2f, ret:%d\n", motor_id, state_frame.can_dlc, position, velocity, torque, kp, kd, ret);
    CheckSendRecvError(motor_id, ret);
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
}

// 循环控制电机运动,并保存控制指令
void J60Master::motor_master_sub_callback_(const j60interfaces::msg::MoveJ60::SharedPtr msg)
{
    float position = msg->position;
    float velocity = msg->velocity;
    float torque = msg->torque; 
    float kp = msg->kp;
    float kd = msg->kd;
    this->move_motor(this->can, this->motor_cmd, this->motor_id, this->motor_data, position, velocity, torque, kp, kd);

}
// 定时发布状态信息
void J60Master::timer_callback()
{   

    MotorCMD *motor_cmd_timer = MotorCMDCreate();
    MotorDATA *motor_data_timer = MotorDATACreate();
    SetNormalCMD(motor_cmd_timer, this->param.motor_id, GET_STATUS_WORD);
    // state_frame结构体用来储存读取的状态信息
    struct can_frame state_frame;

    // 填充控制指令
    j60interfaces::msg::StateJ60 message;
    int ret = SendRecv(this->param.can, motor_cmd_timer, motor_data_timer, &state_frame);
    CheckSendRecvError(this->param.motor_id, ret);
    CheckMotorError(this->param.motor_id, motor_data->error_);


    message.motor_id = motor_data_timer->motor_id_;
    message.cmd = motor_data_timer->cmd_;
    message.position = motor_data_timer->position_;
    message.flag = motor_data_timer->flag_;
    message.velocity = motor_data_timer->velocity_;
    message.temp = motor_data_timer->temp_;
    message.torque = motor_data_timer->torque_;

    // 解析状态信息
    // this->data_parse(&state_frame, message);
    // 发布消息
    this->motor_master_public_->publish(message);
    MotorCMDDestroy(motor_cmd_timer);
    MotorDATADestroy(motor_data_timer);
 
}

// void J60Master::data_parse(struct can_frame * state_frame,j60interfaces::msg::StateJ60::SharedPtr messages){
//     uint16_t position_raw = ((uint8_t)(state_frame->data[1]) << 8) | (uint8_t)(state_frame->data[0]);
//     float position = ((float)position_raw * 80.0 / 65535.0) - 40.0;

//     // 解析速度（14位无符号整数）
//     uint16_t velocity_raw = ((((uint8_t)(state_frame->data[3])) & 0x3F) << 8) | (uint8_t)(state_frame->data[2]); 
//     float velocity = (float)velocity_raw / 2.0;

//     // 解析刚度（10位无符号整数）
//     uint16_t kp_raw = ((uint8_t)(state_frame->data[4]) << 2) | (((uint8_t)(state_frame->data[3]) >> 6) & 0x03);
//     uint16_t kp = kp_raw; // 刚度是整数，直接使用

//     // 解析阻尼（8位无符号整数）
//     uint8_t kd = (uint8_t)(state_frame->data[5]);

//     // 解析力矩（16位无符号整数）
//     uint16_t torque = ((uint8_t)(state_frame->data[7]) << 8) | (uint8_t)(state_frame->data[6]); // 力矩可能是有符号数

//     messages->can_id = state_frame->can_id;
//     messages->can_dlc = state_frame->can_dlc;
//     messages->code_line = "";
//     for (int i = 0; i < 8; i++)
//     {
//         messages->code_line += std::to_string(state_frame->data[i]) + " ";
//     }
//     messages->position = position;
//     messages->velocity = velocity;
//     messages->torque = static_cast<float>(torque);
//     messages->kp = static_cast<float>(kp);
//     messages->kd = static_cast<float>(kd);
// }

volatile sig_atomic_t break_flag = 0;
void sigint_handler(int sig){
    (void)sig;
    break_flag = 1;
}

void J60Master::open_can_device()
{
    // 打开can设备
    signal(SIGINT, sigint_handler);

    this->can = DrMotorCanCreate("can0", true);

    this->motor_cmd = MotorCMDCreate();

    this->motor_data = MotorDATACreate();

    // 使能关节
    this->motor_id = 0;
    SetNormalCMD(this->motor_cmd, this->motor_id, ENABLE_MOTOR);
    SendRecv(this->can, this->motor_cmd, this->motor_data);
    this->param.can = this->can;
    this->param.motor_id = this->motor_id;                                                             
}

J60Master::~J60Master()
{
    // 失能关节
    SetNormalCMD(this->motor_cmd, this->motor_id, DISABLE_MOTOR);
    SendRecv(this->can, this->motor_cmd, this->motor_data);

    // 回收资源
    DrMotorCanDestroy(this->can);
    MotorCMDDestroy(this->motor_cmd);
    MotorDATADestroy(this->motor_data);

    RCLCPP_INFO(this->get_logger(), "Ended single motor control\r\n");
}