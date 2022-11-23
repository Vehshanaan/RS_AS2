<!--
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-23 10:50:54
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-23 10:56:23
 * @FilePath: \RS_AS2\待办事项与每周进度\Week9待办.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
-->
## 目的：在更广的频率范围内测试pid效能
## 程序目的：输入上下限频率，输入插值点数目，输入邻域中插值点数目，自动改变pid参数，自动测算各个点的性能
1. 对于频率域中的点：
  - 生成对应pid参数
  - 计算邻域中几个点的频率和其对应delay
  - 每个邻域delay测算10次取平均值
2. 更改频率域中的点，返回2.

待制作程序：
1. 给定上下限，给定点数/步长，生成序列的函数
2. pid参数自动生成参数