/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-23 15:11:26
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-28 22:00:02
 * @FilePath: \RS_AS2\Experiments\Week9Experiments\AutoTest\AutoTest.ino
 * @Description:
 *
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */
#include "Interpolate.h"
#include "PIDAutoEvaluate.h"

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
volatile double I[15] = {0.045, 1.20, 1.73, 2.34, 2.50, 2.63, 2.72, 2.86, 2.89, 2.92, 0.35, 0.7, 0.9, 0.9, 0.9}; // 从小到大的I参数
volatile double D[15] = {1000, 3.243, 2.52, 2.55, 2.19, 2.05, 1.97, 1.93, 1.91, 1.89, 2.9, 2.9, 2.9, 2.9, 2.9};  // 从小到大的D参数
// ts：                   3000,  180,   104,  70,   60,   53,    0,异常震荡，45,异常震荡,300，95, 振荡，震荡，震荡
//  f:                                                               251          322
void loop()
{
  // 频率上下限
  double f_max = 500;
  double f_min = 2;
  // 总的频率域插值点数
  int interpolate_points = 15;
  if (i >= interpolate_points)
  {
    return;
  }
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
    Serial.println("f_neighbours = []");      // 初始化邻域频率列表
    Serial.println("overshoot_results = []"); // 初始化测试到的超调列表
    Serial.println("setting_results = []");   // 初始化测试到的调节时间列表
    f_test_printed = true;
  }
  // 规定一个邻域中有几个点
  int neighbour_points = 10;
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
  Serial.println("_test_overshoot=[]"); // 初始化本f_test的各个offset的超调结果，下面的各个delay测试完后要append到这里
  Serial.print("f");
  Serial.print((int)f_test[i]);
  Serial.println("_test_setting=[]"); // 初始化本f_test的各个offset的调节时觉结果，下面的各个delay测试完后要append到这里
  // 上述两个list最后要append到总表里
  for (int _ = 0; _ < neighbour_points; _++)
  {
    // 对于每一个邻域中的f_offset点，进行测试, 测试十次求setting和overshoot的均值，然后append给上面的f_ftest_test_oveshoot/setting
    double performances[2]; // 0:overshoot,1:setting
    // 前面已经算过各个offset点对应的delay，就直接调取对应delay就行
    double delay_current = delays[_];
    // 取本f_test对应的PID
    // 对于当前的delay，PID，进行十次测试，记录平均值,保存到overshoot/setting_current_delay

    /*PID评估器here
        输入：当前频率对应的delay，pid参数，两个double（用来返回性能参数）
        返回：无，直接操作输入的两个性能参数
        */
    int step_duration;
    if ((100 * delay_current) > 5000) // arduino的int是16位，最大三万多，这个是防溢出
    {
      step_duration = 5000;
    }
    else
    {
      step_duration = 100 * delay_current;
    }
    if (step_duration < 800)
    { // 防止阶跃函数周期太短
      step_duration = 800;
    }

    // 取PID参数
    double Kp = 35;
    double Ki = I[i];
    double Kd = D[i];
    int times = 10; // 代表的含义是：每个点重复十次取均值
    // 测试:

    PIDEvaluate(delay_current, Kp, Ki, Kd, times, performances, step_duration);

    // 把结果append给fftest_test_overshoot/setting
    Serial.print("f");
    Serial.print((int)f_test[i]);
    Serial.print("_test_overshoot.append(");
    Serial.print(performances[0]);
    Serial.println(")");
    Serial.print("f");
    Serial.print((int)f_test[i]);
    Serial.print("_test_setting.append(");
    Serial.print(performances[1]);
    Serial.println(")");
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