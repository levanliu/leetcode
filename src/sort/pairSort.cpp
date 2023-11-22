#include <iostream>
#include <algorithm>
using namespace std;

typedef pair<int, int> PII;

int main()
{
    int n = 5;
    PII a[n];
    for (int i = 0; i < 5; i++)
    {
        a[i].first = i;
        a[i].second = i * 2;
    }
    sort(a, a + n, [](PII x, PII y)
         {
            if(x.first != y.first)
                return x.second < y.second;
            else
                return x.second > y.second; });
    for (int i = 0; i < 5; i++)
        cout << a[i].first << a[i].second << " ";
    return 0;
}