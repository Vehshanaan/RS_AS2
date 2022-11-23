/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-23 10:57:23
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-23 11:09:09
 * @FilePath: \RS_AS2\Experiments\Week9Experiments\SerieGenerate\SerieGenerate.ino
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
 */

/**
 * @description: 
 * @param {double} max 插值的区域上限
 * @param {double} min 插值的区域下限
 * @param {int} dot_numbers 插多少个点
 * @return {double*} 返回一个double数组，长度为dot_numbers, 其内容从小到大
 */
double* SerieGenerate(double max, double min, int dot_numbers){
    
    double result[dot_numbers]; 
    double step = (max-min)/(dot_numbers-1);

    for(int i=0;i<dot_numbers;i++){
        result[i]=min+i*step;
    }
    static double* ret = result;
    return ret;

}

void setup(){
    Serial.begin(9600);
    delay(1);
    Serial.println("RESET");
}


void loop()
{
    double max = 1000.0;
    double min = 2.0;
    int dot_number = 3;
    Serial.println("begins!");
    double* result;
    result=SerieGenerate(max,min,dot_number);
    for(int i=0;i<dot_number;i++){
      Serial.println(result[i]);
    }
    delay(1000);
}