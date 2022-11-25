/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-10 16:36:15
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-13 22:24:28
 * @FilePath: \RS_AS2\Experiments\OscillateExample\PID.h
 * @Description:PID类，使用方法如下：
 * 1.建立PID类的对象
 * 2.使用PID.init()来给三个参数以及积分限幅上限赋值，以及给更新频率赋值
 * 3.计算PID结果：调用PID.cal(),括号里面输入被控量的当前值就可以，结果是PID.result,可以直接调用，因为是public
 * 4.如果想要重置PID，就用PID.reset(),他会在保持给定参数不变的同时，重置其他的一切
 *
 * 备注：如果仅计算一个轮子的pid，一般会间隔500-600微秒（micros）
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */

#include "Arduino.h"

#ifndef PID_H
#define PID_H

/**
 * @description: PID类，具体使用方法参见头文件PID.h最开头的描述
 */
class PID
{
public:
  double Kp = 0.0; // P的系数
  double Ki = 0.0; // I的系数
  double Kd = 0.0; // D的系数

  double P = 0.0; // 计算后得到的P项
  double I = 0.0; // 计算后得到的I项
  double D = 0.0; // 计算后得到的D项

  double prev_I = 0.0;  // 积分（I）的历史累加值，计算I必须用到这个
  double I_limit = 0.0; // 如果要用到积分限幅：这就是积分限幅上限值的储存位置

  double prev_e = 0.0; // 误差值（e）的历史记录，计算微分（D）必须用到这个

  double aim = 0.0; // PID控制的目标，要让被控量追踪这个aim值

  double result = 0.0; // PID的计算结果
  double e = 0.0;      // 误差（error）信号

  unsigned long prev_time = 0; // 时间记录，算微分积分必须用到这个

  unsigned long update_cycle_length = 100000; // 单位为毫秒（=0.001微秒/millis），两次update()的时长超过此变量的值，则进行更新，不然update会直接return，初始值100微秒

  // 构造函数，必须存在，里面啥也没有
  PID()
  {
  }

  /**
   * @description: PID的初始化函数，内容主要是把所有值设为0，把时间记录更新为当前时间，接受输入的三个参数以及积分限幅值
   * @param {double} Kp_ P项参数
   * @param {double} Ki_ I项参数
   * @param {double} Kd_ D项参数
   * @param {double} I_limit_ 积分限幅的上限值
   * @param {unsigned long} update_cycle 设置两次update()的时间间隔应为多少
   */
  void init(double Kp_, double Ki_, double Kd_, double I_limit_, unsigned long update_cycle)
  {
    Kp = Kp_;
    Ki = Ki_;
    Kd = Kd_;

    P = 0.0;
    I = 0.0;
    D = 0.0;

    prev_I = 0.0;
    I_limit = I_limit_;

    prev_e = 0.0;

    aim = 0.0;

    result = 0.0;
    e = 0.0;

    prev_time = micros();

    update_cycle_length = update_cycle;
    return;
  }

  /**
   * @description: 即为update，计算pid控制值
   * @param {double} y 被控对象的当前值
   * @return  无return，但是会更新PID.result，即PID计算结果
   */
  void cal(double y)
  {

    // 计算时间间隔：
    unsigned long delta_micros = micros() - prev_time;

    if (delta_micros < update_cycle_length) // 如果根据设好的时间间隔，还不到该更新的时候：
    {
      return; // 直接结束
    }

    prev_time = micros(); // 更新时间历史记录到现在

    e = aim - y; // 计算被控量y与控制目标（跟随目标）aim的差距e

    if (e != e)
    { // 解释：有时候e会是NaN，不知道这么回事，但是NaN是不等于自己的，所以利用这个if可以排除掉
      return;
    }

    double delta_time = (double)delta_micros / 1000; // 把时间变化量重新缩放到毫秒为单位

    // P计算：
    P = e * Kp;

    // I计算
    prev_I += delta_time * e;
    I = Ki * prev_I;

    // D计算
    double delta_e = prev_e - e;
    D = (delta_e / delta_time) * Kd;

    // 积分限幅

    if (abs(I) > I_limit)
    { // 如果积分项超出限制范围，则清空积分历史值，并把本轮计算的I也赋为0
      I = 0;
      prev_I = 0;
    }

    result = P + I + D;

    prev_e = e; // 记录e值,给下次计算用
  }

  /**
   * @description: 重设PID的各项值，此函数使用后PID会回到刚刚初始化的状态，但会保持三项参数及积分限幅值不变
   */
  void reset()
  {
    init(Kp, Ki, Kd, I_limit, update_cycle_length);
    return;
  }
};

#endif