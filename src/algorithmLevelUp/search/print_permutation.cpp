#include <stdio.h>

void print_permutation(int n, int *A, int cur)
{
    if (cur == n)
    {
        for (int i = 0; i < n; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    else
    {
        for (int i = 1; i <= n; i++)
        {
            bool ok = 1;
            for (int j = 0; j < cur; j++)
            {
                if (A[j] == i)
                {
                    ok = 0;
                }
            }
            if (ok)
            {
                A[cur] = i;
                print_permutation(n, A, cur + 1);
            }
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int A[9];
    print_permutation(n, A, 0);
    return 0;
}