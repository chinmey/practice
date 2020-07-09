Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.


Input: arr[]   = {3, 0, 2, 0, 4}
Output: 7

We can trap "3 units" of water between 3 and 2,
"1 unit" on top of bar 2 and "3 units" between 2 
and 4.  See below diagram als

Method 1: This is a simple solution to the above problem.

Approach: The idea is to traverse every array element and find the highest bars on left and right sides. Take the smaller of two heights.  
The difference between the smaller height and height of the current element is the amount of water that can be stored in this array element.
Algorithm:
Traverse the array from start to end.
For every element, traverse the array from start to that index and find the maximum height (a) and traverse the array from the current index to end and
 find the maximum height (b).
The amount of water that will be stored in this column is min(a,b) – array[i], add this value to total amount of water stored
Print the total amount of water store O(n2) hence not acceptable
-------------------------------------------------------------------------------------------------------------------------------
Method 2
This is an efficient solution to the above problem.

Approach: In the previous solution, to find the highest bar on the left and right, array traversal is needed which reduces the efficiency of the solution. 
To make this efficient one must pre-compute the highest bar on the left and right of every bar in linear time. Then use these pre-computed values to find the amount of water in every array element.
Algorithm:
Create two array left and right of size n. create a variable max_ = INT_MIN.
Run one loop from start to end. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign left[i] = max_
Update max_ = INT_MIN.
Run another loop from end to start. In each iteration update max_ as max_ = max(max_, arr[i]) and also assign right[i] = max_
Traverse the array from start to end.
The amount of water that will be stored in this column is min(a,b) – array[i],(where a = left[i] and b = right[i]) add this value to total amount of water stored
Print the total amount of water stored.

// C++ program to find maximum amount of water that can 
// be trapped within given set of bars. 
#include <bits/stdc++.h> 
using namespace std; 

int findWater(int arr[], int n) 
{ 
	// left[i] contains height of tallest bar to the 
	// left of i'th bar including itself 
	int left[n]; 

	// Right [i] contains height of tallest bar to 
	// the right of ith bar including itself 
	int right[n]; 

	// Initialize result 
	int water = 0; 

	// Fill left array 
	left[0] = arr[0]; 
	for (int i = 1; i < n; i++) 
		left[i] = max(left[i - 1], arr[i]); 

	// Fill right array 
	right[n - 1] = arr[n - 1]; 
	for (int i = n - 2; i >= 0; i--) 
		right[i] = max(right[i + 1], arr[i]); 

	// Calculate the accumulated water element by element 
	// consider the amount of water on i'th bar, the 
	// amount of water accumulated on this particular 
	// bar will be equal to min(left[i], right[i]) - arr[i] . 
	for (int i = 0; i < n; i++) 
		water += min(left[i], right[i]) - arr[i]; 

	return water; 
} 

// Driver program 
int main() 
{ 
	int arr[] = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << "Maximum water that can be accumulated is "
		<< findWater(arr, n); 
	return 0; 
}

