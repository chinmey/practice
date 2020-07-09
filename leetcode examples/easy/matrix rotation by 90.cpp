
Rotate a matrix 90 anticlockwise

Approach:The idea is to find the transpose of the matrix and then reverse the columns of the transposed matrix.

0 1 2          0 3 6                     2 5 8
3 4 5  ======> 1  4 7 ==================>1 4 7
6 7 8          2  5 8                    0 3 6




Rotate a matrix 90 clockwise

Approach:The idea is to find the transpose of the matrix and then reverse the rows of the transposed matrix.

// C++ program for anticlockwise rotation of matrix by 90 
// degree without using extra space 
#include <bits/stdc++.h> 
using namespace std; 
#define R 4 
#define C 4 

// After transpose we swap elements of column 
// one by one for finding left rotation of matrix 
// by 90 degree 
void reverseColumns(int arr[R][C]) 
{ 
	for (int i = 0; i < C; i++) 
		for (int j = 0, k = C - 1; j < k; j++, k--) 
			swap(arr[j][i], arr[k][i]); 
} 

// Function for do transpose of matrix 
void transpose(int arr[R][C]) 
{ 
	for (int i = 0; i < R; i++) 
		for (int j = i; j < C; j++) 
			swap(arr[i][j], arr[j][i]); 
} 

// Function for print matrix 
void printMatrix(int arr[R][C]) 
{ 
	for (int i = 0; i < R; i++) { 
		for (int j = 0; j < C; j++) 
			cout << arr[i][j] << " "; 
		cout << '\n'; 
	} 
} 

// Function to anticlockwise rotate matrix 
// by 90 degree 
void rotate90(int arr[R][C]) 
{ 
	transpose(arr); 
	reverseColumns(arr); 
} 

// Driven code 
int main() 
{ 
	int arr[R][C] = { { 1, 2, 3, 4 }, 
					{ 5, 6, 7, 8 }, 
					{ 9, 10, 11, 12 }, 
					{ 13, 14, 15, 16 } }; 
	rotate90(arr); 
	printMatrix(arr); 
	return 0; 
} 

