#ifndef DEEP_MOTOR_SDK_H
#define DEEP_MOTOR_SDK_H
#ifdef __cplusplus
extern "C" {
#endif

#include <signal.h>
#include <unistd.h>
#include <net/if.h>
#include <sys/ioctl.h>
#include <sys/epoll.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdio.h>
#include <linux/can/raw.h>
#include <sys/time.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define CAN_ID_SHIFT_BITS 5

#define POSITION_MIN -40.0f
#define POSITION_MAX 40.0f
#define VELOCITY_MIN -40.0f
#define VELOCITY_MAX 40.0f
#define KP_MIN 0.0f
#define KP_MAX 1023.0f
#define KD_MIN 0.0f
#define KD_MAX 51.0f
#define TORQUE_MIN -40.0f
#define TORQUE_MAX 40.0f

#define GEAR_RATIO_MIN 0.0f
#define GEAR_RATIO_MAX 50.0f

#define MOTOR_TEMP_MIN -20.0f
#define MOTOR_TEMP_MAX 200.0f
#define DRIVER_TEMP_MIN -20.0f
#define DRIVER_TEMP_MAX 200.0f
#define CURRENT_MIN 0.0f
#define CURRENT_MAX 40.0f

#define SEND_POSITION_LENGTH 16
#define SEND_VELOCITY_LENGTH 14
#define SEND_KP_LENGTH 10
#define SEND_KD_LENGTH 8
#define SEND_TORQUE_LENGTH 16
#define SEND_GEAR_RATIO_LENGTH 16
#define SEND_LIMIT_CURRENT_LENGTH 16

#define RECEIVE_POSITION_LENGTH 20
#define RECEIVE_VELOCITY_LENGTH 20
#define RECEIVE_TORQUE_LENGTH 16
#define RECEIVE_TEMP_FLAG_LENGTH 1
#define RECEIVE_TEMP_LENGTH 7

#define ERROR_CODE_LENGTH 16
#define ERROR_VOLTAGE_LENGTH 16
#define ERROR_CURRENT_LENGTH 16
#define ERROR_MOTOR_TEMP_LENGTH 8
#define ERROR_DRIVER_TEMP_LENGTH 8



// Commands
#define DISABLE_MOTOR 1
#define ENABLE_MOTOR 2
#define CALIBRATE_START 3
#define CONTROL_MOTOR 4
#define RESET_MOTOR 5
#define SET_HOME 6
#define SET_GEAR 7
#define SET_ID 8
#define SET_CAN_TIMEOUT 9
#define SET_BANDWIDTH 10
#define SET_LIMIT_CURRENT 11
#define SET_UNDER_VOLTAGE 12
#define SET_OVER_VOLTAGE 13
#define SET_MOTOR_TEMPERATURE 14
#define SET_DRIVE_TEMPERATURE 15
#define SAVE_CONFIG 16
#define ERROR_RESET 17
#define WRITE_APP_BACK_START 18
#define WRITE_APP_BACK 19
#define CHECK_APP_BACK 20
#define DFU_START 21
#define GET_FW_VERSION 22
#define GET_STATUS_WORD 23
#define GET_CONFIG 24
#define CALIB_REPORT 31



// SendDLC
#define SEND_DLC_DISABLE_MOTOR 0
#define SEND_DLC_ENABLE_MOTOR 0
#define SEND_DLC_CALIBRATE_START 0
#define SEND_DLC_CONTROL_MOTOR 8
#define SEND_DLC_RESET_MOTOR 0
#define SEND_DLC_SET_HOME 0
#define SEND_DLC_SET_GEAR 2
#define SEND_DLC_SET_ID 1
#define SEND_DLC_SET_CAN_TIMEOUT 1
#define SEND_DLC_SET_BANDWIDTH 2
#define SEND_DLC_SET_LIMIT_CURRENT 2
#define SEND_DLC_SET_UNDER_VOLTAGE 2
#define SEND_DLC_SET_OVER_VOLTAGE 2
#define SEND_DLC_SET_MOTOR_TEMPERATURE 2
#define SEND_DLC_SET_DRIVE_TEMPERATURE 2
#define SEND_DLC_SAVE_CONFIG 0
#define SEND_DLC_ERROR_RESET 0
#define SEND_DLC_WRITE_APP_BACK_START 0
#define SEND_DLC_WRITE_APP_BACK 8
#define SEND_DLC_CHECK_APP_BACK 8
#define SEND_DLC_DFU_START 0
#define SEND_DLC_GET_FW_VERSION 0
#define SEND_DLC_GET_STATUS_WORD 0
#define SEND_DLC_GET_CONFIG 0
#define SEND_DLC_CALIB_REPORT 8



// ReceiveDLC
#define RECEIVE_DLC_DISABLE_MOTOR 1
#define RECEIVE_DLC_ENABLE_MOTOR 1
#define RECEIVE_DLC_CALIBRATE_START 1
#define RECEIVE_DLC_CONTROL_MOTOR 8
#define RECEIVE_DLC_RESET_MOTOR 1
#define RECEIVE_DLC_SET_HOME 1
#define RECEIVE_DLC_SET_GEAR 2
#define RECEIVE_DLC_SET_ID 1
#define RECEIVE_DLC_SET_CAN_TIMEOUT 1
#define RECEIVE_DLC_SET_BANDWIDTH 1
#define RECEIVE_DLC_SET_LIMIT_CURRENT 1
#define RECEIVE_DLC_SET_UNDER_VOLTAGE 1
#define RECEIVE_DLC_SET_OVER_VOLTAGE 1
#define RECEIVE_DLC_SET_MOTOR_TEMPERATURE 1
#define RECEIVE_DLC_SET_DRIVE_TEMPERATURE 1
#define RECEIVE_DLC_SAVE_CONFIG 1
#define RECEIVE_DLC_ERROR_RESET 1
#define RECEIVE_DLC_WRITE_APP_BACK_START 1
#define RECEIVE_DLC_WRITE_APP_BACK 1
#define RECEIVE_DLC_CHECK_APP_BACK 2
#define RECEIVE_DLC_DFU_START 1
#define RECEIVE_DLC_GET_FW_VERSION 2
#define RECEIVE_DLC_GET_STATUE_WORD 5
#define RECEIVE_DLC_GET_CONFIG 8
#define RECEIVE_DLC_CALIB_REPORT 8
typedef union SendMotionData
{
    uint8_t data[8];
    struct 
    {
        uint32_t position : SEND_POSITION_LENGTH;
        uint32_t velocity : SEND_VELOCITY_LENGTH;
        uint32_t kp : SEND_KP_LENGTH;
        uint32_t kd : SEND_KD_LENGTH;
        uint32_t torque : SEND_TORQUE_LENGTH;
    };
}SendMotionData;

typedef union ReceivedMotionData
{
    uint8_t data[8];
    struct 
    {
        uint32_t position : RECEIVE_POSITION_LENGTH;
        uint32_t velocity : RECEIVE_VELOCITY_LENGTH;
        uint32_t torque : RECEIVE_TORQUE_LENGTH;
        uint32_t temp_flag : RECEIVE_TEMP_FLAG_LENGTH;
        uint32_t temperature : RECEIVE_TEMP_LENGTH;
    };
}ReceivedMotionData;

typedef union ReceivedErrorData
{
    uint8_t data[8];
    struct 
    {
        uint16_t error_code : ERROR_CODE_LENGTH;
        uint16_t voltage : ERROR_VOLTAGE_LENGTH;
        uint16_t current : ERROR_CURRENT_LENGTH;
        uint8_t motor_temp : ERROR_MOTOR_TEMP_LENGTH;
        uint8_t driver_temp : ERROR_DRIVER_TEMP_LENGTH;
    };
}ReceivedErrorData;

enum Temp_Flag{
    kDriverTempFlag=0,
    kMotorTempFlag=1
};

enum SendRecvRet{
    kNoSendRecvError = 0,
    kSendLengthError = -1,
    kRecvTimeoutError = -2,
    kRecvEpollError = -3,
    kRecvLengthError = -4
};


enum MotorErrorType{
    kMotorNoError = 0,
    kOverVoltage = (0x01 << 0),
    kUnderVoltage = (0x01 << 1),
    kOverCurrent = (0x01 << 2),
    kMotorOverTemp = (0x01 << 3),
    kDriverOverTemp = (0x01 << 4),
    kCanTimeout = (0x01 << 5)
};

typedef struct{
    bool is_show_log_;
    int can_socket_;
    int epoll_fd_;
    pthread_mutex_t rw_mutex;
}DrMotorCan;

typedef struct
{
    uint8_t motor_id_;
    uint8_t cmd_;
    float position_;
    float velocity_;
    float torque_;
    bool flag_;
    float temp_;
    uint16_t error_;
}MotorDATA;

typedef struct
{
    uint8_t motor_id_;
    uint8_t cmd_;
    float position_;
    float velocity_;
    float torque_;
    float kp_;
    float kd_;
}MotorCMD;

typedef struct{
    DrMotorCan *can;
    uint8_t motor_id;
}MotorCheckThreadParam;



// volatile sig_atomic_t break_flag = 0;

uint32_t FloatToUint(const float x, const float x_min, const float x_max, const uint8_t bits);
float UintToFloat(const int x_int, const float x_min, const float x_max, const uint8_t bits);
MotorDATA *MotorDATACreate();
void MotorDATADestroy(MotorDATA *motor_data);
void CheckSendRecvError(uint8_t motor_id, int code);
void CheckMotorError(uint8_t motor_id, uint16_t code);
MotorCMD *MotorCMDCreate();
void SetNormalCMD(MotorCMD *motor_cmd, uint8_t motor_id, uint8_t cmd);
void SetMotionCMD(MotorCMD *motor_cmd, uint8_t motor_id, uint8_t cmd, float position, float velocity, float torque, float kp, float kd);
void MotorCMDDestroy(MotorCMD *motor_cmd);
void parse_motor_data(u_int8_t *data);
void FloatsToUints(const MotorCMD *param, uint8_t *data);
void UintsToFloats(const struct can_frame *frame, MotorDATA *data);
uint16_t FormCanId(uint8_t cmd, uint8_t motor_id);
void MakeSendFrame(const MotorCMD *cmd, struct can_frame *frame_ret);
void ParseRecvFrame(const struct can_frame *frame_ret, MotorDATA *data);
DrMotorCan* DrMotorCanCreate(const char *can_name, bool is_show_log);
void DrMotorCanDestroy(DrMotorCan *can);
int SendRecv(DrMotorCan *can, const MotorCMD *cmd, MotorDATA *data,struct can_frame * state_frame=NULL);
// int ReadRecv(DrMotorCan *can, const MotorCMD *cmd, MotorDATA *data,struct can_frame * state_frame=NULL);
// void sigint_handler(int sig);




#ifdef __cplusplus
}
#endif

#endif // DEEP_MOTOR_SDK_H