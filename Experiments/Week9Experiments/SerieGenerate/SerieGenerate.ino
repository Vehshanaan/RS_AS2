/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-23 10:57:23
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-23 18:24:43
 * @FilePath: \RS_AS2\Experiments\Week9Experiments\SerieGenerate\SerieGenerate.ino
 * @Description:
 * 给定上下限，给定点数，自动插值，适用于频率域插值等。返回指针的方式对arduino可能不稳定
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */

#include "Interpolate.h"

void setup()
{
    Serial.begin(9600);
    delay(1);
    Serial.println("RESET");
}

volatile long count = 0;

void loop()
{
    double max = 1000.0;
    double min = 2.0;
    int dot_number = 180;
    double result[dot_number];
    Interpolate(max, min, dot_number,result);
    if (count == 5)
    {

        Serial.println("begins!");
        for (int i = 0; i < dot_number; i++)
        {
            Serial.println(result[i]);
        }
    }
    count += 1;
    delay(1000);
}