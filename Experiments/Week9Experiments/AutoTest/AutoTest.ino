/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-23 15:11:26
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-23 22:41:32
 * @FilePath: \RS_AS2\Experiments\Week9Experiments\AutoTest\AutoTest.ino
 * @Description:
 *
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */
#include "Interpolate.h"

void setup()
{
    Serial.begin(9600);
    delay(1);
    Serial.println("RESET");
    delay(5000);
}

/*
任务：
    输入总频率域的上下限，插值得到总的待测试频率点序列f_test[]
        针对f_test中的每个点，取其上下两个点之间的邻域，生成给定点数的序列f_neighbour[]（temp）
            针对每个f_neighbour的点，算出其delay（temp）
                对于每个delay：用对应的pid测试十次，计算均值
                print性能指标的均值，print对应的f(用delay算出)，print调pid时使用的f(f_test中的某个)
产生的文本文件的使用：
    列表可以用append来往里塞任何东西，包括其他列表

*/
volatile int i = 0;
volatile bool f_test_printed = false;
void loop()
{
    // 频率上下限
    double f_max = 1000;
    double f_min = 2;
    // 总的频率域插值点数
    int interpolate_points = 8;
    if(i>=interpolate_points){return;}
    // 总的频率域待测试点的集合
    double f_test[interpolate_points];
    // 插值计算总的频率域待测试点
    Interpolate(f_max, f_min, interpolate_points, f_test); // 生成结果是从小到大的
    // 向python输出待测试点
    if (!f_test_printed)
    {
        Serial.print("f_test=[");
        for (int j = 0; j < interpolate_points; j++)
        {
            Serial.print(f_test[j]);
            Serial.print(", ");
        }
        Serial.println("]");
        Serial.println("f_neighbours = []"); // 初始化邻域频率列表
        Serial.println("overshoot_results = []"); // 初始化测试到的超调列表
        Serial.println("setting_results = []"); // 初始化测试到的调节时间列表
        f_test_printed = true;
    }
    // 规定一个邻域中有几个点
    int neighbour_points = 6;
    // 对每个待测试频率的邻域点的存储集合
    double f_neighbour[neighbour_points];

    // 用外层的i遍历f_test,即所有待测试频率，一个loop过一个
    // 计算当前被测试频率的邻域中有谁
    double neighbour_max = 0.0; // 初始化插值上下限
    double neighbour_min = 0.0;
    if (i == 0) // 若当前受测试点是第一个点：
    {
        neighbour_min = f_test[i];
    }
    else
    {
        neighbour_min = f_test[i - 1];
    }
    if (i == (interpolate_points - 1)) //如果是最后一个点
    {
        neighbour_max = f_test[i];
    }
    else
    {
        neighbour_max = f_test[i + 1];
    }
    // 给邻域插值，生成邻域值
    Interpolate(neighbour_max, neighbour_min, neighbour_points, f_neighbour);
    // 打印邻域频率值
    Serial.print("f");
    Serial.print((int)f_test[i]);
    Serial.print("_offsets = [");
    for (int _ = 0; _ < neighbour_points; _++)
    {
      Serial.print(f_neighbour[_]);
      Serial.print(", ");
    }
    Serial.println("]");
    Serial.print("f_neighbours.append(");
    Serial.print("f");
    Serial.print((int)f_test[i]);
    Serial.print("_offsets");
    Serial.println(")");
    // 计算所有邻域频率所对应的delay
    double delays[neighbour_points];
    for (int _ = 0; _ < neighbour_points; _++)
    {
        delays[_] = 1000.0 / f_neighbour[_];
    }
    Serial.print("f");
    Serial.print((int)f_test[i]);
    Serial.println("_test_overshoot=[]");// 初始化本f_test的各个offset的超调结果，下面的各个delay测试完后要append到这里
    Serial.print("f");
    Serial.print((int)f_test[i]);
    Serial.println("_test_setting=[]");// 初始化本f_test的各个offset的调节时觉结果，下面的各个delay测试完后要append到这里
    // 上述两个list最后要append到总表里
    for (int _ = 0; _ < neighbour_points; _++)
    {
        // 对于每一个邻域中的f_offset点，进行测试, 测试十次求setting和overshoot的均值，然后append给f_ftest_test_oveshoot/setting

        // 前面已经算过各个offset点对应的delay，就直接调取对应delay就行
        double delay_current = delays[_];
        // 取本f_test对应的PID
        // 对于当前的delay，PID，进行十次测试，记录平均值
        // 把结果append给fftest_test_overshoot/setting
        // 所以这里应该有一个高级的PID评估器，给定delay和PID参数，就能返回十次平均的overshoot和setting
        
    }
    Serial.print("overshoot_results.append(");
    Serial.print("f");
    Serial.print((int)f_test[i]);
    Serial.println("_test_overshoot)");
    Serial.print("setting_results.append(");
    Serial.print("f");
    Serial.print((int)f_test[i]);
    Serial.println("_test_setting)");

    i += 1;
    delay(100);
}