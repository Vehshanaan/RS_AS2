/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-24 13:18:13
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-25 09:38:19
 * @FilePath: \RS_AS2\Experiments\Week9Experiments\PID_AutoTest\PID_AutoTest.ino
 * @Description:
 *
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */

#include "PIDAutoEvaluate.h"

void setup()
{
    Serial.begin(9600);
    delay(1000);
    Serial.println("RESET");
}

void loop()
{
    double para[2];
    int delay_value = 10;
    double Kp=35;
    double Ki = 2.5;
    double Kd = 5.0;
    int times = 10; // 测试十次
    PIDEvaluate(delay_value,Kp,Ki,Kd,times,para,100*delay_value); // 最后这个乘以100表示step的周期是100个delay，如果设得太短来不及收敛，我的函数会认定这是震荡。所以请留一点余地。
    Serial.print("overshoot:");
    Serial.println(para[0]);
    Serial.print("setting:");
    Serial.println(para[1]);
    delay(1000000);
}