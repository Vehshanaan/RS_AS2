/*
 * @Author: Runze Yuan 1959180242@qq.com
 * @Date: 2022-11-17 09:20:18
 * @LastEditors: Runze Yuan 1959180242@qq.com
 * @LastEditTime: 2022-11-17 09:29:16
 * @FilePath: \RS_AS2\Experiments\TimeTest\TimeTest.ino
 * @Description:
 *
 * Copyright (c) 2022 by Runze Yuan 1959180242@qq.com, All Rights Reserved.
 */
void setup()
{
    Serial.begin(115200);
    delay(1);
    Serial.println("***RESET***");
}
void loop()
{
    unsigned long micros_start = micros();
    unsigned long millis_start = millis();

    delay(1);

    unsigned long micros_end = micros();
    unsigned long millis_end = millis();

    int millis_duration = millis_end - millis_start;
    int micros_duration = micros_end - micros_start;
    Serial.print("millis:  ");
    Serial.print(millis_duration);
    Serial.print("   micros:   ");
    Serial.println(micros_duration);
}