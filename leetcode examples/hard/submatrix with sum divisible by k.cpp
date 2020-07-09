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



submatrix with all one  // check copy for more detail

int numSubmat(vector<vector<int>>& mat)
	{
		int n=mat.size();
		int m=mat[0].size();
		int ar[n][m];
		
		// pre computation 
		for(int i=0;i<n;i++)
		{
			int c=0;
			for(int j=m-1;j>=0;j--)
			{
				if(mat[i][j])
				{
					c++;
				}
				else
				{
					c=0;
				}
				ar[i][j]=c;
			}
		}
		int ans=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
			// i, j is the top most left point of the rectangle which is fixed 
				int x=INT_MAX;
				for(int k=i;k<n;k++)
				{
					x=min(x,ar[k][j]);
					ans+=x;
				}
			}
		}
		return ans;
	}

