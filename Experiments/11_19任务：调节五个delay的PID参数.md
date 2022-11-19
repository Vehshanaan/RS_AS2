<!--
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-19 08:48:26
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-19 09:02:27
 * @FilePath: \RS_AS2\Experiments\11_19任务：调节五个delay的PID参数.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
-->
# 任务：从delay = 10 ~ 500中选取五个点，针对这五个点调PID参数
## **小提示**，我更新了一点点那个TuningExercise，现在delay是精准的了，只是为了确保实验严谨。所以记得[更新](https://github.com/Vehshanaan/RS_AS2/tree/main/Experiments/TuningExercise)一下。
## 我想让频率`f` = 1/`delay` 等差取五个点，而不是让delay等差，这样比较*科学*一点吧，所以，
## 要用的[五个点](https://zh.planetcalc.com/9023/?xy=0%201000%0A4%202&interpolate=1%202%203)是：
|f|delay|
|:-:|:-:|
|100Hz|10(millis)|
|75.5Hz|13(millis)|
|51Hz|20(millis)|
|26.5Hz|38(millis)|
|2Hz|500(millis)|

## 针对上述五个delay的值，把pid参数调到[我们所需要的状态](https://github.com/Vehshanaan/RS_AS2/blob/main/Experiments/TuningExercise/PID%E8%B0%83%E8%AF%95%E6%89%8B%E5%86%8C.md),然后记录PID的值。

### 我正在干的下一步计划：
- 因为我们的实验稍后还要有：**保持PID参数不变，调整delay观察影响**，所以我正在写**自动在给定范围内微调delay**的东西
- 串口数据的自动保存
