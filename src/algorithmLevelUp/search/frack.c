// y <= 2k
#include <stdio.h>
int main()
{
    int k;
    scanf("%d", &k);
    for (int y = k + 1; y <= 2 * k; y++)
    {
        if ((k * y) % (y - k) == 0)
        {
            printf("1/%d = 1/%d +1/%d\n", k, (k * y) / (y - k), y);
        }
    }
}
