#ifndef DATASTRUCTURE_TRIE_H
#define DATASTRUCTURE_TRIE_H

/**
 * 高效的存储和查找字符串，集合的数据结构
 * abcdef
 * addef
 * find root has a child? if there isn't,create a;
 * then recurrence a;
 * so same as anther child.
 *
 * and need a start mark there is a word!
 *
 * acwing 835 Trie String count
 * */

#include <iostream>
using namespace std;
class Trie
{
private:
    static const int N = 100010;
    int son[N][26], cnt[N], idx; // index is zero, is root and null;
    char str[N];

public:
    void insert(char str[])
    {
        int p = 0;
        for (int i = 0; str[i]; i++)
        {
            int u = str[i] - 'a';
            if (!son[p][u])
                son[p][u] = ++idx;
            p = son[p][u];
        }
        cnt[p]++;
    }
    int query(char str[])
    {
        int p = 0;
        for (int i = 0; str[i]; i++)
        {
            int u = str[i] - 'a';
            if (!son[p][u])
                return 0;
            p = son[p][u];
        }
        return cnt[p];
    }
    int trieMain()
    {
        int n;
        scanf("%d", &n);
        while (n--)
        {
            char op[2];
            scanf("%s%s", op, str);
            if (op[0] == 'I')
                insert(str);
            else
                printf("%d\n", query(str));
        }
        return 0;
    }
};

#endif