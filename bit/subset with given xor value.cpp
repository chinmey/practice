Given an array arr[] of n numbers and a number K, find the number of subsets of arr[] having XOR of elements as K

Input:   arr[]  = {1, 2, 3, 4, 5}, k = 4
Output:  4
The subsets are {1, 5}, {4}, {1, 2, 3, 4}
                and {2, 3, 5}

We define a number m such that m = pow(2,(log2(max(arr))+1))­ – 1. This number is actually the maximum value any XOR subset will acquire. We get this number by counting bits in largest number. We create a 2D array dp[n+1][m+1], such that dp[i][j] equals to the number of subsets having XOR value j from subsets of arr[0…i-1].
such that dp[i][j] equals to the number of subsets having XOR value j from subsets of arr[0…i-1].
We fill the dp array as following:

We initialize all values of dp[i][j] as 0.
Set value of dp[0][0] = 1 since XOR of an empty set is 0.
Iterate over all the values of arr[i] from left to right and for each arr[i], iterate over all the possible values of XOR i.e from 0 to m (both inclusive) and fill the dp array asfollowing:
       for i = 1 to n:
             for j = 0 to m:
                   dp[i][j] = dp[i­1][j] + dp[i­1][j^arr[i-1]]
This can be explained as, if there is a subset arr[0…i­2] with XOR value j, then there also exists a subset arr[0…i-1] with XOR value j. also if there exists a subset arr[0….i-2] with XOR value j^arr[i] then clearly there exist a subset arr[0…i-1] with XOR value j, as j ^ arr[i-1] ^ arr[i-1] = j.
Counting the number of subsets with XOR value k: Since dp[i][j] is the number of subsets having j as XOR value from the subsets of arr[0..i-1], then the number of subsets from set arr[0..n] having XOR value as K will be dp[n][K]

// arr dynamic programming solution to finding the number
// of subsets having xor of their elements as k
#include<bits/stdc++.h>
using namespace std;

// Returns count of subsets of arr[] with XOR value equals
// to k.
int subsetXOR(int arr[], int n, int k)
{
	// Find maximum element in arr[]
	int max_ele = arr[0];
	for (int i=1; i<n; i++)
	if (arr[i] > max_ele)
		max_ele = arr[i];

	// Maximum possible XOR value
	int m = (1 << (int)(log2(max_ele) + 1) ) - 1;

	// The value of dp[i][j] is the number of subsets having
	// XOR of their elements as j from the set arr[0...i-1]
	int dp[n+1][m+1];

	// Initializing all the values of dp[i][j] as 0
	for (int i=0; i<=n; i++)
		for (int j=0; j<=m; j++)
			dp[i][j] = 0;

	// The xor of empty subset is 0
	dp[0][0] = 1;

	// Fill the dp table
	for (int i=1; i<=n; i++)
		for (int j=0; j<=m; j++)
			dp[i][j] = dp[i-1][j] + dp[i-1][j^arr[i-1]];

	// The answer is the number of subset from set
	// arr[0..n-1] having XOR of elements as k
	return dp[n][k];
}

// Driver program to test above function
int main()
{
	int arr[] = {1, 2, 3, 4, 5};
	int k = 4;
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << "Count of subsets is " << subsetXOR(arr, n, k);
	return 0;
}
