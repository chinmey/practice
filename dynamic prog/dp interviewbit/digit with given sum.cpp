Given two integers ‘n’ and ‘sum’, find count of all n digit numbers with sum of digits as ‘sum’. Leading 0’s are not counted as digits.
1 <= n <= 100 and
1 <= sum <= 500

Input:  n = 2, sum = 2
Output: 2
Explanation: Numbers are 11 and 20

Input:  n = 2, sum = 5
Output: 5
Explanation: Numbers are 14, 23, 32, 41 and 50

Input:  n = 3, sum = 6
Output: 21


Lets build a recursive approach to this problem. Let rec_Count(id, sum) be the number of numbers having digit count as id and digit sum as sum.
 To be more clear,

rec_Count(id, sum) = summation of rec_Count(id-1,sum-x) where 0 <= x <= 9 && sum-x >= 0.

but we need to handle first digit seperately as it does not allow 0



// A lookup table used for memoization 
unsigned long long int lookup[101][501]; 

// Memoization based implementation of recursive 
// function 
unsigned long long int countRec(int n, int sum) 
{ 
	// Base case 
	if (n == 0) 
	return sum == 0; 

	// If this subproblem is already evaluated, 
	// return the evaluated value 
	if (lookup[n][sum] != -1) 
	return lookup[n][sum]; 

	// Initialize answer 
	unsigned long long int ans = 0; 

	// Traverse through every digit and 
	// recursively count numbers beginning 
	// with it 
	for (int i=0; i<10; i++) 
	if (sum-i >= 0) 
		ans += countRec(n-1, sum-i); 

	return lookup[n][sum] = ans; 
} 

// This is mainly a wrapper over countRec. It 
// explicitly handles leading digit and calls 
// countRec() for remaining n. 
unsigned long long int finalCount(int n, int sum) 
{ 
	// Initialize all entries of lookup table 
	memset(lookup, -1, sizeof lookup); 

	// Initialize final answer 
	unsigned long long int ans = 0; 

	// Traverse through every digit from 1 to 
	// 9 and count numbers beginning with it 
	for (int i = 1; i <= 9; i++) 
	if (sum-i >= 0) 
		ans += countRec(n-1, sum-i); 
	return ans; 
} 

// Driver program 
int main() 
{ 
	int n = 3, sum = 5; 
	cout << finalCount(n, sum); 
	return 0; 
} 
---------------------------------------------------------------------------------------

check out tushor roy maximum sum rectangle in 2d matrix


Given a n x n matrix of integers and a positive integer k. The problem is to count all sub-matrices having sum divisible by the given value k.

Input : mat[][] = { {5, -1, 6},
            {-2, 3, 8},
            {7, 4, -9} }

        k = 4

Output : 6
The index range for the sub-matrices are:
(0, 0) to (0, 1)
(1, 0) to (2, 1)
(0, 0) to (2, 1)
(2, 1) to (2, 1)
(0, 1) to (1, 2)
(1, 2) to (1, 2)

idea: Counting all sub-arrays having sum divisible by k for 1D array can be used to reduce the time complexity to O(n^3). 
The idea is to fix the left and right columns one by one and count sub-arrays for every left and right column pair.
 Calculate sum of elements in every row from left to right and store these sums in an array say temp[].
  So temp[i] indicates sum of elements from left to right in row i. Count sub-arrays in temp[] having sum divisible by k. 
  This count is the number of sub-matrices having sum divisible by k with left and right as boundary columns. 
Sum up all the counts for each temp[] with different left and right column pairs.

// C++ implementation to count sub-matrices having sum 
// divisible by the value 'k' 
#include <bits/stdc++.h> 
using namespace std; 

#define SIZE 10 

int subCount(int arr[], int n, int k) 
{ 
	// create auxiliary hash array to count frequency 
	// of remainders 
	int mod[k]; 
	memset(mod, 0, sizeof(mod)); 

	// Traverse original array and compute cumulative 
	// sum take remainder of this current cumulative 
	// sum and increase count by 1 for this remainder 
	// in mod[] array 
	int cumSum = 0; 
	for (int i = 0; i < n; i++) { 
		cumSum += arr[i]; 

		// as the sum can be negative, taking modulo 
		// twice 
		mod[((cumSum % k) + k) % k]++; 
	} 

	int result = 0; // Initialize result 

	// Traverse mod[] 
	for (int i = 0; i < k; i++) 

		// If there are more than one prefix subarrays 
		// with a particular mod value. 
		if (mod[i] > 1) 
			result += (mod[i] * (mod[i] - 1)) / 2; 

	// add the subarrays starting from the arr[i] 
	// which are divisible by k itself 
	result += mod[0]; 

	return result; 
} 

// function to count all sub-matrices having sum 
// divisible by the value 'k' 
int countSubmatrix(int mat[SIZE][SIZE], int n, int k) 
{ 
	// Variable to store the final output 
	int tot_count = 0; 

	int left, right, i; /* used to traverse array column wise*/
	int temp[n]; /* always equal to number of rows*/

	// Set the left column 
	for (left = 0; left < n/*equal to no of columns*/; left++) { 

		// Initialize all elements of temp as 0 
		memset(temp, 0, sizeof(temp)); 

		// Set the right column for the left column 
		// set by outer loop 
		for (right = left; right < n/*equal to no of columns*/; right++) { 

			// Calculate sum between current left 
			// and right for every row 'i' 
			for (i = 0; i < n/*equal to no of rows*/; ++i) 
				temp[i] += mat[i][right]; 

			// Count number of subarrays in temp[] 
			// having sum divisible by 'k' and then 
			// add it to 'tot_count' 
			tot_count += subCount(temp, n, k); 
		} 
	} 

	// required count of sub-matrices having sum 
	// divisible by 'k' 
	return tot_count; 
} 

// Driver program to test above 
int main() 
{ 
	int mat[][SIZE] = { { 5, -1, 6 }, 
						{ -2, 3, 8 }, 
						{ 7, 4, -9 } }; 
	int n = 3, k = 4; 
	cout << "Count = "
		<< countSubmatrix(mat, n, k); 
	return 0; 
} 


