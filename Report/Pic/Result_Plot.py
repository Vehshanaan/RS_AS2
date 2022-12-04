import numpy as np
import matplotlib.pyplot as plt
f_test = [2.00, 37.57, 73.14, 108.71, 144.29, 179.86, 215.43,
          251.00, 286.57, 322.14, 357.71, 393.29, 428.86, 464.43, 500.00, ]
f_neighbours = []
overshoot_results = []
setting_results = []
f2_offsets = [2.00, 5.95, 9.90, 13.86, 17.81,
              21.76, 25.71, 29.67, 33.62, 37.57, ]
f_neighbours.append(f2_offsets)
f2_test_overshoot = []
f2_test_setting = []
f2_test_overshoot.append(2.36)
f2_test_setting.append(2602.20)
f2_test_overshoot.append(0.00)
f2_test_setting.append(4462.74)
f2_test_overshoot.append(0.00)
f2_test_setting.append(4338.76)
f2_test_overshoot.append(0.00)
f2_test_setting.append(4136.88)
f2_test_overshoot.append(0.08)
f2_test_setting.append(4150.91)
f2_test_overshoot.append(0.00)
f2_test_setting.append(4241.37)
f2_test_overshoot.append(float('NaN'))
f2_test_setting.append(float('NaN'))
f2_test_overshoot.append(float('NaN'))
f2_test_setting.append(float('NaN'))
f2_test_overshoot.append(float('NaN'))
f2_test_setting.append(float('NaN'))
f2_test_overshoot.append(float('NaN'))
f2_test_setting.append(float('NaN'))
overshoot_results.append(f2_test_overshoot)
setting_results.append(f2_test_setting)
f37_offsets = [2.00, 9.90, 17.81, 25.71,
               33.62, 41.52, 49.43, 57.33, 65.24, 73.14, ]
f_neighbours.append(f37_offsets)
f37_test_overshoot = []
f37_test_setting = []
f37_test_overshoot.append(float('NaN'))
f37_test_setting.append(float('NaN'))
f37_test_overshoot.append(float('NaN'))
f37_test_setting.append(float('NaN'))
f37_test_overshoot.append(26.34)
f37_test_setting.append(588.30)
f37_test_overshoot.append(29.55)
f37_test_setting.append(310.55)
f37_test_overshoot.append(12.11)
f37_test_setting.append(214.20)
f37_test_overshoot.append(2.51)
f37_test_setting.append(159.24)
f37_test_overshoot.append(1.08)
f37_test_setting.append(140.39)
f37_test_overshoot.append(1.13)
f37_test_setting.append(126.77)
f37_test_overshoot.append(0.31)
f37_test_setting.append(129.11)
f37_test_overshoot.append(0.67)
f37_test_setting.append(170.32)
overshoot_results.append(f37_test_overshoot)
setting_results.append(f37_test_setting)
f73_offsets = [37.57, 45.48, 53.38, 61.29,
               69.19, 77.10, 85.00, 92.90, 100.81, 108.71, ]
f_neighbours.append(f73_offsets)
f73_test_overshoot = []
f73_test_setting = []
f73_test_overshoot.append(27.70)
f73_test_setting.append(259.54)
f73_test_overshoot.append(20.91)
f73_test_setting.append(174.80)
f73_test_overshoot.append(10.80)
f73_test_setting.append(134.10)
f73_test_overshoot.append(8.80)
f73_test_setting.append(107.14)
f73_test_overshoot.append(6.25)
f73_test_setting.append(141.34)
f73_test_overshoot.append(3.91)
f73_test_setting.append(84.34)
f73_test_overshoot.append(4.66)
f73_test_setting.append(95.05)
f73_test_overshoot.append(4.40)
f73_test_setting.append(93.88)
f73_test_overshoot.append(3.23)
f73_test_setting.append(84.71)
f73_test_overshoot.append(4.03)
f73_test_setting.append(102.89)
overshoot_results.append(f73_test_overshoot)
setting_results.append(f73_test_setting)
f108_offsets = [73.14, 81.05, 88.95, 96.86, 104.76,
                112.67, 120.57, 128.48, 136.38, 144.29, ]
f_neighbours.append(f108_offsets)
f108_test_overshoot = []
f108_test_setting = []
f108_test_overshoot.append(17.08)
f108_test_setting.append(132.43)
f108_test_overshoot.append(15.14)
f108_test_setting.append(117.39)
f108_test_overshoot.append(13.98)
f108_test_setting.append(96.81)
f108_test_overshoot.append(11.67)
f108_test_setting.append(96.71)
f108_test_overshoot.append(9.40)
f108_test_setting.append(82.73)
f108_test_overshoot.append(7.03)
f108_test_setting.append(91.98)
f108_test_overshoot.append(9.08)
f108_test_setting.append(69.69)
f108_test_overshoot.append(8.82)
f108_test_setting.append(80.37)
f108_test_overshoot.append(6.02)
f108_test_setting.append(66.63)
f108_test_overshoot.append(6.32)
f108_test_setting.append(68.30)
overshoot_results.append(f108_test_overshoot)
setting_results.append(f108_test_setting)
f144_offsets = [108.71, 116.62, 124.52, 132.43,
                140.33, 148.24, 156.14, 164.05, 171.95, 179.86, ]
f_neighbours.append(f144_offsets)
f144_test_overshoot = []
f144_test_setting = []
f144_test_overshoot.append(13.35)
f144_test_setting.append(74.07)
f144_test_overshoot.append(10.24)
f144_test_setting.append(83.66)
f144_test_overshoot.append(float('NaN'))
f144_test_setting.append(float('NaN'))
f144_test_overshoot.append(5.47)
f144_test_setting.append(64.56)
f144_test_overshoot.append(float('NaN'))
f144_test_setting.append(float('NaN'))
f144_test_overshoot.append(10.48)
f144_test_setting.append(71.63)
f144_test_overshoot.append(8.55)
f144_test_setting.append(64.11)
f144_test_overshoot.append(float('NaN'))
f144_test_setting.append(float('NaN'))
f144_test_overshoot.append(7.40)
f144_test_setting.append(57.88)
f144_test_overshoot.append(3.91)
f144_test_setting.append(56.13)
overshoot_results.append(f144_test_overshoot)
setting_results.append(f144_test_setting)
f179_offsets = [144.29, 152.19, 160.10, 168.00,
                175.90, 183.81, 191.71, 199.62, 207.52, 215.43, ]
f_neighbours.append(f179_offsets)
f179_test_overshoot = []
f179_test_setting = []
f179_test_overshoot.append(8.08)
f179_test_setting.append(70.50)
f179_test_overshoot.append(12.86)
f179_test_setting.append(69.90)
f179_test_overshoot.append(15.51)
f179_test_setting.append(97.98)
f179_test_overshoot.append(float('NaN'))
f179_test_setting.append(float('NaN'))
f179_test_overshoot.append(7.23)
f179_test_setting.append(56.71)
f179_test_overshoot.append(12.42)
f179_test_setting.append(59.14)
f179_test_overshoot.append(float('NaN'))
f179_test_setting.append(float('NaN'))
f179_test_overshoot.append(float('NaN'))
f179_test_setting.append(float('NaN'))
f179_test_overshoot.append(7.36)
f179_test_setting.append(50.66)
f179_test_overshoot.append(5.72)
f179_test_setting.append(50.96)
overshoot_results.append(f179_test_overshoot)
setting_results.append(f179_test_setting)
f215_offsets = [179.86, 187.76, 195.67, 203.57,
                211.48, 219.38, 227.29, 235.19, 243.10, 251.00, ]
f_neighbours.append(f215_offsets)
f215_test_overshoot = []
f215_test_setting = []
f215_test_overshoot.append(7.23)
f215_test_setting.append(54.90)
f215_test_overshoot.append(7.97)
f215_test_setting.append(56.82)
f215_test_overshoot.append(float('NaN'))
f215_test_setting.append(float('NaN'))
f215_test_overshoot.append(float('NaN'))
f215_test_setting.append(float('NaN'))
f215_test_overshoot.append(8.26)
f215_test_setting.append(53.40)
f215_test_overshoot.append(10.51)
f215_test_setting.append(52.63)
f215_test_overshoot.append(8.18)
f215_test_setting.append(52.84)
f215_test_overshoot.append(float('NaN'))
f215_test_setting.append(float('NaN'))
f215_test_overshoot.append(float('NaN'))
f215_test_setting.append(float('NaN'))
f215_test_overshoot.append(float('NaN'))
f215_test_setting.append(float('NaN'))
overshoot_results.append(f215_test_overshoot)
setting_results.append(f215_test_setting)
f251_offsets = [215.43, 223.33, 231.24, 239.14,
                247.05, 254.95, 262.86, 270.76, 278.67, 286.57, ]
f_neighbours.append(f251_offsets)
f251_test_overshoot = []
f251_test_setting = []
f251_test_overshoot.append(11.18)
f251_test_setting.append(51.49)
f251_test_overshoot.append(8.37)
f251_test_setting.append(51.31)
f251_test_overshoot.append(float('NaN'))
f251_test_setting.append(float('NaN'))
f251_test_overshoot.append(float('NaN'))
f251_test_setting.append(float('NaN'))
f251_test_overshoot.append(float('NaN'))
f251_test_setting.append(float('NaN'))
f251_test_overshoot.append(float('NaN'))
f251_test_setting.append(float('NaN'))
f251_test_overshoot.append(18.70)
f251_test_setting.append(167.26)
f251_test_overshoot.append(4.36)
f251_test_setting.append(44.67)
f251_test_overshoot.append(2.85)
f251_test_setting.append(43.15)
f251_test_overshoot.append(5.05)
f251_test_setting.append(45.95)
overshoot_results.append(f251_test_overshoot)
setting_results.append(f251_test_setting)
f286_offsets = [251.00, 258.90, 266.81, 274.71,
                282.62, 290.52, 298.43, 306.33, 314.24, 322.14, ]
f_neighbours.append(f286_offsets)
f286_test_overshoot = []
f286_test_setting = []
f286_test_overshoot.append(float('NaN'))
f286_test_setting.append(float('NaN'))
f286_test_overshoot.append(float('NaN'))
f286_test_setting.append(float('NaN'))
f286_test_overshoot.append(6.01)
f286_test_setting.append(44.38)
f286_test_overshoot.append(0.00)
f286_test_setting.append(43.78)
f286_test_overshoot.append(8.63)
f286_test_setting.append(46.55)
f286_test_overshoot.append(6.25)
f286_test_setting.append(46.96)
f286_test_overshoot.append(float('NaN'))
f286_test_setting.append(float('NaN'))
f286_test_overshoot.append(float('NaN'))
f286_test_setting.append(float('NaN'))
f286_test_overshoot.append(float('NaN'))
f286_test_setting.append(float('NaN'))
f286_test_overshoot.append(float('NaN'))
f286_test_setting.append(float('NaN'))
overshoot_results.append(f286_test_overshoot)
setting_results.append(f286_test_setting)
f322_offsets = [286.57, 294.48, 302.38, 310.29,
                318.19, 326.10, 334.00, 341.90, 349.81, 357.71, ]
f_neighbours.append(f322_offsets)
f322_test_overshoot = []
f322_test_setting = []
f322_test_overshoot.append(7.61)
f322_test_setting.append(47.16)
f322_test_overshoot.append(10.47)
f322_test_setting.append(55.12)
f322_test_overshoot.append(float('NaN'))
f322_test_setting.append(float('NaN'))
f322_test_overshoot.append(float('NaN'))
f322_test_setting.append(float('NaN'))
f322_test_overshoot.append(float('NaN'))
f322_test_setting.append(float('NaN'))
f322_test_overshoot.append(float('NaN'))
f322_test_setting.append(float('NaN'))
f322_test_overshoot.append(float('NaN'))
f322_test_setting.append(float('NaN'))
f322_test_overshoot.append(float('NaN'))
f322_test_setting.append(float('NaN'))
f322_test_overshoot.append(float('NaN'))
f322_test_setting.append(float('NaN'))
f322_test_overshoot.append(float('NaN'))
f322_test_setting.append(float('NaN'))
overshoot_results.append(f322_test_overshoot)
setting_results.append(f322_test_setting)
f357_offsets = [322.14, 330.05, 337.95, 345.86,
                353.76, 361.67, 369.57, 377.48, 385.38, 393.29, ]
f_neighbours.append(f357_offsets)
f357_test_overshoot = []
f357_test_setting = []
f357_test_overshoot.append(float('NaN'))
f357_test_setting.append(float('NaN'))
f357_test_overshoot.append(float('NaN'))
f357_test_setting.append(float('NaN'))
f357_test_overshoot.append(float('NaN'))
f357_test_setting.append(float('NaN'))
f357_test_overshoot.append(float('NaN'))
f357_test_setting.append(float('NaN'))
f357_test_overshoot.append(float('NaN'))
f357_test_setting.append(float('NaN'))
f357_test_overshoot.append(0.00)
f357_test_setting.append(281.48)
f357_test_overshoot.append(0.00)
f357_test_setting.append(181.87)
f357_test_overshoot.append(0.00)
f357_test_setting.append(188.73)
f357_test_overshoot.append(0.22)
f357_test_setting.append(191.74)
f357_test_overshoot.append(1.30)
f357_test_setting.append(211.90)
overshoot_results.append(f357_test_overshoot)
setting_results.append(f357_test_setting)
f393_offsets = [357.71, 365.62, 373.52, 381.43,
                389.33, 397.24, 405.14, 413.05, 420.95, 428.86, ]
f_neighbours.append(f393_offsets)
f393_test_overshoot = []
f393_test_setting = []
f393_test_overshoot.append(float('NaN'))
f393_test_setting.append(float('NaN'))
f393_test_overshoot.append(0.00)
f393_test_setting.append(105.43)
f393_test_overshoot.append(0.00)
f393_test_setting.append(105.48)
f393_test_overshoot.append(0.04)
f393_test_setting.append(110.67)
f393_test_overshoot.append(0.78)
f393_test_setting.append(112.81)
f393_test_overshoot.append(2.59)
f393_test_setting.append(113.44)
f393_test_overshoot.append(4.01)
f393_test_setting.append(118.67)
f393_test_overshoot.append(float('NaN'))
f393_test_setting.append(float('NaN'))
f393_test_overshoot.append(float('NaN'))
f393_test_setting.append(float('NaN'))
f393_test_overshoot.append(float('NaN'))
f393_test_setting.append(float('NaN'))
overshoot_results.append(f393_test_overshoot)
setting_results.append(f393_test_setting)
f428_offsets = [393.29, 401.19, 409.10, 417.00,
                424.90, 432.81, 440.71, 448.62, 456.52, 464.43, ]
f_neighbours.append(f428_offsets)
f428_test_overshoot = []
f428_test_setting = []
f428_test_overshoot.append(1.66)
f428_test_setting.append(94.03)
f428_test_overshoot.append(3.62)
f428_test_setting.append(95.31)
f428_test_overshoot.append(5.30)
f428_test_setting.append(105.52)
f428_test_overshoot.append(float('NaN'))
f428_test_setting.append(float('NaN'))
f428_test_overshoot.append(float('NaN'))
f428_test_setting.append(float('NaN'))
f428_test_overshoot.append(float('NaN'))
f428_test_setting.append(float('NaN'))
f428_test_overshoot.append(float('NaN'))
f428_test_setting.append(float('NaN'))
f428_test_overshoot.append(float('NaN'))
f428_test_setting.append(float('NaN'))
f428_test_overshoot.append(float('NaN'))
f428_test_setting.append(float('NaN'))
f428_test_overshoot.append(float('NaN'))
f428_test_setting.append(float('NaN'))
overshoot_results.append(f428_test_overshoot)
setting_results.append(f428_test_setting)
f464_offsets = [428.86, 436.76, 444.67, 452.57,
                460.48, 468.38, 476.29, 484.19, 492.10, 500.00, ]
f_neighbours.append(f464_offsets)
f464_test_overshoot = []
f464_test_setting = []
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
f464_test_overshoot.append(float('NaN'))
f464_test_setting.append(float('NaN'))
overshoot_results.append(f464_test_overshoot)
setting_results.append(f464_test_setting)
f500_offsets = [464.43, 468.38, 472.33, 476.29,
                480.24, 484.19, 488.14, 492.10, 496.05, 500.00, ]
f_neighbours.append(f500_offsets)
f500_test_overshoot = []
f500_test_setting = []
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
f500_test_overshoot.append(float('NaN'))
f500_test_setting.append(float('NaN'))
overshoot_results.append(f500_test_overshoot)
setting_results.append(f500_test_setting)

f_offsets = [f2_offsets, f37_offsets, f73_offsets, f108_offsets, f144_offsets, f179_offsets, f215_offsets,
             f251_offsets, f286_offsets, f322_offsets, f357_offsets, f393_offsets, f428_offsets, f464_offsets, f500_offsets]

# 删除震荡点 从offset，overshoot，setting三个里删除


f_test = np.array(f_test)
f_neighoburs = np.array(f_neighbours)
overshoot_results = np.array(overshoot_results)
setting_results = np.array(setting_results)


"""
# 原始大图
figure = plt.figure()

for i in range(len(f_test)):
    # 超调
    plt.subplot(2, 1, 1)

    # 对每组offset,画出一根线，叠加在一个图里
    current_offset = np.array(f_offsets[i])

    current_overshoot = np.array(overshoot_results[i]).astype(np.double)
    overshoot_mask = np.isfinite(current_overshoot)

    current_setting = np.array(setting_results[i]).astype(np.double)
    setting_mask = np.isfinite(current_setting)
    # 超调：
    # 有效数据
    plt.plot(current_offset[overshoot_mask],
             current_overshoot[overshoot_mask], marker="o", label=str(f_test[i]))
    # 无效数据：
    plt.scatter(current_offset[np.invert(overshoot_mask)], np.zeros(
        len(current_offset))[np.invert(overshoot_mask)], marker="*", color="r")
    plt.ylabel("Overshoot (%)", fontsize=20)
    plt.xlabel("PID Frequency (Hz)", fontsize=20)
    plt.legend()

    # 调节时间：
    plt.subplot(2, 1, 2)
    # 有效数据：
    plt.plot(current_offset[setting_mask],
             current_setting[setting_mask], marker="o", label=str(f_test[i]))
    # 无效数据：
    plt.scatter(current_offset[np.invert(setting_mask)], np.zeros(
        len(current_offset))[np.invert(setting_mask)], marker="*", color="r")
    plt.ylabel("Setting time (ms)", fontsize=20)
    plt.xlabel("PID Frequency (Hz)", fontsize=20)
    plt.ylim([-5, 200])
    plt.legend()
plt.show()
"""
"""
# 中频
figure = plt.figure(figsize=(6,8))
for i in range(1,8):
    # 超调
    plt.subplot(2, 1, 1)

    # 对每组offset,画出一根线，叠加在一个图里
    current_offset = np.array(f_offsets[i])

    current_overshoot = np.array(overshoot_results[i]).astype(np.double)
    overshoot_mask = np.isfinite(current_overshoot)

    current_setting = np.array(setting_results[i]).astype(np.double)
    setting_mask = np.isfinite(current_setting)
    # 超调：
    # 有效数据
    plt.plot(current_offset[overshoot_mask],
             current_overshoot[overshoot_mask], marker="o", label=str(f_test[i]))
    # 无效数据：
    plt.scatter(current_offset[np.invert(overshoot_mask)], np.zeros(
        len(current_offset))[np.invert(overshoot_mask)], marker="*", color="r")
    plt.ylabel("Overshoot (%)", fontsize=10)
    plt.xlabel("PID Frequency (Hz)", fontsize=10)
    my_x_ticks = np.arange(35, 235, 10)      #显示范围为-5至5，每10显示一刻度
    plt.xticks(my_x_ticks)
    plt.xlim([35,235])
    plt.legend()

    # 调节时间：
    plt.subplot(2, 1, 2)
    # 有效数据：
    plt.plot(current_offset[setting_mask],
             current_setting[setting_mask], marker="o", label=str(f_test[i]))
    # 无效数据：
    plt.scatter(current_offset[np.invert(setting_mask)], np.zeros(
        len(current_offset))[np.invert(setting_mask)], marker="*", color="r")
    plt.ylabel("Setting time (ms)", fontsize=10)
    plt.xlabel("PID Frequency (Hz)", fontsize=10)
    plt.ylim([-5, 200])
    plt.xticks(my_x_ticks)
    plt.xlim([35,235])
    plt.legend()
plt.show()
"""
"""
# 高频
figure = plt.figure(figsize=(6,8))
for i in range(7,15):
    # 超调
    plt.subplot(2, 1, 1)

    # 对每组offset,画出一根线，叠加在一个图里
    current_offset = np.array(f_offsets[i])

    current_overshoot = np.array(overshoot_results[i]).astype(np.double)
    overshoot_mask = np.isfinite(current_overshoot)

    current_setting = np.array(setting_results[i]).astype(np.double)
    setting_mask = np.isfinite(current_setting)
    # 超调：
    # 有效数据
    plt.plot(current_offset[overshoot_mask],
             current_overshoot[overshoot_mask], marker="o", label=str(f_test[i]))
    # 无效数据：
    plt.scatter(current_offset[np.invert(overshoot_mask)], np.zeros(
        len(current_offset))[np.invert(overshoot_mask)], marker="*", color="r")
    plt.ylabel("Overshoot (%)", fontsize=10)
    plt.xlabel("PID Frequency (Hz)", fontsize=10)
    #my_x_ticks = np.arange(35, 235, 10)      #显示范围为-5至5，每10显示一刻度
   #plt.xticks(my_x_ticks)
    plt.ylim({-0.8,32})
    plt.xlim([225,505])
    plt.legend()

    # 调节时间：
    plt.subplot(2, 1, 2)
    # 有效数据：
    plt.plot(current_offset[setting_mask],
             current_setting[setting_mask], marker="o", label=str(f_test[i]))
    # 无效数据：
    plt.scatter(current_offset[np.invert(setting_mask)], np.zeros(
        len(current_offset))[np.invert(setting_mask)], marker="*", color="r")
    plt.ylabel("Setting time (ms)", fontsize=10)
    plt.xlabel("PID Frequency (Hz)", fontsize=10)
    plt.ylim([-5, 200])
    #plt.xticks(my_x_ticks)
    plt.xlim([225,505])
    plt.legend()
plt.show()
"""

Ki = np.array([0.045, 1.20, 1.73, 2.34, 2.50, 2.63, 2.72, 2.86, 2.89, 2.92, 0.35, 0.7, 0.9, 0.9, 0.9])
Kd = np.array([1000, 3.243, 2.52, 2.55, 2.19, 2.05, 1.97, 1.93, 1.91, 1.89, 2.9, 2.9, 2.9, 2.9, 2.9])

"""
# Ki变化趋势的分析：
fig=plt.figure(figsize=[9,4])
for i in range(len(f_test)):
    plt.plot(f_test,Ki,marker="o",color="b")
    plt.ylim([-0.1,3.0])
    plt.vlines(f_test[9],-1,10,colors="r")
    my_x_ticks = np.array(f_test)
    plt.xticks(my_x_ticks)
    plt.ylabel("Ki",fontsize="12")
    plt.xlabel("f (Hz)",fontsize="12")
    plt.grid(linestyle=":")
plt.show()
"""


# Kd变化趋势的分析
fig=plt.figure(figsize=[9,4])
for i in range(len(f_test)):
    plt.plot(f_test,Kd,marker="o",color="b")
    plt.ylim([1.5,3.0])
    plt.vlines(f_test[9],-1,10,colors="r")
    my_x_ticks = np.array(f_test)
    plt.xticks(my_x_ticks,fontsize="10")
    plt.yticks(fontsize="12")
    plt.ylabel("Ki",fontsize="14")
    plt.xlabel("f (Hz)",fontsize="12")
    plt.grid(linestyle=":")
plt.show()





