#include "deep_motor_sdk.h"


uint32_t FloatToUint(const float x, const float x_min, const float x_max, const uint8_t bits){
    /// Converts a float to an unsigned int, given range and number of bits ///
    float span = x_max - x_min;
    float offset = x_min;
    return (uint32_t)((x-offset)*((float)((1<<bits)-1))/span);
}
float UintToFloat(const int x_int, const float x_min, const float x_max, const uint8_t bits){
    /// converts unsigned int to float, given range and number of bits ///
    float span = x_max - x_min;
    float offset = x_min;
    return ((float)x_int)*span/((float)((1<<bits)-1)) + offset;
}

void CheckSendRecvError(uint8_t motor_id, int code){
    switch (code)
    {
    case kNoSendRecvError:
        break;
    case kSendLengthError:
        printf("[ERROR] Motor with id %d kSendLengthError\r\n", (uint32_t)motor_id);
        break;
    case kRecvTimeoutError:
        printf("[WARN] Motor with id %d kRecvTimeoutError\r\n", (uint32_t)motor_id);
        break;
    case kRecvEpollError:
        printf("[ERROR] Motor with id %d kRecvEpollError\r\n", (uint32_t)motor_id);
        break;
    case kRecvLengthError:
        printf("[ERROR] Motor with id %d kRecvLengthError\r\n", (uint32_t)motor_id);
        break;        
    default:
        break;
    }
}

void CheckMotorError(uint8_t motor_id, uint16_t code){
    if(code != kMotorNoError){
        if(code & kOverVoltage){
            printf("[ERROR] Motor with id: %d kOverVoltage\r\n", (uint32_t)motor_id);
        }
        if(code & kUnderVoltage){
            printf("[ERROR] Motor with id: %d kUnderVoltage\r\n", (uint32_t)motor_id);
        }
        if(code & kOverCurrent){
            printf("[ERROR] Motor with id: %d kOverCurrent\r\n", (uint32_t)motor_id);
        }
        if(code & kMotorOverTemp){
            printf("[ERROR] Motor with id: %d kMotorOverTemp\r\n", (uint32_t)motor_id);
        }
        if(code & kDriverOverTemp){
            printf("[ERROR] Motor with id: %d kDriverOverTemp\r\n", (uint32_t)motor_id);
        }
        if(code & kCanTimeout){
            printf("[ERROR] Motor with id: %d kCanTimeout\r\n", (uint32_t)motor_id);
        }
    }
}

MotorDATA *MotorDATACreate(){
    MotorDATA *motor_data = (MotorDATA*)malloc(sizeof(MotorDATA));
    motor_data->error_ = kMotorNoError;
    return motor_data;
}

void MotorDATADestroy(MotorDATA *motor_data){
    free(motor_data);
}

MotorCMD *MotorCMDCreate(){
    MotorCMD *motor_cmd = (MotorCMD*)malloc(sizeof(MotorCMD));
    return motor_cmd;
}

void SetNormalCMD(MotorCMD *motor_cmd, uint8_t motor_id, uint8_t cmd){
    motor_cmd->motor_id_ = motor_id;
    motor_cmd->cmd_ = cmd;
}

void SetMotionCMD(MotorCMD *motor_cmd, uint8_t motor_id, uint8_t cmd, float position, float velocity, float torque, float kp, float kd){
    motor_cmd->motor_id_ = motor_id;
    motor_cmd->cmd_ = cmd;
    motor_cmd->position_ = position;
    motor_cmd->velocity_ = velocity;
    motor_cmd->torque_ = torque;
    motor_cmd->kp_ = kp;
    motor_cmd->kd_ = kd;
}

void MotorCMDDestroy(MotorCMD *motor_cmd){
    free(motor_cmd);
}


void parse_motor_data(u_int8_t *data){
    // 解析位置（16位无符号整数）
    uint16_t position_raw = (data[1] << 8) | data[0];
    double position = ((double)position_raw * 80.0 / 65535.0) - 40.0;

    // 解析速度（14位无符号整数）
    uint16_t velocity_raw = ((data[3] & 0x3F) << 8) | data[2]; 
    double velocity = (double)velocity_raw / 2.0;

    // 解析刚度（10位无符号整数）
    uint16_t kp_raw = (data[4] << 2) | ((data[3] >> 6) & 0x03);
    uint16_t kp = kp_raw; // 刚度是整数，直接使用

    // 解析阻尼（8位无符号整数）
    uint8_t kd = data[5];

    // 解析力矩（16位无符号整数）
    uint16_t torque = (data[7] << 8) | data[6]; // 力矩可能是有符号数

    // 打印解析后的数据
    printf("位置: %.2f\n", position);
    printf("速度: %.2f\n", velocity);
    printf("刚度: %u\n", kp);
    printf("阻尼: %u\n", kd);
    printf("力矩: %d\n", torque);
}

void FloatsToUints(const MotorCMD *param, uint8_t *data)
{
    // 将十进制的弧度指令映射到16位保存。data[]uint8_t数组中的每个元素都是一个字节，所以需要将16位的数据分成两个字节
    uint16_t _position = FloatToUint(param->position_, POSITION_MIN, POSITION_MAX, SEND_POSITION_LENGTH);
    uint16_t _velocity = FloatToUint(param->velocity_, VELOCITY_MIN, VELOCITY_MAX, SEND_VELOCITY_LENGTH);
    uint16_t _torque = FloatToUint(param->torque_, TORQUE_MIN, TORQUE_MAX, SEND_TORQUE_LENGTH);
    uint16_t _kp = FloatToUint(param->kp_, KP_MIN, KP_MAX, SEND_KP_LENGTH);
    uint16_t _kd = FloatToUint(param->kd_, KD_MIN, KD_MAX, SEND_KD_LENGTH);
    data[0] = _position;
    data[1] = _position >> 8;
    
    data[2] = _velocity;
    data[3] = ((_velocity >> 8) & 0x3f)| ((_kp & 0x03) << 6);
    data[4] = _kp >> 2;
    data[5] = _kd;
    data[6] = _torque;
    data[7] = _torque >> 8;
    parse_motor_data(data);
}


void UintsToFloats(const struct can_frame *frame, MotorDATA *data)
{
    const ReceivedMotionData *pcan_data = (const ReceivedMotionData*)frame->data;
    data->position_ = UintToFloat(pcan_data->position, POSITION_MIN, POSITION_MAX, RECEIVE_POSITION_LENGTH);
    data->velocity_ = UintToFloat(pcan_data->velocity, VELOCITY_MIN, VELOCITY_MAX, RECEIVE_VELOCITY_LENGTH);
    data->torque_ = UintToFloat(pcan_data->torque, TORQUE_MIN, TORQUE_MAX, RECEIVE_TORQUE_LENGTH);
    data->flag_ = (bool)pcan_data->temp_flag;
    if(data->flag_ == kMotorTempFlag){
        data->temp_ = UintToFloat(pcan_data->temperature, MOTOR_TEMP_MIN, MOTOR_TEMP_MAX, RECEIVE_TEMP_LENGTH);
    }
    else{
        data->temp_ = UintToFloat(pcan_data->temperature, DRIVER_TEMP_MIN, DRIVER_TEMP_MAX, RECEIVE_TEMP_LENGTH);
    }
}

uint16_t FormCanId(uint8_t cmd, uint8_t motor_id){
    return (cmd << CAN_ID_SHIFT_BITS) | motor_id;
}

void MakeSendFrame(const MotorCMD *cmd, struct can_frame *frame_ret){
    frame_ret->can_id = FormCanId(cmd->cmd_, cmd->motor_id_);
    switch (cmd->cmd_)
    {
    case ENABLE_MOTOR:
        frame_ret->can_dlc = SEND_DLC_ENABLE_MOTOR;
        break;

    case DISABLE_MOTOR:
        frame_ret->can_dlc = SEND_DLC_DISABLE_MOTOR;
        break;

    case SET_HOME:
        frame_ret->can_dlc = SEND_DLC_SET_HOME;
        break;

    case ERROR_RESET:
        frame_ret->can_dlc = SEND_DLC_ERROR_RESET;
        break;

    case CONTROL_MOTOR:
        frame_ret->can_dlc = SEND_DLC_CONTROL_MOTOR;
        FloatsToUints(cmd, frame_ret->data);
        break;

    case GET_STATUS_WORD:
        frame_ret->can_dlc = SEND_DLC_GET_STATUS_WORD;
        break;

    default:
        break;
    }
}
// 传入收到的Can帧，解析出Motor数据
void ParseRecvFrame(const struct can_frame *frame_ret, MotorDATA *data){
    uint32_t frame_id = frame_ret->can_id;
    uint32_t cmd = (frame_id >> CAN_ID_SHIFT_BITS) & 0x3f;
    uint32_t motor_id = frame_id & 0x0f;
    data->motor_id_ = motor_id;
    data->cmd_ = cmd; 
    switch (cmd)
    {
    case ENABLE_MOTOR:
        printf("[INFO] Motor with id: %d enable success\r\n", (uint32_t)motor_id);
        break;

    case DISABLE_MOTOR:
        printf("[INFO] Motor with id: %d disable success\r\n", (uint32_t)motor_id);
        break;

    case SET_HOME:
        printf("[INFO] Motor with id: %d set zero point success\r\n", (uint32_t)motor_id);
        break;

    case ERROR_RESET:
        printf("[INFO] Motor with id: %d clear error success\r\n", (uint32_t)motor_id);
        break;

    case CONTROL_MOTOR:
        UintsToFloats(frame_ret, data);
        break;    

    case GET_STATUS_WORD:
        data->error_ = (frame_ret->data[0] << 8) | frame_ret->data[1];
        break;

    default:
        printf("[WARN] Received a frame not fitting into any cmd\r\n");
        break;
    }
}

DrMotorCan* DrMotorCanCreate(const char *can_name, bool is_show_log){
    DrMotorCan* can = (DrMotorCan*)malloc(sizeof(DrMotorCan));
    if(can != NULL){
        can->is_show_log_ = is_show_log;

        if((can->can_socket_ = socket(PF_CAN, SOCK_RAW, CAN_RAW)) < 0){
            printf("[ERROR] Socket creation failed\r\n");
            exit(-1);
        }

        int flags = fcntl(can->can_socket_, F_GETFL, 0);
        if(flags == -1){
            printf("[ERROR] Getting socket flags failed\r\n");
            exit(-1);
        }
        flags |= O_NONBLOCK;
        if(fcntl(can->can_socket_, F_SETFL, flags) == -1){
            printf("[ERROR] Setting socket to non-blocking mode failed\r\n");
            exit(-1);
        }

        struct ifreq ifr;
        struct sockaddr_can addr;
        strcpy(ifr.ifr_name, can_name);
        ioctl(can->can_socket_, SIOCGIFINDEX, &ifr);
        addr.can_ifindex = ifr.ifr_ifindex;
        addr.can_family = AF_CAN;
        if(bind(can->can_socket_, (struct sockaddr*)&addr, sizeof(addr)) < 0){
            printf("[ERROR] Bind failed\r\n");
            close(can->can_socket_);
            exit(-1);
        }

        can->epoll_fd_ = epoll_create1(0);
        if(can->epoll_fd_ == -1){
            printf("[ERROR] Error creating epoll instance\r\n");
            exit(-1);
        }

        struct epoll_event event;
        event.events = EPOLLIN;
        event.data.fd = can->can_socket_;
        if(epoll_ctl(can->epoll_fd_, EPOLL_CTL_ADD, can->can_socket_, &event) == -1){
            printf("[ERROR] Adding socket to epoll failed\r\n");
            exit(-1);
        }
    }
    return can;
}

void DrMotorCanDestroy(DrMotorCan *can){
    close(can->can_socket_);
    free(can);
}

int SendRecv(DrMotorCan *can, const MotorCMD *cmd, MotorDATA *data,struct can_frame * state_frame){
    struct can_frame send_frame, recv_frame;
    MakeSendFrame(cmd, &send_frame);

    struct timeval start_time;
    gettimeofday(&start_time, NULL);

    if(can->is_show_log_){
        printf("[INFO] Writing frame with can_id: %d, can_dlc: %d, data: %d, %d, %d, %d, %d, %d, %d, %d",
            send_frame.can_id, send_frame.can_dlc,
            (uint32_t)send_frame.data[0], (uint32_t)send_frame.data[1], (uint32_t)send_frame.data[2], (uint32_t)send_frame.data[3],
            (uint32_t)send_frame.data[4], (uint32_t)send_frame.data[5], (uint32_t)send_frame.data[6], (uint32_t)send_frame.data[7]
        );
        
    }
    // 写入Can总线
    pthread_mutex_lock(&can->rw_mutex);
    ssize_t nbytes1 = write(can->can_socket_, &send_frame, sizeof(send_frame));
    pthread_mutex_unlock(&can->rw_mutex);
    if(nbytes1 != sizeof(send_frame)){
        return kSendLengthError;
    }

    struct epoll_event events;
    int epoll_wait_result = epoll_wait(can->epoll_fd_, &events, 5, 3);
    if(epoll_wait_result == 0){
        return kRecvTimeoutError;
    }else if (epoll_wait_result == -1){
        return kRecvEpollError;
    }else{
        // 读取Can总线
        pthread_mutex_lock(&can->rw_mutex);
        ssize_t nbytes2 = read(can->can_socket_, &recv_frame, sizeof(recv_frame));
        pthread_mutex_unlock(&can->rw_mutex);
        if(nbytes2 != sizeof(recv_frame)){
            return kRecvLengthError;
        }

        if(can->is_show_log_){
            printf("[INFO] Reading frame with can_id: %d, can_dlc: %d, data: %d, %d, %d, %d, %d, %d, %d, %d\r\n",
                recv_frame.can_id, recv_frame.can_dlc,
                (uint32_t)recv_frame.data[0], (uint32_t)recv_frame.data[1], (uint32_t)recv_frame.data[2], (uint32_t)recv_frame.data[3],
                (uint32_t)recv_frame.data[4], (uint32_t)recv_frame.data[5], (uint32_t)recv_frame.data[6], (uint32_t)recv_frame.data[7]
            );

            struct timeval end_time;
            gettimeofday(&end_time, NULL);
            long long duration_us = (end_time.tv_sec - start_time.tv_sec) * 1000000LL +
                        (end_time.tv_usec - start_time.tv_usec);
            printf("[INFO] SendRecv() t_diff: %lld us\r\n", duration_us);
        }

        ParseRecvFrame(&recv_frame, data);
        return kNoSendRecvError;
    }

}

