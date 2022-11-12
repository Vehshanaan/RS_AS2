/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-11 11:00:26
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-11 12:33:17
 * @FilePath: \RS_AS2\Tools\KinematicsExample\Kinematics.h
 * @Description:运动学的实现类，内含世界坐标系转角与横纵坐标、左右轮速度，直接调用公有成员即可
 * 使用方法：
 * 1.实例化Kinematics对象
 * 2.setup()中调用.init()方法初始化
 * 3.loop()中调用.update()方法，更新运动学信息
 * 4.想看哪个参数直接访问类的公有成员即可
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */
#ifndef KINEMATICS_H
#define KINEMATICS_H

#include "Encoder.h"

class Kinematics
{
public:
    double X_w = 0.0;     // 世界坐标系中的x坐标
    double Y_w = 0.0;     // 世界坐标系中的y坐标
    double theta_w = 0.0; // 世界坐标系中的theta，顺时针（往右拧）是正，逆时针（往左拧）是负

    double v_l = 0.0; // 左轮速度
    double v_r = 0.0; // 右轮速度

    long code_l = 0; // 左编码器的读数历史
    long code_r = 0; // 右编码器的读数历史

    long prev_time = 0; // 时间的历史值

    /**
     * @description:构造函数，必须存在，啥也不干
     */
    Kinematics() {}

    /**
     * @description: 初始化函数，除了初始化几个记录值以外，啥也不干
     */
    void init()
    {
        code_l = count_l;     // 初始化左电机编码值记录
        code_r = count_r;     // 初始化右电机编码值记录
        prev_time = millis(); // 初始化时间记录
    }

    void update()
    {
        // 读取左右编码器值的变化
        long code_l_delta = count_l - code_l;
        code_l = count_l;
        long code_r_delta = count_r - code_r;
        code_r = count_r;

        unsigned long delta_time = millis() - prev_time; // millis()-prev_time; // 计算Δt
        prev_time = millis();                            // 更新时间值的记录

        // 算出左右轮子的大致速度
        v_l = (double)code_l_delta / (double)delta_time;
        v_r = (double)code_r_delta / (double)delta_time;

        // 算出左右轮子前进的距离
        double dist_l = code_l_delta * code2dist;
        double dist_r = code_r_delta * code2dist;
        // X_r = 1/2*(左轮里程+右轮里程)
        double X_r = 0.5 * (dist_l + dist_r);
        // theta_r = 1/2l(左轮里程-右轮里程)
        double theta_r = (dist_l - dist_r) / (2 * l / 2.25); //本轮更新中被加到位置中的角度变化量
        
        // ↑2.25是一个纯纯的矫正参量，在公式里本不该存在，所以记得校正
        
        // X_w += X_r*cos(theta_w)
        X_w += X_r * cos(theta_w);
        // Y_w += Y_r*sin(theta_w)
        Y_w += X_r * sin(theta_w);
        // theta_w += theta_r
        theta_w += theta_r;

        // 360度回到0度的计算：
        if (theta_w > 2 * pi)
        {
            theta_w -= 2 * pi;
        }
        else if (theta_w < -2 * pi)
        {
            theta_w += 2 * pi;
        }
    }

      void print() {
    Serial.print("v_l:");
    Serial.print(v_l);
    Serial.print(" v_r:");
    Serial.print(v_r);
    Serial.print(" X_w:");
    Serial.print(X_w);
    Serial.print(" Y_w:");
    Serial.print(Y_w);
    Serial.print(" θ:");
    Serial.println(theta_w * rad2deg);
  }
};

#endif