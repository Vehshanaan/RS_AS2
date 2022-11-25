/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-24 13:23:03
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-25 09:34:34
 * @FilePath: \RS_AS2\Experiments\Week9Experiments\PID_AutoTest\PIDAutoEvaluate.h
 * @Description:
 *
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */
#include "Arduino.h"
#ifndef AUTOEVALUATE_H
#define AUTOEVALUATE_H

#define OSCILLATE 99999.0

#include "Evaluator.h"
#include "PID.h"
#include "Motor.h"
#include "Kinematics.h"
#include "StepSignal.h"

/**
 * @description: 对给定的delay与PID参数组进行十一次测试，舍弃掉第一组数据，对后十组的性能参数求平均，返回
 * @param {double} delay 给定的delay
 * @param {double} Kp   给定的P
 * @param {double} Ki   给定的I
 * @param {double} Kd   给定的D
 * @param {int} times 重复几次？
 * @param {double*} parameters double数组，用来返回性能指标，[0]是超调（%），[1]是调节时间（ms）
 * @param {int} step_length 阶跃信号周期长度，可以根据delay来设置这个，为了得到更快的测试速度
 */
void PIDEvaluate(double delay, double Kp, double Ki, double Kd, int times, double *parameters,int step_length)
{
    // 初始化性能指标保存变量
    double overshoot = 0.0;
    double setting = 0.0;
    // 初始化PID控制器
    PID pid_lwheelspeed;
    pid_lwheelspeed.init(Kp, Ki, Kd, 99999, 0);
    // 初始化电机控制类
    Motor motor;
    motor.init();
    // 初始化编码器
    setupEncoder0();
    setupEncoder1();
    // 初始化运动学
    Kinematics ki;
    ki.init();
    // 初始化阶跃函数
    StepSignal step;
    step.init(step_length, 1.0);
    // 初始化评估器
    Evaluator eva;
    // while count<?，进行评估，并给overshoot和setting加上自己对应的值。
    bool prev_ended = false; // 某一次的评估是否已测试完成的历史记录
    bool step_state= false; // 用来检查阶跃函数的值是否有跳变的一个bool量
    bool step_state_prev = false; // 阶跃函数状态的记录bool量
    int count = -1;
    unsigned long prev_micros = micros();
    while (count < times)                  // 当还没取够十次性能参数时：
    {
        // 在这里面跑一个周期的阶跃，pid根据其频率不断地跟随，直到eva出结果
        if ((micros() - prev_micros) >= delay * 1000.0) // 如果该更新了：
        {
            step_state_prev = step_state; // 记录阶跃函数状态
            ki.update();
            step.update();
            if (step.value == step.high) // 如果当前阶跃函数值为高：
            {
                step_state = true;
                pid_lwheelspeed.aim = step.value;
                pid_lwheelspeed.cal(ki.v_l);
                motor.setPower(pid_lwheelspeed.result, 0);
                eva.record(ki.v_l, pid_lwheelspeed.aim, on);
            }
            else
            {
                step_state=false;
                pid_lwheelspeed.reset();
                motor.setPower(0, 0);
                if((step_state&&step_state_prev)==0&&step_state_prev)
                {
                  // 阶跃函数跳变为低的第一次，会进入到这里
                  if(eva.ended==false){ // 如果跳低了还没收敛：
                    // 结束评估，返回代表震荡的值
                    parameters[0]=OSCILLATE;
                    parameters[1]=OSCILLATE;
                    return;
                  }
                }
                eva.reset();
            }
            prev_micros = micros();
        }

      // 下面的任务：针对十一次稳定情形，舍去其中第一次，把剩下十次加起来，其中要注意不收敛情况的处理
      
      // 若正常运行且收敛了，就会进入这里
      if( ((prev_ended&&eva.ended)==0) && eva.ended)
      {
        // 如果ended状态跳变并且确实ended了：记录性能数据
        //Serial.print("setting: ");Serial.println(eva.setting);
        //Serial.print("overshoot: ");Serial.println(eva.overshoot);
        if(count!=-1) // 舍去count=-1的第一次测量值，那个不准
        {
          if(eva.overshoot!=INVALID_PARA)
          {
            overshoot+=eva.overshoot;
          }
          setting+=eva.setting;
        }
        count+=1;
      }
      prev_ended = eva.ended;
    }

    // 出while代表十次评估结束

    // overshoot/=点数，setting/=点数

    overshoot /= (double)times;
    setting /= (double)times;

    parameters[0] = overshoot * 100.0; // 直接转化为百分比
    parameters[1] = setting;

    motor.setPower(0,0); // 记得停机
    return;
}

#endif