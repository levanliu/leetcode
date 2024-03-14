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



int maxSquare()
{
	const int N = 103;
	int a[N][N];
	int b[N][N];

	int m,n;
	cin >> m >> n;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			cin >> a[i][j];
			b[i][j] = 
	 				b[i][j-1] + b[i-1][j] - b[i-1][j-1] + a[i][j];
		}
	}

	int ans = 1;

	int l = 2;

	while(l < min(m,n)){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=n;j++){
				if(l*l == b[i][j] + b[i-l][j-l] - b[i-l][j] - b[i][j-l]){
					ans = max(ans,l);
				}
			}
		}
		l++;
	}
	return ans;
}
