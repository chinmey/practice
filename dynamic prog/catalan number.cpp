/*1) Count the number of expressions containing n pairs of parentheses which are correctly matched. For n = 3, possible expressions are ((())), ()(()), ()()(), (())(), (()()).

2) Count the number of possible Binary Search Trees with n keys (See this)

3) Count the number of full binary trees (A rooted binary tree is full if every vertex has either two children or no children) with n+1 leaves.

See this for more applications.

The first few Catalan numbers for n = 0, 1, 2, 3, … are 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, …

Catalan numbers satisfy the following recursive formula.
C0 =1 and  C[n+1]=summation from i=0 to n (C[i]*C[n-i]) */

#include<iostream>
using namespace std;

// A dynamic programming based function to find nth
// Catalan number
unsigned long int catalanDP(unsigned int n)
{
	// Table to store results of subproblems
	unsigned long int catalan[n+1];

	// Initialize first two values in table
	catalan[0] = catalan[1] = 1;

	// Fill entries in catalan[] using recursive formula
	for (int i=2; i<=n; i++)
	{
		catalan[i] = 0;
		for (int j=0; j<i; j++)
			catalan[i] += catalan[j] * catalan[i-j-1];
	}

	// Return last entry
	return catalan[n];
}

// Driver program to test above function
int main()
{
	for (int i = 0; i < 10; i++)
		cout << catalanDP(i) << " ";
	return 0;
}
/*---------------------------------------------------------------------------------------------*/



