#include <bits/stdc++.h>
using namespace std;

// Print all subsets if there is atleast one subset of set[]
// with sum equal to given sum
void PrintSubsetSum(int i, int n, int set[], int targetSum,
					vector<int>& subset)
{
	// targetSum is zero then there exist a
	// subset.
	if (targetSum == 0) {

		// Prints valid subset
		for (int i = 0; i < subset.size(); i++) {
			cout << subset[i] << " ";
		}
		cout << endl;
		return;
	}

	if (i == n) {
		// return if we have reached at the end of the array
		return;
	}

	// Not considering current element
	PrintSubsetSum(i + 1, n, set, targetSum, subset);

	// consider current element if it is less than or equal
	// to targetSum
	if (set[i] <= targetSum) {

		// push the current element in subset
		subset.push_back(set[i]);

		// Recursive call for consider current element
		PrintSubsetSum(i + 1, n, set, targetSum - set[i],
					subset);

		// pop-back element after recursive call to restore
		// subsets original configuration
		subset.pop_back();
	}
}

// Driver code
int main()
{
	int set[] = { 1,2,3,3,4,5 };
	int sum = 10;
	int n = sizeof(set) / sizeof(set[0]);
	vector<int> subset;
	PrintSubsetSum(0, n, set, sum, subset);
	return 0;
}
// This code is contributed by Hem Kishan

