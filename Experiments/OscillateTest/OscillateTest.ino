/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-10 16:26:44
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-13 22:24:44
 * @FilePath: \RS_AS2\Experiments\OscillateExample\OscillateExample.ino
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

void setup() {
  Serial.begin(9600);
  delay(1);
  Serial.print("***RESET***");
  setupEncoder0();
  setupEncoder1();
  ki.init();
  motor.init();

  // PID参数的调整：对于极低的延迟，此三值分别为90 0.7 0.1
  // 对于300的delay，此三值分别为30 0.11 -950
  double Kp = 30;    
  double Ki = 0.11;   
  double Kd = -950;  
  double I_limit = 5000;
  unsigned long PID_update_cycle_length = 0;

  pid_lspeed.init(Kp, Ki, Kd, I_limit, PID_update_cycle_length);  // P,I,D,积分限幅值（暂时没用，只是占位符），PID更新时间间隔（单位毫秒），系统本身能做到的最快的速度也就是500微秒更新一次
  /*
    笔记：
    1. PID更新时间间隔为500（接近自然极限）的时候是不太震荡的
    */
  step.init(5000, 1.0);
}

void loop() {

  ki.update();
  step.update();

  pid_lspeed.aim = step.value;           // 将阶跃信号的值设为速度控制PID的追踪对象
  pid_lspeed.cal(ki.v_l);                // 根据当前速度计算PID控制值
  motor.setPower(pid_lspeed.result, 0);  // 用PID结果控制电机

  if (step.value == 0) {
    pid_lspeed.reset();
    motor.setPower(0, 0);
  }

  //Serial.print("PID:");
  //Serial.println(pid_lspeed.result);

  Serial.print("1:");
  Serial.println(1);
  Serial.print("aim:");
  Serial.println(step.value);
  Serial.print("v_l:");
  Serial.println(ki.v_l);
  Serial.print("0:");
  Serial.println(0);


  delay(300);  // 用300调的参数，300的表现是一个开头部分震荡有点多的pid表现，320也不错

  // 1.可能是：pid wind up的问题：
  // 建立设置PId参数的规则
  // 保存现有的数据
  // 给delay上一个范围，用范围的数
}