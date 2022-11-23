
#ifndef INTERPOLATE_H
#define INTERPOLATE_H

/**
 * @description: 
 * @param {double} max 插值区间的最大值
 * @param {double} min 插值区间的最小值
 * @param {int} dot_numbers 所生成插值序列的总点数
 * @param {double*} series 所生成的插值序列的保存数组，长度应为dot_numbers
 * @return {*}
 */
void Interpolate(double max, double min, int dot_numbers,double* series)
{

    double step = (max - min) / (dot_numbers - 1);

    for (int i = 0; i < dot_numbers; i++)
    {
        series[i] = min + i * step;
    }
    return;
}

#endif