/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-10 16:26:44
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-13 19:35:28
 * @FilePath: \RS_AS2\Tools\PID_example\PID_example.ino
 * @Description:用阶跃信号类作为电机驱动的给定值，然后用PID控制电机速度的例子
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */

#include "PID.h"
#include "Kinematics.h"
#include "StepSignal.h"
#include "Motor.h"

Kinematics ki;
Motor motor;
PID pid_lspeed;
StepSignal step;

void setup()
{
    Serial.begin(9600);
    delay(1);
    Serial.print("***RESET***");
    setupEncoder0();
    setupEncoder1();
    ki.init();
    motor.init();
    pid_lspeed.init(2, 1, 0.2, 500, 500); // P,I,D,积分限幅值（暂时没用，只是占位符），PID更新时间间隔（单位毫秒），系统本身能做到的最快的速度也就是500微秒更新一次
    /*
    笔记：
    1. PID更新时间间隔为500（接近自然极限）的时候是不太震荡的
    */
    step.init(3000, 0.2); 
}

void loop()
{
    ki.update();
    step.update();

    if (step.value == 0) // 如果是阶跃信号值为0的时候:
    {
        pid_lspeed.reset();   // 一直reset pid，相当于关闭pid
        motor.setPower(0, 0); // 停机
    }
    else
    {                                         // 若阶跃信号的值现在不为0：
        pid_lspeed.aim = step.value;          // 将阶跃信号的值设为速度控制PID的追踪对象
        pid_lspeed.cal(ki.v_l);               // 根据当前速度计算PID控制值
        motor.setPower(pid_lspeed.result, 0); // 用PID结果控制电机
        Serial.println(pid_lspeed.I);
    }
}
