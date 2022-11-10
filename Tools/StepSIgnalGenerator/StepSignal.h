/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-10 10:54:21
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-10 16:21:24
 * @FilePath: \RS_AS2\Tools\StepSIgnalGenerator\StepSignalGenerator\StepSignal.h
 * @Description:
 *  阶跃信号发生器，通过class实现。使用方法详见下一行（代码文本中）
 *  使用方法：
 *      1.建立对象
 *      2.用.init()方法设置周期和高值
 *      3.在loop()中放一句对象.update()
 *      4.对象.value 就是阶跃函数当前的输出，这是一个int。
 *  原理是每次调用update，如果超出给定period值，则将函数值翻转（高到低低到高）
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */
#ifndef STEPSIGNAL_H
#define STEPSIGNAL_H

// 阶跃信号类，使用前需要init周期与信号为高时对应的值（默认两者均为0）
class StepSignal
{
public:
    int period = 0;              // 阶跃信号的周期，这个周期是单个高/低的长度，实际上数学定义层面的周期应该是2*period
    int high = 0;                // 阶跃信号的“高”具体是多少
    int value = 0;               // 阶跃信号的当前值, 用于输出，调用这个就可以得到函数当前的值，当然，在使用前要update()
    unsigned long prev_time = 0; // 上次更新函数值时的时间记录

    /**
     * @description: 构造函数，初始化类内的时间记录
     */
    StepSignal()
    {
        prev_time = millis(); // 初始化时间记录
        return;
    }

    /**
     * @description: 初始化函数，用户应当在这里做的是：初始化阶跃信号的周期，峰值大小。
     * @param {int} p :阶跃信号的周期。从低到高一整个算是一个周期,单个周期中一半是高，一半是低。
     * @param {int} h :阶跃信号的“高”具体是多少。
     */
    void init(int p, int h)
    {
        period = p;
        high = h;
        prev_time = millis();
        return;
    }

    /**
     * @description: 用于重新设置阶跃函数的周期和值，只是为了函数名好记，实际上和init是同样的功能
     * @param {int} p :阶跃信号的周期。从低到高一整个算是一个周期,单个周期中一半是高，一半是低。
     * @param {int} h :阶跃信号的“高”具体是多少。
     */
    void reset(int p, int h)
    {
        period = p;
        high = h;
        prev_time = millis();
        return;
    }

    /**
     * @description: 翻转函数值，高就变低，低就变高
     */
    void flip()
    {

        if (value == high) // 如果函数当前值是高
        {
            // 就翻成低
            value = 0;
        }
        else // 如果函数state是低
        {
            // 就翻成高
            value = high;
        }
    }

    /**
     * @description: 根据时间更新阶跃函数状态
     */
    void update()
    {
        unsigned long current_time = millis();             // 当前时间
        unsigned long duration = current_time - prev_time; // 距离上次函数值翻转后已经过的时间
        if (duration >= period)                            // 若超时：
        {
            flip();               // 翻转函数值
            prev_time = millis(); // 更新时间记录
        }
        return;
    }
};
#endif