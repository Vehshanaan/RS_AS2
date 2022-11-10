/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-10 10:53:57
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-10 16:28:14
 * @FilePath: \RS_AS2\Tools\StepSIgnalGenerator\StepSignalGenerator\StepSignalGenerator.ino
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
 */
#include "StepSignal.h"

StepSignal step;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(1);
  Serial.print("*****RESET*****");

  step.init(5,1); // 设置阶跃信号的周期（5）与高时的值（1）
}

void loop() {
  // put your main code here, to run repeatedly:
  step.update(); // 更新阶跃信号的值（利用时间变化来计算）
  Serial.print("StepSignalValue:");
  Serial.println(step.value); // value即为阶跃信号对象的当前值
}
