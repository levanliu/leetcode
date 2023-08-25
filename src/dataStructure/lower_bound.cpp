#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int arr[] = {1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value = 3;

    // Find the first element in the array that is greater than or equal to 3.
    auto it = lower_bound(arr, arr + n, value);

    // If the element was found, print its index.
    if (it != arr + n)
    {
        cout << it - arr << endl;
        cout << *it << endl;
    }
    else
    {
        cout << "The greater than or equal to 3 element was not found." << endl;
    }

    return 0;
}
