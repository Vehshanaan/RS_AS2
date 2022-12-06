'''
Author: Runze Yuan 1959180242@qq.com
Date: 2022-12-06 19:56:20
LastEditors: Runze Yuan 1959180242@qq.com
LastEditTime: 2022-12-06 20:16:17
FilePath: \RS_AS2\Report\Pic\OscillateExample.py
Description: 

Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved. 
'''
import matplotlib.pyplot as plt

x_axis = [0,1,2,3,4,5,6,7,8]
updown = [0.0,1.28,0.70,1.23,0.73,1.20,0.72,1.22,0.74]
steady_error =[0.0,1.10,0.90,1.09,0.92,1.08,0.93,1.07,0.93]

figure = plt.figure()
plt.subplot(2,1,1)
plt.plot(x_axis,updown)
plt.hlines(1.0,-2,9,color="r")
plt.grid(linestyle=":")
plt.ylim([0.6,1.3])
plt.xlim([-0.1,7.1])
plt.title("Oscillate 1): Oscillate in General Sense")
plt.xlabel("time")
plt.ylabel("process value")
plt.subplot(2,1,2)
plt.plot(x_axis,steady_error)
plt.hlines(1.0,-2,9,color="r")
plt.hlines([0.95,1.05],-2,9,color="m",linestyles=":")
plt.grid(linestyle=":")
plt.title("Oscillate 2): Poor Steady State Performance")
plt.ylim([0.6,1.3])
plt.xlim([-0.1,7.1])
plt.xlabel("time")
plt.ylabel("process value")
plt.show()
