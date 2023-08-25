#include <iostream>

using namespace std;

int main()
{
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Create the prefix sum array.
    int prefixSum[n];
    prefixSum[0] = arr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    // Print the prefix sum array.
    for (int i = 0; i < n; i++)
    {
        cout << prefixSum[i] << " ";
    }

    return 0;
}