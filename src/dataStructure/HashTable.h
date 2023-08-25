#ifndef MAIN_HASHTABLE_H
#define MAIN_HASHTABLE_H

/**
 * 存储结构  开放寻址法 拉链法
 *
 * 字符串哈希方式
 *
 * h(x) belongs (0,10^5)
 *
 * 1、x mod 10^5
 * 2、冲突
 *
 * 拉链法： 开一个10^5的数组
 *
 * 操作：
 * 添加 and 查找
 *
 * */
#include <iostream>
#include <cstring>
using namespace std;

class HashTable
{
private:
    static const int N = 100003;
    int h[N], e[N], ne[N], idx;

public:
    HashTable(/* args */);
    ~HashTable();

    void insert(int x)
    {
        int k = (x % N + N) % N;
        e[idx] = x;
        ne[idx] = h[k];
        h[k] = idx++;
    }

    bool find(int x)
    {
        int k = (x % N + N) % N;
        for (int i = h[k]; i != -1; i = ne[i])
        {
            if (e[i] == x)
                return true;
        }
        return false;
    }

    int hashTableMain()
    {
        int n;
        scanf("%d", &n);
        memset(h, -1, sizeof h);
        while (n--)
        {
            char op[2];
            int x;
            scanf("%s%d", &x);

            if (*op == 'I')
                insert(x);
            else
            {
                if (find(x))
                    puts("Yes");
                else
                    puts("No");
            }
        }
        return 0;
    }
};

HashTable::HashTable(/* args */)
{
}

HashTable::~HashTable()
{
}

class HashTableFindAdd
{
private:
    static const int N = 200003, null = 0x3f3f3f3f;
    int h[N];

public:
    HashTableFindAdd();
    ~HashTableFindAdd();
    int find(int x)
    {
        int k = (x % N + N) % N;
        while (h[k] != null && h[k] != x)
        {
            k++;
            if (k == N)
                k = 0;
        }
        return k;
    }

    int hashTableFindAddMain()
    {
        int n;
        scanf("%d", &n);
        memset(h, 0x3f, sizeof h);
        while (n--)
        {
            char op[2];
            int x;
            scanf("%s%d", op, &x);
            int k = find(x);
            if (*op == 'I')
                h[k] = x;
            else
            {
                if (h[k] != null)
                    puts("Yes");
                else
                    puts("No");
            }
        }
        return 0;
    }
};

HashTableFindAdd::HashTableFindAdd(/* args */)
{
}

HashTableFindAdd::~HashTableFindAdd()
{
}
#endif