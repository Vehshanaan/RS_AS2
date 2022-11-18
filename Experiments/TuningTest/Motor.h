/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-10 17:26:55
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-11 10:46:51
 * @FilePath: \RS_AS2\Tools\Motor\Motor.h
 * @Description:
 * 电机驱动类的实现。
 * 使用方法：
 * 1.实例化类的对象,如 Motor motor;
 * 2.在setup()中调用init()方法
 * 3.使用setPower()方法为左右轮设置速度，即可驱动电机
 * 4.使用前要先校正死区范围
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */
#ifndef MOTOR_H
#define MOTOR_H

/*
一些关于电机的备注：
1.电机PWM写负数的时候会相当于油门踩满
2.电机PWM写成小数的时候会自动取整
*/

#define L_DIR_PIN 16 // L_DIR_PIN or PN_L
#define R_DIR_PIN 15 // R_DIR_PIN or PN_R
#define L_PWM_PIN 10 // L_PWM_PIN or EN_L
#define R_PWM_PIN 9  // R_DIR_PIN or EN_R

#define FWD LOW  // LOW = 0x0
#define REV HIGH // HIGH = 0x1

class Motor
{
private:
    int LeftMotorPower = 0;  // 左侧电机当前PWM值
    int RightMotorPower = 0; // 右侧电机当前PWM值

public:
    Motor() // 构造函数，必须存在
    {
    }

    /**
     * @description: 初始化各个引脚，必须在使用电机前调用
     */
    void init()
    {
        pinMode(L_DIR_PIN, OUTPUT);
        pinMode(R_DIR_PIN, OUTPUT);
        pinMode(L_PWM_PIN, OUTPUT);
        pinMode(R_PWM_PIN, OUTPUT);
    }

    /**
     * @description: 驱动电机的方法 
     * @param {int} L 左轮速度，接受正负输入
     * @param {int} R 右轮速度，接受正负输入
     */
    void setPower(int L, int R)
    {
        // 取控制量的绝对值
        int L_temp = abs(L);
        int R_temp = abs(R);

        // 不许大于255
        if (L_temp > 255)
            L_temp = 255;
        if (R_temp > 255)
            R_temp = 255;

        // 根据输入数字的正负写电机方向
        if (L > 0)
            digitalWrite(L_DIR_PIN, FWD);
        if (L < 0)
            digitalWrite(L_DIR_PIN, REV);
        if (R > 0)
            digitalWrite(R_DIR_PIN, FWD);
        if (R < 0)
            digitalWrite(R_DIR_PIN, REV);

        // 驱动电机
        if (L == 0)
            analogWrite(L_PWM_PIN, 0);
        else
        {
            // 死区14
            LeftMotorPower = (int)(L_temp); //* 0.945 + 14); //不含校正的驱动： LeftMotorPower = (int)(L_temp);
            analogWrite(L_PWM_PIN, LeftMotorPower);
        }
        if (R == 0)
            analogWrite(R_PWM_PIN, 0);
        else
        {
            // 死区17
            RightMotorPower = (int)(R_temp);// * 0.933 + 17); //不含校正的驱动： RightMotorPower = (int)(R_temp);
            analogWrite(R_PWM_PIN, RightMotorPower);
        }
        return;
    }
};

#endif