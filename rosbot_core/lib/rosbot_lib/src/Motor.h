#ifndef MOTOR_H
#define MOTOR_H

#include "Arduino.h"
#include "Pinout.h"

#define LEFT 0
#define RIGHT 1

#define ENCODER_CPR 12
#define WHEEL_DIAMETER 0.032
#define GEAR_RATIO 100.37004662

/**
 * @brief Motor class.
 * 
 */
class Motor
{
public:
    Motor();
    void begin(int motor, float gear_ratio, bool reverse_direction, void (*f_A)(void), void (*f_B)(void));

    void setVoltage(float u);
    void setSpeed(float w);
    void setEncoderCountA();
    void setEncoderCountB();

    void setSpeedKp(float kp);
    void setSpeedKi(float ki);
    void setSpeedKd(float kd);
    void setSpeedILimit(float limit);

    float getVoltage();
    float getSpeed();
    float getCurrent();

private:
    bool _reverse_direction = false;
    int _motor = 0;

    //pwm
    const int _pwm_freq = 22000;                           // Hz
    const int _pwm_resolution = 10;                        // bit
    const int _pwm_value_max = (1 << _pwm_resolution) - 1; // 1
    int _pwm_value = 0;

    //voltage
    const float _supply_voltage = 5.0f; // V
    float _voltage = 0.0f;              // V

    //current
    const int _adc_current_resolution = 12;                                // bit
    const int _adc_current_value_max = (1 << _adc_current_resolution) - 1; // 1

    //connections
    int _channel_A;
    int _channel_B;
    int _motor_A_pin;
    int _motor_B_pin;
    int _current_pin;
    int _encoder_pin_A;
    int _encoder_pin_B;

    //PID

    float _speed = 0.0f; // m/s

    float _kp = 10.0f;
    float _ki = 100.0f;
    float _kd = 0.4f;

    float _error_integral = 0.0f;
    float _error_integral_limit = _supply_voltage / _ki;
    float _error_previous = 0.0f;

    //encoder
    volatile int _encoder_count = 0;
    const int _encoder_count_min = 24;
    ulong _encoder_count_start = 0;
    float _encoder_distance_increment;

    //time
    float _us = 0.000001f;
    ulong _motor_last = 0;
    float _motor_timeout = 0.1f;
    float _encoder_timeout = 0.1f;
};

#endif
