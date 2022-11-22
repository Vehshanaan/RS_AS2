'''
Author: Runze Yuan 1959180242@qq.com
Date: 2022-11-21 08:34:48
LastEditors: Runze Yuan 1959180242@qq.com
LastEditTime: 2022-11-22 10:48:17
FilePath: \RS_AS2\Experiments\11_20_result_plot.py
Description: 

Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
'''
import numpy as np
import matplotlib.pyplot as plt
import copy


# 横轴：频率
# 纵轴：PID性能
# 五个图，对应五组调好的PID参数
'''
    原材料：
        1. 每个频率有6（偏移后频率）*10（十次测试）的数据
        2. 对每个偏移后频率，求十次测试的平均值
        3. 得到（偏移后频率，性能指标）的坐标
        4. 画图，六个点画在一起
'''
# 1. f=100
# (1) offset f = 100
f100_offset100_overshoot = [7, 9, 9, 7, 9, 17, 17, 8, 7, 8]
f100_offset100_setting = [90.26, 79.99, 109.70,
                          89.23, 80.01, 81.03, 101.52, 81.04, 60.58, 101.52]
# (2) offset f = 87.75
f100_offset8775_overshoot = [15, 15, 15, 17, 24, 17, 7, 7, 8, 15]
f100_offset8775_setting = [120.97, 89.25, 98.44,
                           132.24, 110.72, 99.47, 88.21, 143.48, 100.49, 99.46]
# (3) offset f = 75.5
f100_offset7550_overshoot = [20, 14, 14, 20, 20, 20, 20, 13, 20, 14]
f100_offset7550_setting = [117.88, 103.58, 103.58,
                           103.59, 130.20, 103.58, 103.59, 104.59, 142.46, 116.90]

f100_overshoot = [f100_offset100_overshoot,
                  f100_offset8775_overshoot, f100_offset7550_overshoot]
f100_setting = [f100_offset100_setting,
                f100_offset8775_setting, f100_offset7550_setting]

f100_offset_delays = [10, 11.4, 13.25]
f100_offset_fs = [100, 87.75, 75.5]

# 2. f = 75.5
# (1) offset f = 100
f7550_offset100_overshoot = [9, 9, 9, 9, 8, 9, 17, 9, 7, 17]
f7550_offset100_setting = [99.48, 90.24, 130.14,
                           109.72, 59.53, 81.04, 91.28, 91.22, 80.04, 81.05]

# (2) offset f = 90.2
f7550_offset9020_overshoot = [15, 15, 17, 15, 15, 8, 17, 17, 15, 15]
f7550_offset9020_setting = [154.76, 89.22, 109.70,
                            120.96, 99.47, 110.68, 88.18, 110.74, 100.48, 99.46]

# (3) offset f = 80.4
f7550_offset8040_overshoot = [22, 14, 15, 15, 14, 15, 14, 14, 22, 14]
f7550_offset8040_setting = [95.39, 119.93, 95.37,
                            119.96, 120.94, 108.69, 156.80, 168.08, 108.66, 132.23]

# (4) offset f = 70.6
f7550_offset7060_overshoot = [19, 19, 20, 19, 18, 12, 20, 19, 26, 19]
f7550_offset7060_setting = [114.84, 113.82, 113.82,
                            114.00, 113.82, 99.48, 128.14, 128.16, 128.14, 100.48]

# (5) offset f = 60.8
f7550_offset6080_overshoot = [28, 30, 16, 24, 28, 24, 34, 34, 30, 30]
f7550_offset6080_setting = [128.13, 128.27, 112.79,
                            128.14, 143.49, 96.41, 128.15, 96.35, 111.77, 160.90]

# (6) offset f = 51
f7550_offset5100_overshoot = [34, 28, 30, 36, 29, 39, 36, 30, 34, 34]
f7550_offset5100_setting = [228.50, 171.15, 171.14,
                            171.15, 152.72, 190.62, 227.47, 209.04, 172.18, 171.15]

f7550_overshoot = [f7550_offset100_overshoot, f7550_offset9020_overshoot, f7550_offset8040_overshoot,
                   f7550_offset7060_overshoot, f7550_offset6080_overshoot, f7550_offset5100_overshoot]
f7550_setting = [f7550_offset100_setting, f7550_offset9020_setting, f7550_offset8040_setting,
                 f7550_offset7060_setting, f7550_offset6080_setting, f7550_offset5100_setting]

f7550_offset_delays = [10, 11.09, 12.44, 14.16, 16.45, 19.6]
f7550_offset_fs = [100, 90.2, 80.4, 70.6, 60.8, 51]

# 3. f = 51

# (1) offset = 75.5
f5100_offset7550_overshoot = [0.00, 0.00, 0.00,
                              5.23, 0.00, 5.23, 5.86, 0.00, 0.00, 5.86]
f5100_offset7550_setting = [77.96, 104.60, 103.58,
                            91.27, 103.56, 155.78, 116.90, 91.29, 116.86, 130.18]
# (2) offset = 65.7
f5100_offset6570_overshoot = [0, 4.66, 4.69, 0, 4.19, 4.22, 4.66, 0, 0, 0]
f5100_offset6570_setting = [90.26, 91.28, 90.25,
                            90.25, 150.68, 119.96, 104.58, 90.25, 91.28, 75.90]

# (3) offset = 55.9
f5100_offset5590_overshoot = [3.71, 3.42, 3.40,
                              3.81, 9.15, 3.45, 3.42, 3.42, 3.89, 3.42]
f5100_offset5590_setting = [101.53, 102.57, 102.54,
                            102.52, 102.53, 119.96, 103.57, 137.36, 85.14, 101.74]

# (4) offset = 46.1
f5100_offset4610_overshoot = [17.21, 11.65, 11.63,
                              17.21, 2.34, 11.63, 17.21, 16.26, 16.28, 12.35]
f5100_offset4610_setting = [171.16, 192.67, 148.63,
                            128.15, 128.16, 148.64, 149.63, 128.14, 148.82, 128.16]

# (5) offset = 36.3
f5100_offset3630_overshoot = [16.45, 16.45, 23.99,
                              19.39, 19.37, 20.21, 16.47, 12.77, 20.19, 15.74]
f5100_offset3630_setting = [216.20, 216.22, 216.19,
                            270.47, 270.47, 242.80, 242.83, 271.51, 217.22, 271.50]

# (6) offset = 26.5
f5100_offset2650_overshoot = [35.65, 42.56, 41.07,
                              43.79, 32.92, 34.61, 38.36, 46.52, 38.36, 41.07]
f5100_offset2650_setting = [406.67, 370.84, 406.66,
                            481.43, 332.94, 371.87, 333.98, 406.66, 259.20, 332.89]

f5100_overshoot = [f5100_offset7550_overshoot, f5100_offset6570_overshoot, f5100_offset5590_overshoot,
                   f5100_offset4610_overshoot, f5100_offset3630_overshoot, f5100_offset2650_overshoot]
f5100_setting = [f5100_offset7550_setting, f5100_offset6570_setting, f5100_offset5590_setting,
                 f5100_offset4610_setting, f5100_offset3630_setting, f5100_offset2650_setting]

f5100_offset_delays = [13.24, 15.22, 17.89, 21.69, 27.55, 37.74]
f5100_offset_fs = [75.5, 65.7, 55.9, 46.1, 36.3, 26.5]

# 4. f = 26.5

# (1) offset = 51.0
f2650_offset5100_overshoot = [2.82, 2.86,
                              2.82, 0, 2.73, 2.92, 3.10, 3.10, 0, 0]
f2650_offset5100_setting = [285.83, 266.38, 246.92,
                            265.35, 266.38, 228.50, 266.39, 265.36, 267.40, 284.81]
# (2) offset = 41.2
f2650_offset4120_overshoot = [1.74, 1.92,
                              1.92, 1.74, 0, 0, 0, 1.92, 1.76, 1.94]
f2650_offset4120_setting = [312.46, 336.02, 263.31,
                            288.92, 239.68, 264.32, 287.90, 264.34, 264.36, 287.88]

# (3) offset = 31.4
f2650_offset3140_overshoot = [0, 0.92, 0.94,
                              0.83, 0.91, 0, 0.94, 0.95, 0.92, 0.92]
f2650_offset3140_setting = [248.97, 279.71, 310.41,
                            248.98, 373.90, 248.98, 310.43, 279.71, 310.42, 310.40]

# (4) offset = 21.6
f2650_offset2160_overshoot = [8.51, 12.85,
                              2.01, 8.52, 10.69, 8.51, 0, 6.35, 8.53, 6.36]
f2650_offset2160_setting = [322.72, 321.69, 276.61,
                            321.68, 322.67, 321.68, 276.61, 321.68, 321.69, 322.86]

# (5) offset = 11.8
f2650_offset1180_overshoot = [45.33, 41.84, 44.17,
                              46.50, 46.50, 46.49, 41.81, 45.33, 44.17, 44.17]
f2650_offset1180_setting = [688.24, 602.25, 774.28,
                            602.23, 774.28, 774.29, 602.26, 688.27, 688.26, 774.28]

# (6) offset = 2
# 震荡

f2650_overshoot = [f2650_offset5100_overshoot, f2650_offset4120_overshoot,
                   f2650_offset3140_overshoot, f2650_offset2160_overshoot, f2650_offset1180_overshoot]
f2650_setting = [f2650_offset5100_setting, f2650_offset4120_setting,
                 f2650_offset3140_setting, f2650_offset2160_setting, f2650_offset1180_setting]
f2650_offset_delays = [19.6, 24.27, 31.85, 46.30, 86.75]
f2650_offset_fs = [51, 41.2, 31.4, 21.6, 11.8]

# 5. f = 2

# (1) offset = 26.5
f2_offset2650_overshoot = [0.37, 0.31, 0.37, 0, 0.39, 0, 0.38, 0, 0.39, 0]
f2_offset2650_setting = [23738.76, 3701.89, 3737.72,
                         3701.90, 3848.31, 3774.59, 3812.49, 3664.00, 3738.74, 3774.55]
# (2) offset = 14.25
f2_offset1425_overshoot = [0, 0, 0.54, 0, 0, 0, 0, 0, 0, 0]
f2_offset1425_setting = [3781.77, 3852.43, 3922.05,
                         3851.40, 3782.79, 3851.35, 3642.51, 3852.42, 3851.38, 3853.42]

# (3) offset = 2
f2_offset2_overshoot = [7.66, 8.24, 7.46,
                        7.66, 6.26, 6.24, 6.45, 6.66, 7.06, 6.26]
f2_offset2_setting = [4500.62, 4501.66, 4000.87,
                      4499.62, 3999.87, 4000.92, 4000.90, 4500.63, 3999.89, 4499.60]

f2_overshoot = [f2_offset2650_overshoot,
                f2_offset1425_overshoot, f2_offset2_overshoot]
f2_setting = [f2_offset2650_setting, f2_offset1425_setting, f2_offset2_setting]
f2_offset_delays = [37.74, 70.18, 500]
f2_offset_setting = [26.5, 14.25, 2]

overshoots = [f100_overshoot, f7550_overshoot,
              f5100_overshoot, f2650_overshoot, f2_overshoot]
              # overshoots->某校正频率的超调列表->某offset频率的超调列表
settings = [f100_setting, f7550_setting,
            f5100_setting, f2650_setting, f2_setting]
delays = [f100_offset_delays, f7550_offset_delays,
          f5100_offset_delays, f2650_offset_delays, f2_offset_delays]

"""打印图像：
1. 对于每一个频率：
    横轴：f_offset（如果效果不好，考虑delay_offset）
    纵轴：超调，调节时间（两张图来显现）即下面的两个avg
"""
avg_overshoots = copy.deepcopy(overshoots)
avg_settings = copy.deepcopy(settings)
avg_steps = copy.deepcopy(settings)
fs = copy.deepcopy(delays)

for i in range(len(overshoots)):
    for j in range(len(overshoots[i])):
        avg_overshoots[i][j]=(sum(overshoots[i][j])/len(overshoots[i][j]))

for i in range(len(settings)):
    for j in range(len(settings[i])):
        avg_settings[i][j]=((sum(settings[i][j])/len(settings[i][j])))

for i in range(len(settings)):
    for j in range(len(settings[i])):
        avg_steps[i][j]=((sum(settings[i][j])/len(settings[i][j])))/delays[i][j] ## 按步长计

for i in range(len(delays)):
    for j in range(len(delays[i])):
        fs[i][j]=1000.0/delays[i][j]
        print(fs[i][j])

        
"""
图片：
    每个f有两个图，一个超调一个调节
    有五个f
    5行2列。一行一个f，一列一个性能参数
"""
tuned_frequency = [100,75.5,51,26.5,2]

figure = plt.figure()
for r in range(5):
    rows = r+1

    plt.subplot(5,3,r*3+1) 
    plt.plot(fs[r],avg_overshoots[r],marker = "o")
    plt.axvline(tuned_frequency[r],0,1,color = "r")
    plt.ylim((0,50))
    plt.ylabel("overshoot(%)")
    plt.xlabel("frequency")

    plt.subplot(5,3,r*3+2)
    plt.plot(fs[r],avg_settings[r],marker = "o")
    plt.axvline(tuned_frequency[r],0,1,color = "r")
    plt.ylabel("setting(ms)")
    plt.xlabel("frequency")

    plt.subplot(5,3,r*3+3)
    plt.plot(fs[r],avg_steps[r],marker = "o")
    plt.axvline(tuned_frequency[r],0,1,color = "r")
    plt.ylabel("setting(steps)")
    plt.xlabel("frequency")
figure.tight_layout()#调整整体空白
##plt.subplots_adjust(wspace =0, hspace =0)
plt.show()   

