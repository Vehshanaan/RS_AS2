/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-11 10:59:01
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-12 16:03:15
 * @FilePath: \RS_AS2\Tools\KinematicsExample\KinematicsExample.ino
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
 */
#include "Kinematics.h"

Kinematics ki;

void setup()
{
    Serial.begin(9600);
    delay(1);
    Serial.println("***RESET***");
    setupEncoder0();
    setupEncoder1();
    ki.init();

}
void loop()
{
    ki.update();
    ki.print();
}