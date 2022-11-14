<!--
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-14 18:59:05
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-14 21:01:04
 * @FilePath: \RS_AS2\Experiments\OscillateTest\README.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
-->
## 此程序是为了验证以下想法：
- 越大的延迟，就需要越小的积分项
- 对于大延迟稳定的pid参数，把延迟调小会使其震荡，延迟调大可以趋于稳定

## 记住：原本的猜想：
- 对于一个PID控制器，延迟可能有助于其保持稳定

## 现在我们在做的：
- 对于某一个延迟调好PID，然后减少延迟，观察影响

# 观察到的结果：
- 用300的delay调好了pid，30 0.11 -950
- 减少延迟值会使调节时间无敌长，变成纯爬坡。同时消灭了超调
- 增加延迟值会使函数趋向于震荡