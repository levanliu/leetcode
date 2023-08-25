//
// Created by le on 14/11/2022.
//

#ifndef LANGUAGEBASIC_UNIONFIND_H
#define LANGUAGEBASIC_UNIONFIND_H
/** 并查集
 * 快速的处理
 * 1、将两个集合合并
 * 2、询问两个元素是否在一个集合当中
 * belong[x] = a
 * if(belong[x] == belong[y]) O(1)
 *
 * 集合1 是一个 树，   集合2 也是一个 树
 * 根结点的编号就是 该集合的编号。  每个结点存一下其父亲节点 p(x)
 * 快速的找到每一个元素是属于 某一个集合的
 *
 * 1、如何判断树根， if(p[x] == x)
 * 2、如何求x的集合编号 while(p[x] != x) x = p[x];
 * 3、如何合并两个集合  p[x]是x的集合， p[y]是y的集合，p[x] = y；
 *
 * Acwing 836 合并集合
 */
#include <iostream>

using namespace std;

class UnionFind
{

public:
    static const int N = 100010;
    int p[N];
    int find(int x) // 返回x的祖宗节点 + 路径压缩
    {
        // 如果x不是祖先，则让 x父亲的祖先 变为 x的父亲
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    void unionFindMain()
    {
        int n, m;
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            p[i] = i;

        while (m--)
        {
            char op[2];
            int a, b;
            scanf("%s%d%d", op, &a, &b);
            // 合并是让 b的祖先 变为 a祖先的 父亲
            if (op[0] == 'M')
                p[find(a)] = find(b);
            else
            {
                if (find(a) == find(b))
                    puts("Yes");
                else
                    puts("No");
            }
        }
    }
};

#endif // LANGUAGEBASIC_UNIONFIND_H
