/*Input: set[] = {9, 8, 5}
Output: 13
The subset {8, 5} has maximum XOR value

Let the input set be : {9, 8, 5}

We start from 31st bit [Assuming Integers are 32 bit
long]. The loop will continue without doing anything till 4'th bit.

The 4th bit is set in set[0] i.e. 9 and this is the maximum
element with 4th bit set. So we choose this element and check
if any other number has the same bit set. If yes, we XOR that
number with 9. The element set[1], i.e., 8 also has 4'th bit
set. Now set[] becomes {9, 1, 5}.  We add 9 to the list of
chosen elements by incrementing 'index'

We move further and find the maximum number with 3rd bit set
which is set[2] i.e. 5  No other number in the array has 3rd
bit set. 5 is also added to the list of chosen element.

We then iterate for bit 2 (no number for this) and then for
1 which is 1. But numbers 9 and 5 have the 1st bit set. Thus
we XOR 9 and 5 with 1 and our set becomes (8, 1, 4)

Finally, we XOR current elements of set and get the result
as 8 ^ 1 ^ 4 = 13.*/

// C++ program to find
// maximum XOR subset
#include<bits/stdc++.h>
using namespace std;

// Number of bits to
// represent int
#define INT_BITS 32

// Function to return
// maximum XOR subset
// in set[]
int maxSubarrayXOR(int set[], int n)
{
	// Initialize index of
	// chosen elements
	int index = 0;

	// Traverse through all
	// bits of integer
	// starting from the most
	// significant bit (MSB)
	for (int i = INT_BITS-1; i >= 0; i--)
	{
		// Initialize index of
		// maximum element and
		// the maximum element
		int maxInd = index;
		int maxEle = INT_MIN;
		for (int j = index; j < n; j++)
		{
			// If i'th bit of set[j]
			// is set and set[j] is
			// greater than max so far.
			if ( (set[j] & (1 << i)) != 0
					&& set[j] > maxEle )
				maxEle = set[j], maxInd = j;
		}

		// If there was no
		// element with i'th
		// bit set, move to
		// smaller i
		if (maxEle == INT_MIN)
		continue;

		// Put maximum element
		// with i'th bit set
		// at index 'index'
		swap(set[index], set[maxInd]);

		// Update maxInd and
		// increment index
		maxInd = index;

		// Do XOR of set[maxIndex]
		// with all numbers having
		// i'th bit as set.
		for (int j=0; j<n; j++)
		{
			// XOR set[maxInd] those
			// numbers which have the
			// i'th bit set
			if (j != maxInd &&
			(set[j] & (1 << i)) != 0)
				set[j] = set[j] ^ set[maxInd];
		}

		// Increment index of
		// chosen elements
		index++;
	}

	// Final result is
	// XOR of all elements
	int res = 0;
	for (int i = 0; i < n; i++)
		res ^= set[i];
	return res;
}

// Driver program
int main()
{
	int set[] = {9, 8, 5};
	int n = sizeof(set) / sizeof(set[0]);

	cout << "Max subset XOR is ";
	cout << maxSubarrayXOR(set, n);
	return 0;
}

