/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-16 15:26:03
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-16 19:23:14
 * @FilePath: \RS_AS2\Tools\PID_Evaluate\Evaluator.h
 * @Description:
 *
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */
#ifndef EVALUATOR_H
#define EVALUATOR_H

#define on true         // 评估器启动
#define off false       // 评估器关闭
#define INVALID_PARA -1 // 初始化参数用的宏

class Evaluator
{
public:
    double overshoot = INVALID_PARA; // 超调量
    double max = INVALID_PARA;       // 最大值记录，计算超调量用

    double setting = INVALID_PARA;   // 调节时间
    int stable_count = INVALID_PARA; // 保持稳定的次数的统计，计算调节时间用

    unsigned long start_time = 0; // 此次PID开始评估的时间
    bool power = off;             // 是否启动评估器，评估器电源
    bool ended = false;           // 本轮PID是否已评估完毕？所有待获取数据均已得到？

    Evaluator()
    {
        // 构造函数，必须存在
        overshoot = INVALID_PARA;
        max = INVALID_PARA;
        setting = INVALID_PARA;
        stable_count = INVALID_PARA;
        start_time = 0;
        power = off;
        ended = false;
    }

    /**
     * @description: 复位函数，将一切参数复位回原位。关闭评估器的时候用这个
     */
    void reset()
    {
        overshoot = INVALID_PARA;
        max = INVALID_PARA;
        setting = INVALID_PARA;
        stable_count = INVALID_PARA;
        start_time = 0;
        power = off;
        ended = false;
    }

    /**
     * @description: PID评估器的记录函数，在loop里调用这个，就可以得到PID的性能参数
     * @param {double} value 被控量的值
     * @param {double} aim 被控量的追踪目标，即给定值
     * @param {bool} power_ 开关PID评估器
     * @return {*} 本次评估是否已结束
     */
    bool record(double value, double aim, bool power_)
    {
        power = power_;
        if (power == off)
        {
            reset();
            return ended;
        }
        else
        {
            if (ended == true) // 如果本次评估已经结束：
            {
                return ended; // 啥也不干
            }
            if (start_time == 0) // 如果起始时间没有被初始化过：
            {
                start_time = micros(); // 记录起始时间
            }
            if (ended == false) // 如果本次评估没有结束：
            {
                if (value > max) // 如果被控量高于现有最大值记录
                {
                    max = value; // 更新最大值记录
                }
                if (max > aim) // 如果最大值大于被控量
                {
                    double current_overshoot = max - aim; // 计算当前超调
                    if (current_overshoot > overshoot) // 如果当前超调大于超调值记录
                    {
                        overshoot = current_overshoot; // 更新超调值
                    }
                }
                if (abs(value - aim) <= abs(aim * 0.05)) // 如果被控量在控制目标的±5%：
                {
                    stable_count += 1; // 增加一次稳定计数
                }
                else //若不在稳定区间内:
                {
                    stable_count == INVALID_PARA; //将稳定计数器复位
                }
                if (stable_count >= 2) // 如果记录到连续三次稳定：(此处这个判断可能需要测试)
                {
                    setting = micros() - start_time + 0.0; // 计算调节时间
                    setting /= 1000.0;                      // 单位转换：转化为millis()
                    ended = true;                          // 评估结束
                }
            }
        }
        return ended; // 返回当前评估是否已结束
    }
};

#endif