Find number of solutions of a linear equation of n variables

Input:  coeff[] = {1, 2}, rhs = 5
Output: 3
The equation "x + 2y = 5" has 3 solutions.
(x=3,y=1), (x=1,y=2), (x=5,y=0)

Input:  coeff[] = {2, 2, 3}, rhs = 4
Output: 3
The equation "2x + 2y + 3z = 4"  has 3 solutions.
(x=0,y=2,z=0), (x=2,y=0,z=0), (x=1,y=1,z=0)

// A naive recursive C++ program to
// find number of non-negative solutions
// for a given linear equation
#include<bits/stdc++.h>
using namespace std;

// Recursive function that returns
// count of solutions for given rhs
// value and coefficients coeff[start..end]
int countSol(int coeff[], int start,
			int end, int rhs)
{
	// Base case
	if (rhs == 0)
	return 1;

	// Initialize count
	// of solutions
	int result = 0;

	// One by subtract all smaller or
	// equal coefficiants and recur
	for (int i = start; i <= end; i++)
	if (coeff[i] <= rhs)
		result += countSol(coeff, i, end,
						rhs - coeff[i]);

	return result;
}

// Driver Code
int main()
{
	int coeff[] = {2, 2, 5};
	int rhs = 4;
	int n = sizeof(coeff) / sizeof(coeff[0]);
	cout << countSol(coeff, 0, n - 1, rhs);
	return 0;
}


// A Dynamic programming based C++
// program to find number of non-negative
// solutions for a given linear equation
#include<bits/stdc++.h>
using namespace std;

// Returns count of solutions for
// given rhs and coefficients coeff[0..n-1]
int countSol(int coeff[], int n, int rhs)
{
	// Create and initialize a table
	// to store results of subproblems
	int dp[rhs + 1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	// Fill table in bottom up manner
	for (int i = 0; i < n; i++)
	for (int j = coeff[i]; j <= rhs; j++)
		dp[j] += dp[j - coeff[i]];

	return dp[rhs];
}

// Driver Code
int main()
{
	int coeff[] = {2, 2, 5};
	int rhs = 4;
	int n = sizeof(coeff) / sizeof(coeff[0]);
	cout << countSol(coeff, n, rhs);
	return 0;
}
