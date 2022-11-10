/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-10 17:26:49
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-10 18:17:02
 * @FilePath: \RS_AS2\Tools\Motor\MotorExample.ino
 * @Description:
 *
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */
#include "Motor.h"

Motor motor;

void setup()
{
    Serial.begin(9600);
    delay(1);
    Serial.println("***RESET***");
    motor.init();
}
void loop()
{
    motor.setPower(10,10);
    delay(100);
}
