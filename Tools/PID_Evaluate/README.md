<!--
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-14 18:59:05
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-16 19:28:29
 * @FilePath: \RS_AS2\Tools\PID_Evaluate\README.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
-->
## 此程序是为了实现：
- 对pid性能的稳定测量
- 
## 使用方法：
- 实例化对象 `Evaluator 名字；`
- 在`loop()`中：
  - 调用pid
  - 调用评估器`.rec(double 被控量当前值，double 控制目标, 评估器开关)` 其中，评估器开关这样使用：
    - 当阶跃函数为高时，设为`on`
    - 当阶跃函数为低时，设为`off`： off时评估器会自动复位
    - .rec会返回此次评估有没有结束。（bool true/false）
    - 若超调/调节时间没有出现（无超调/震荡）：它们的初始值是`INVALID_PARA`,这个宏的值是-1 
  - 若想手动复位，可以调用`.reset()`方法
## 程序逻辑：
- 告诉PID评估器当前是on还是off
- 告诉评估器当前的被控量值和目标值
- 计算超调和调节，调节时间算出来之后，就代表此轮计算结束，应当封存结果，不再接受计算要求

## 本程序是基于以下假设：
- 超调量只会在系统调节时间确定以前出现

## 评估器类的设想：
- **成员：**
  - double 最大值 max 记录被控量的历史最大值
  - double 超调overshoot 值为-1时代表无效，初始为-1
  - double 调节时间setting 值为-1时代表无效 初始为-1 这里按±5%的标准来吧。
  - unsigned long 开始计时的时间记录start_time 其中应以micros为计数单位 记录本次评估的开始时间 初始为0（代表无效）
  - bool 开关状态 值为on/off (t/f)
  - bool 本次测量状态 ended 值为t/f
  - int stable_count 稳定点数计算，其作用详见调节时间计算 初始为-1（代表无效）   
- **方法：**（double 目标量，double 被控量，bool on/off）
  - 根据输入的on/off设置评估器的状态（on/off）
  - 若为off： 复位
    - 复位一切参数（除开关状态以外）
    - return
  - 若为on：进行下述操作
    - 若start_time 未初始化过：
      - start_time = micros()
    - 若本次测量已结束：（ended = true）
      - return
    - 若本次测量未结束： （ended = false）
      - 计算超调：
        - 记录最大值max(和先前的max比较，更新最大值记录)
        - 若最大值max大于给定：
          - 计算当前被控量比目标量大多少temp_max
          - 若上面这行的“大多少”temp_max比已有的超调量大，则更新超调值
      - 计算调节时间
        - 若当前被控值在目标量的±5%范围内：
          - stable_count+=1
        - 若stable_count 大于某个阈值（**此阈值大小需要测试**） 
          - 调节时间setting = micros-start_time / 1000 （**此处时间转换需要测试**）
          - 本次测量结束 ended = true
      - return

