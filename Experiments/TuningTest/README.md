<!--
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-17 09:17:41
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-18 20:23:55
 * @FilePath: \RS_AS2\Experiments\TuningTest\README.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
-->
<!--
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-14 18:59:05
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-18 20:12:13
 * @FilePath: \RS_AS2\Experiments\TuningTest\README.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
-->
## 此程序是为了实现：
1. 确定待测试的delay范围
2. 确定对于各个delay，是否都能达到某一性能指标
3. 确定pid的调试规则

## 对**频率**进行插值，得到几个待测试点：
- [插值结果](https://zh.planetcalc.com/9023/?xy=0%201000%0A4%202&interpolate=1%202%203)


## 任务的步骤分解：
 - 对于在`不同频率`下`稳定`*的pid参数集，`改变PID频率`，观察PID`性能参数`的变化
   - `不同频率`：delay(?)~delay(?) 
     - delay上限根据什么确定？
     - delay上限根据什么确定？
     - 中间取什么值？
   - `稳定`：PID的校正遵循什么规则？
   - `改变频率`：改成哪些值？
   - `性能参数`：用谁？
 - 不同频率：delay(1)~delay(500) 之间取若干个点 **先取五个点吧**
 - 稳定：写PID调试手册 [**√**](https://github.com/Vehshanaan/RS_AS2/blob/main/Experiments/TuningExercise/PID%E8%B0%83%E8%AF%95%E6%89%8B%E5%86%8C.md)
 - 改变频率：在什么范围内改变频率？是不是自动改变频率？**在前后两个点的区间内** :取几个点？怎么[自动记录实验数据](https://www.youtube.com/watch?v=RWgyCcnUxPY&ab_channel=ShuvangkarDas)？
 - 性能参数：**超调和调节时间**

## 待实现的功能：
1. 精确的延迟控制
2. 用频率反过来确定延迟时间，然后进行实验内容
3. [串口数据的记录](https://www.youtube.com/watch?v=RWgyCcnUxPY&ab_channel=ShuvangkarDas)
