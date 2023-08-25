//
// Created by le on 2/11/2022.
//

#ifndef DATASTRUCTURE_Thread_H
#define DATASTRUCTURE_Thread_H

#include <iostream>
#include <thread>
using namespace std;

class ThreadTest
{
public:
    const static int N = 2000;
    void static func_2(int begin, int end, int &res)
    {
        res = 0;
        int sum = 0;
        for (int kk = 1; kk < 10; kk++)
            for (int i = begin; i < end; i++)
            {
                sum = (sum + i + 1);
            }
        res = sum;
    }
    void static add(int &a)
    {
        for (int i = 0; i < 10; i++)
        {
            a += 1;
        }
    }
    int static multi_thread()
    {
        int cpu_num = thread::hardware_concurrency(); //12
        int use_cpu_num = cpu_num;
        int split_num = (N + use_cpu_num - 1) / use_cpu_num;
        int k1 = 0, k2 = split_num; // k1,k2切分数组
        int sum = 0;
        int *res = new int[split_num];
        thread *th = new thread[use_cpu_num];
        for (int i = 0; i < use_cpu_num; i++)
        {
            th[i] = thread(func_2, k1, k2, ref(res[i]));
            k1 = k2;
            k2 += split_num;
            if (k2 >= N)
                k2 = N;
        }
        for (int i = 0; i < use_cpu_num; i++)
            th[i].join();
        for (int i = 0; i < use_cpu_num; i++)
        {
            sum = (sum + res[i]);
        }
        return sum;
    }
    int threadTest()
    {
        long c1 = clock();
        int res;
        func_2(0, N, res);
        long c2 = clock();
        cout << "res = " << res << " , time consume = " << c2 - c1 << endl;

        c1 = clock();
        int sum = multi_thread();
        c2 = clock();
        cout << "sum = " << sum << " , time consume = " << c2 - c1 << endl;

        c1 = clock();
        int a = 0;
        thread *th = new thread[5];
        for (int i = 0; i < 5; i++)
        {
            th[i] = thread(add, ref(a));
        }
        for (int i = 0; i < 5; i++)
        {
            th[i].join();
        }

        c2 = clock();
        cout << a << " , time consume = " << c2 - c1 << endl;
        return 0;
    }
};

#endif // DATASTRUCTURE_Thread_H
