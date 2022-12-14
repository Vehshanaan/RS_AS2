# **电机驱动方法Motor.setMotor()在使用前要校正！**

## 关于死区校正的方法：
1. ###  给电机输入PWM值，记录到底要多高电机才会开始运转，设此值为thres
1. ### 将电机驱动类中给电机写的PWM值重新映射，将0-255映射至thres~255的范围内

## 举例：
>1. 测试死区范围，我的电机直到输入提升到17才能开始空转，提升到更高才能拖着机器人在地面上运行
>1. 这个实验只需要电机空转，不需要机器人在地上走，所以死区就按空转的先来就行了，把死区范围记为17
>1. 计算：(255-17) / 255, 得到0.933，即**重映射参数**
>1. 如何使用这个结果？ `实际驱动电机的PWM值` = `输入的控制量` * 0.933 + 17。 此处`输入的控制量`就是Motor.setPower(L,R)里的L，R，然后经过这个公式映射，再把得到的`实际驱动电机的PWM值`用来驱动电机，analogWrite（`实际驱动电机的PWM值`），这样来一定程度上消除死区
## 所以，该怎么校正死区并把程序修改成当前机器人能用的样子?

1. ### PWM值从0开始，驱动电机，直到电机开始动为止，记录这个值`a`
   - 注意，我的电机类的setPower里是我校正后的结果，不要直接用那个驱动电机，可以把我的校正结果先删除掉，再用setPower测试电机死区，我在代码里留了校正前的原始驱动代码
2. ### 计算新的映射参数：`b` = （255-`a`）/255
3. ### 把映射参数套进程序里
```
    // 以左轮为例：
    // LeftMotorPower是最后用来实际驱动电机的值
    // L是输入setPower里的值

    LeftMotorPower = (int)(L*b+a); // b,a就是第1、2步里得到的值（映射参数和死区大小）
    analogWrite(L_PWM_PIN, LeftMotorPower); 
```
4. ### 左右轮子的死区不一样，要校正两次，别忘了
5. ### 测试是不是setPower(1,1)就能让轮子转
