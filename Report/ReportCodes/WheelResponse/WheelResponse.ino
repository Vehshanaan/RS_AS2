/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-12-01 17:21:38
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-12-01 17:28:19
 * @FilePath: \RS_AS2\Report\ReportCodes\WheelResponse\WheelResponse.ino
 * @Description: 轮子PWM值与速度关系的测试函数，包含画图
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
 */
#include "Kinematics.h"
#include "Motor.h"

Motor motor;
Kinematics ki;

void setup()
{
    Serial.begin(9600);
    delay(1000);
    Serial.println("RESET");
    setupEncoder0();
    setupEncoder1();
    motor.init();
    ki.init();
    Serial.println("speed = []");
}

volatile  int i=0;
void loop()
{
    if(i>255){motor.setPower(0,0);return;}
    ki.update();
    motor.setPower(i,0);
    delay(1000);
    ki.update();
    Serial.print("speed.append(");
    Serial.print(ki.v_l);
    Serial.println(")");
    i++;
}