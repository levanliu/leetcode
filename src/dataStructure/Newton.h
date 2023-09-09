#ifndef LANGUAGEBASIC_NEWTON_H
#define LANGUAGEBASIC_NEWTON_H

#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

/**
 * 利用牛顿法求较高精度根号x的值
 * input: 10 2
 * output: 10 5.1 2.74607843137 1.73719487438 1.44423809487 1.41452565515 1.4142135968 1.41421356237
 */

class Newton
{
public:
    long double fAndDf(long double x, long double num)
    {
        // 定义f(x)表达式
        long double fx = x * x - num;
        // 定义f'(x)表达式
        long double dfx = 2 * x;
        return fx / dfx;
    }

    void newton(long double initPos, long double num, long double precision)
    {
        long double ans = initPos;
        long double x1 = ans - fAndDf(ans, num);
        int i = 0;

        while (abs(x1 - ans) > precision && i < 100)
        {
            // 设置输出精度
            cout << setprecision(12) << ans << " ";
            ans = x1;
            // 牛顿法原理 x1=x0-f(x)/f'(x)
            x1 = x1 - fAndDf(x1, num);
            i++;
        }
    }

    void NewtonMain()
    {
        // 初始位置和所求的值
        long double initPos, num;
        // 计算精度
        long double precision = 1e-64;
        cin >> initPos >> num;
        newton(initPos, num, precision);
    }
};
#endif