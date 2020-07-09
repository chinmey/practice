/* maximum product of three elemenets*/

Given an array A, of N integers A.

Return the highest product possible by multiplying 3 numbers from the array.


Choosing 3 maximum elements in the array and 2 negative elements with the highest absolute value should be enough.

There are various ways to calculate 3 maximum elements in the array ( and subsequently 2 negative elements with highest absolute value ).
 One such approach is maintaining 3 variables ( m1, m2, m3 where m1 > m2 > m3 ). When you encounter new value in the array, if the value is less than m3, then the variables are unaffected. Else, depending on where the new value lies, you can update the 3 values.

Another approach could be maintaining a priority_queue of size 3. You pop out the smallest element if the new element if bigger than the smallest element, and then insert the new element into the priority queue.

Once you have the 5 elements you desire,
your answer would be one of the following :
1) Product of 3 maximum elements
2) Product of the 2 negative elements with max absolute value and maximum positive value.


int Solution::maxp3(vector<int> &A) {
    sort(A.begin(), A.end());
    int n = A.size();
    int all_pos = A[n-3]*A[n-2]*A[n-1]; 
    int pos_neg = A[0]*A[1]*A[n-1];     
    return max({all_pos, pos_neg});
}

/* distribute candies*/

There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give?

int Solution::candy(vector<int> &A) {
    
    int n=A.size(),i,count=0;
     int candy[n];
     
     for(i=0;i<n;i++) candy[i]=1;
     
      for(i=1;i<n;i++) /* check for left neighbour*/
     {
         if(A[i] >A[i-1])
         candy[i]=max(candy[i],1+candy[i-1]);
     }
     
     for(i=n-2;i>=0;i--) /* check for right neighbour*/
     {
         if(A[i]>A[i+1])
         candy[i]=max(candy[i],1+candy[i+1]);
     }
     
    
     for(i=0;i<n;i++)
     count=count+candy[i];
     
     return count;
}

/* moore voting algo*/

We are given a read only array of n integers. Find any element that appears more than n/3 times in the array in linear time and constant additional space. If no such element exists, return -1

if we use only first and count1 we can get more than n/2 element
// CPP program to find if any element appears 
// more than n/3. 
#include <bits/stdc++.h> 
using namespace std; 

int appearsNBy3(int arr[], int n) 
{ 
	int count1 = 0, count2 = 0; 
	int first=INT_MAX , second=INT_MAX ; 

	for (int i = 0; i < n; i++) { 

		// if this element is previously seen, 
		// increment count1. 
		if (first == arr[i]) 
			count1++; 

		// if this element is previously seen, 
		// increment count2. 
		else if (second == arr[i]) 
			count2++; 
	
		else if (count1 == 0) { 
			count1++; 
			first = arr[i]; 
		} 

		else if (count2 == 0) { 
			count2++; 
			second = arr[i]; 
		} 

		// if current element is different from 
		// both the previously seen variables, 
		// decrement both the counts. 
		else { 
			count1--; 
			count2--; 
		} 
	} 

	count1 = 0; 
	count2 = 0; 

	// Again traverse the array and find the 
	// actual counts. 
	for (int i = 0; i < n; i++) { 
		if (arr[i] == first) 
			count1++; 

		else if (arr[i] == second) 
			count2++; 
	} 

	if (count1 > n / 3) 
		return first; 

	if (count2 > n / 3) 
		return second; 

	return -1; 
} 

int main() 
{ 
	int arr[] = { 1, 2, 3, 1, 1 }; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << appearsNBy3(arr, n) << endl; 
	return 0; 
} 

