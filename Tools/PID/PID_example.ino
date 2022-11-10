/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-10 16:26:44
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-10 17:26:25
 * @FilePath: \RS_AS2\Tools\PID\PID_example.ino
 * @Description:用阶跃信号类作为电机驱动的给定值，然后用PID控制电机速度的例子
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */

#include "PID.h"
#include "StepSignal.h"

PID pid;
StepSignal step;

void setup()
{
    Serial.begin(9600);
    delay(1);
    Serial.print("***RESET***");
    step.init(1000, 1);
}

void loop()
{
}
