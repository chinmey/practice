/*Let arr[0..n-1] be the input array and L(i) be the length of the LIS ending at index i such that arr[i] is the last element of the LIS.
Then, L(i) can be recursively written as:
L(i) = 1 + max( L(j) ) where 0 < j < i and arr[j] < arr[i]; or
L(i) = 1, if no such j exists.*/







/* Dynamic Programming C++ implementation of LIS problem */
#include<bits/stdc++.h>
using namespace std;

/* lis() returns the length of the longest increasing
  subsequence in arr[] of size n */
int lis( int arr[], int n )
{
    int lis[n];

    lis[0] = 1;

    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++ )
    {
        lis[i] = 1;
        for (int j = 0; j < i; j++ )
            if ( arr[i] > arr[j] && lis[i] < lis[j] + 1)
                lis[i] = lis[j] + 1;
    }

    // Return maximum value in lis[]
    return *max_element(lis, lis+n);
}

/* Driver program to test above function */
int main()
{
    int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Length of lis is %d\n", lis( arr, n ) );
    return 0;
}

----------------------------------------------------------------------------------------


This problem is a variation of standard Longest Increasing Subsequence (LIS) problem. 
Let the input array be arr[] of length n. We need to construct two arrays lis[] and lds[] using Dynamic Programming solution of LIS problem.
/*importabt line read*/
 lis[i] stores the length of the Longest Increasing subsequence ending with arr[i]. lds[i] stores the length of the longest Decreasing subsequence starting from arr[i].
  Finally, we need to return the max value of lis[i] + lds[i] – 1 where i is from 0 to n-1.
  
  
  /* Dynamic Programming implementation of longest bitonic subsequence problem */
#include<stdio.h> 
#include<stdlib.h> 

/* lbs() returns the length of the Longest Bitonic Subsequence in 
	arr[] of size n. The function mainly creates two temporary arrays 
	lis[] and lds[] and returns the maximum lis[i] + lds[i] - 1. 

	lis[i] ==> Longest Increasing subsequence ending with arr[i] 
	lds[i] ==> Longest decreasing subsequence starting with arr[i] 
*/
int lbs( int arr[], int n ) 
{ 
int i, j; 

/* Allocate memory for LIS[] and initialize LIS values as 1 for 
	all indexes */
int *lis = new int[n]; 
for (i = 0; i < n; i++) 
	lis[i] = 1; 

/* Compute LIS values from left to right */
for (i = 1; i < n; i++) 
	for (j = 0; j < i; j++) 
		if (arr[i] > arr[j] && lis[i] < lis[j] + 1) 
			lis[i] = lis[j] + 1; 

/* Allocate memory for lds and initialize LDS values for 
	all indexes */
int *lds = new int [n]; 
for (i = 0; i < n; i++) 
	lds[i] = 1; 

/* Compute LDS values from right to left */
for (i = n-2; i >= 0; i--) 
	for (j = n-1; j > i; j--) 
		if (arr[i] > arr[j] && lds[i] < lds[j] + 1) 
			lds[i] = lds[j] + 1; 


/* Return the maximum value of lis[i] + lds[i] - 1*/
int max = lis[0] + lds[0] - 1; 
for (i = 1; i < n; i++) 
	if (lis[i] + lds[i] - 1 > max) 
		max = lis[i] + lds[i] - 1; 
return max; 
} 

/* Driver program to test above function */
int main() 
{ 
int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5, 
			13, 3, 11, 7, 15}; 
int n = sizeof(arr)/sizeof(arr[0]); 
printf("Length of LBS is %d\n", lbs( arr, n ) ); 
return 0; 
} 

-----------------------------------------------------------------------------------------
The longest Zig-Zag subsequence problem is to find length of the longest subsequence of given sequence such that all elements of this are alternating.
Input: arr[] = {1, 5, 4}
Output: 3
The whole arrays is of the form  x1 < x2 > x3 

Input: arr[] = {10, 22, 9, 33, 49, 50, 31, 60}
Output: 6
The subsequences {10, 22, 9, 33, 31, 60} or
{10, 22, 9, 49, 31, 60} or {10, 22, 9, 50, 31, 60}
are longest Zig-Zag of length 6.

We will solve this problem by dynamic Programming method, Let A is given array of length n of integers. 
We define a 2D array Z[n][2] such that Z[i][0] contains longest Zig-Zag subsequence ending at index i and last element is greater than its previous element and 
Z[i][1] contains longest Zig-Zag subsequence ending at index i and last element is smaller than its previous element, then we have following recurrence relation between them,

Z[i][0] = Length of the longest Zig-Zag subsequence 
          ending at index i and last element is greater
          than its previous element
Z[i][1] = Length of the longest Zig-Zag subsequence 
          ending at index i and last element is smaller
          than its previous element

Recursive Formulation:
   Z[i][0] = max (Z[i][0], Z[j][1] + 1); 
             for all j < i and A[j] < A[i] 
   Z[i][1] = max (Z[i][1], Z[j][0] + 1); 
             for all j < i and A[j] > A[i]


int zzis(int arr[], int n) 
{ 
    /*Z[i][0] = Length of the longest Zig-Zag subsequence 
          ending at index i and last element is greater 
          than its previous element 
     Z[i][1] = Length of the longest Zig-Zag subsequence 
          ending at index i and last element is smaller 
          than its previous element   */
    int Z[n][2]; 
  
    /* Initialize all values from 1  */
    for (int i = 0; i < n; i++) 
        Z[i][0] = Z[i][1] = 1; 
  
    int res = 1; // Initialize result 
  
    /* Compute values in bottom up manner */
    for (int i = 1; i < n; i++) 
    { 
        // Consider all elements as previous of arr[i] 
        for (int j = 0; j < i; j++) 
        { 
            // If arr[i] is greater, then check with Z[j][1] 
            if (arr[j] < arr[i] && Z[i][0] < Z[j][1] + 1) 
                Z[i][0] = Z[j][1] + 1; 
  
            // If arr[i] is smaller, then check with Z[j][0] 
            if( arr[j] > arr[i] && Z[i][1] < Z[j][0] + 1) 
                Z[i][1] = Z[j][0] + 1; 
        } 
  
        /* Pick maximum of both values at index i  */
        if (res < max(Z[i][0], Z[i][1])) 
            res = max(Z[i][0], Z[i][1]); 
    } 
  
    return res;
    
    
    --------------------------------------------------------------------------------------------------------------------------------------
    
   /// box stacking problem 
    
    You are given a set of n types of rectangular 3-D boxes, where the i^th box has height h(i), width w(i) and depth d(i) (all real numbers).
	 You want to create a stack of boxes which is as tall as possible, but you can only stack a box on top of another box 
	 if the dimensions of the 2-D base of the lower box are each strictly larger than those of the 2-D base of the higher box. Of course, 
	 you can rotate a box so that any side functions as its base.
	 It is also allowable to use multiple instances of the same type of box.
	 
	 
	 
	 
	 1) Generate all 3 rotations of all boxes. The size of rotation array becomes 3 times the size of original array. 
	 For simplicity, we consider depth as always smaller than or equal to width.

2) Sort the above generated 3n boxes in decreasing order of base area.

3) After sorting the boxes, the problem is same as LIS with following optimal substructure property.
MSH(i) = Maximum possible Stack Height with box i at top of stack
MSH(i) = { Max ( MSH(j) ) + height(i) } where j < i and width(j) > width(i) and depth(j) > depth(i).
If there is no such j then MSH(i) = height(i)

4) To get overall maximum height, we return max(MSH(i)) where 0 < i < n




/* Dynamic Programming implementation of Box Stacking problem */
#include<stdio.h> 
#include<stdlib.h> 

/* Representation of a box */
struct Box 
{ 
// h --> height, w --> width, d --> depth 
int h, w, d; // for simplicity of solution, always keep w <= d 
}; 

// A utility function to get minimum of two intgers 
int min (int x, int y) 
{ return (x < y)? x : y; } 

// A utility function to get maximum of two intgers 
int max (int x, int y) 
{ return (x > y)? x : y; } 

/* Following function is needed for library function qsort(). We 
use qsort() to sort boxes in decreasing order of base area. 
Refer following link for help of qsort() and compare() 
http://www.cplusplus.com/reference/clibrary/cstdlib/qsort/ */
int compare (const void *a, const void * b) 
{ 
	return ( (*(Box *)b).d * (*(Box *)b).w ) - 
		( (*(Box *)a).d * (*(Box *)a).w ); 
} 

/* Returns the height of the tallest stack that can be 
formed with give type of boxes */
int maxStackHeight( Box arr[], int n ) 
{ 
/* Create an array of all rotations of given boxes 
	For example, for a box {1, 2, 3}, we consider three 
	instances{{1, 2, 3}, {2, 1, 3}, {3, 1, 2}} */
Box rot[3*n]; 
int index = 0; 
for (int i = 0; i < n; i++) 
{ 
	// Copy the original box 
	rot[index].h = arr[i].h; 
	rot[index].d = max(arr[i].d, arr[i].w); 
	rot[index].w = min(arr[i].d, arr[i].w); 
	index++; 

	// First rotation of box 
	rot[index].h = arr[i].w; 
	rot[index].d = max(arr[i].h, arr[i].d); 
	rot[index].w = min(arr[i].h, arr[i].d); 
	index++; 

	// Second rotation of box 
	rot[index].h = arr[i].d; 
	rot[index].d = max(arr[i].h, arr[i].w); 
	rot[index].w = min(arr[i].h, arr[i].w); 
	index++; 
} 

// Now the number of boxes is 3n 
n = 3*n; 

/* Sort the array 'rot[]' in non-increasing order 
	of base area */
qsort (rot, n, sizeof(rot[0]), compare); 

// Uncomment following two lines to print all rotations 
// for (int i = 0; i < n; i++ ) 
// printf("%d x %d x %d\n", rot[i].h, rot[i].w, rot[i].d); 

/* Initialize msh values for all indexes 
	msh[i] --> Maximum possible Stack Height with box i on top */
int msh[n]; 
for (int i = 0; i < n; i++ ) 
	msh[i] = rot[i].h; 

/* Compute optimized msh values in bottom up manner */
for (int i = 1; i < n; i++ ) 
	for (int j = 0; j < i; j++ ) 
		if ( rot[i].w < rot[j].w && 
			rot[i].d < rot[j].d && 
			msh[i] < msh[j] + rot[i].h 
			) 
		{ 
			msh[i] = msh[j] + rot[i].h; 
		} 


/* Pick maximum of all msh values */
int max = -1; 
for ( int i = 0; i < n; i++ ) 
	if ( max < msh[i] ) 
		max = msh[i]; 

return max; 
} 

/* Driver program to test above function */
int main() 
{ 
Box arr[] = { {4, 6, 7}, {1, 2, 3}, {4, 5, 6}, {10, 12, 32} }; 
int n = sizeof(arr)/sizeof(arr[0]); 

printf("The maximum possible height of stack is %d\n", 
		maxStackHeight (arr, n) ); 

return 0; 
} 


