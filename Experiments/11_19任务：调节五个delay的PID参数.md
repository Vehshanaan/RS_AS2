<!--
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-19 08:48:26
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-20 18:46:46
 * @FilePath: \RS_AS2\Experiments\11_19任务：调节五个delay的PID参数.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
-->
# 任务：从delay = 10 ~ 500中选取五个点，针对这五个点调PID参数
## **小提示**，我更新了一点点那个TuningExercise，现在delay是精准的了，只是为了确保实验严谨。所以记得[更新](https://github.com/Vehshanaan/RS_AS2/tree/main/Experiments/TuningExercise)一下。更新前记得保留自己的历史记录，以防万一。
## 我想让频率`f` = 1/`delay` 等差取五个点，而不是让delay等差，这样比较*科学*一点吧，所以，
## 要用的[五个点](https://zh.planetcalc.com/9023/?xy=0%201000%0A4%202&interpolate=1%202%203)是：


[调试用程序](https://github.com/Vehshanaan/RS_AS2/tree/main/Experiments/TuningExercise)
>Robot-C:

|f|delay|P|I|D|
|:-:|:-:|:-:|:-:|:-:|
|100Hz|10(millis)|35|2.5|5|
|75.5Hz|13(millis)|35|1.8|2.5|
|51Hz|20(millis)|35|1.5|2|
|26.5Hz|38(millis)|35|0.75|1|
|2Hz|500(millis)|35|0.05|950|

11_20 在Robot—Y上对参数做的测试和性能验证
>Robot-Y

|f|delay|P|I|D|overshoot|setting|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|100Hz|10(millis)|35|2.5|5|大约15%|大约100ms|
|75.5Hz|13(millis)|35|1.8|2.5|大约0~5%|大约70ms|
|51Hz|20(millis)|35|1.5|2|大约12%|大约128ms|
|26.5Hz|38(millis)|35|0.75|1|大约5%|大约235.7ms|
|2Hz|500(millis)|35|0.05|1000|大约7%|大约7-8个点(3500——4000ms)|

## 发现：
1. 对于38（milli)的delay,（五个点后在一定时间内稳定在5%内，但最后出现了较大波动）
2. 对于延迟低于20(millis)的五个点后虽然趋于稳定但波动较大

## 针对上述五个delay的值，把pid参数调到[我们所需要的状态](https://github.com/Vehshanaan/RS_AS2/blob/main/Experiments/TuningExercise/PID%E8%B0%83%E8%AF%95%E6%89%8B%E5%86%8C.md),然后记录PID的值。

### 我正在干的下一步计划：
- 因为我们的实验稍后还要有：**保持PID参数不变，调整delay观察影响**，所以我正在写**自动在给定范围内微调delay**的东西
- 串口数据的自动保存
