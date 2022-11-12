
/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-10 17:26:49
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-11 10:57:42
 * @FilePath: \RS_AS2\Tools\MotorExample\MotorExample.ino
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
    motor.setPower(1,1);
    delay(100);
}
