here we are going to discuss problems involving diagonal filling of matrix
see vivekanand lps for clear understanding
longest palindrom subsequence

// A Dynamic Programming based C++ program for LPS problem 
// Returns the length of the longest palindromic subsequence in seq 
#include<stdio.h> 
#include<string.h> 

// A utility function to get max of two integers 
int max (int x, int y) { return (x > y)? x : y; } 

// Returns the length of the longest palindromic subsequence in seq 
int lps(char *str) 
{ 
int n = strlen(str); 
int i, j, cl; 
int L[n][n]; // Create a table to store results of subproblems 


// Strings of length 1 are palindrome of lentgh 1 
for (i = 0; i < n; i++) 
	L[i][i] = 1; 
  for(i=0;i<n;i++)
  {
    for(j=0;j<n;j++)
    {
      if(i>j)
        L[i][j]=0;
    }
  }// setting all elements below diagonal as zero

	// Build the table. Note that the lower diagonal values of table are 
	// useless and not filled in the process. The values are filled in a 
	// manner similar to Matrix Chain Multiplication DP solution (See 
	// https://www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/). cl is length of 
	// substring 
	for (cl=2; cl<=n; cl++) 
	{ 
		for (i=0; i<n-cl+1; i++) 
		{ 
			j = i+cl-1; 
			
			 if (str[i] == str[j]) 
			L[i][j] = L[i+1][j-1] + 2; 
			else
			L[i][j] = max(L[i][j-1], L[i+1][j]); 
		} 
	} 

	return L[0][n-1]; 
} 

/* Driver program to test above functions */
int main() 
{ 
	char seq[] = "abcda"; 
	int n = strlen(seq); 
	printf ("The lnegth of the LPS is %d", lps(seq)); 
	getchar(); 
	return 0; 
} 
-------------------------------------------------------------------------------------------------


optimal game strategy

There are two choices:
1. The user chooses the ith coin with value Vi: The opponent either chooses (i+1)th coin or jth coin. The opponent intends to choose the coin which leaves the user with minimum value.
i.e. The user can collect the value Vi + min(F(i+2, j), F(i+1, j-1) )


2. The user chooses the jth coin with value Vj: The opponent either chooses ith coin or (j-1)th coin. The opponent intends to choose the coin which leaves the user with minimum value.
i.e. The user can collect the value Vj + min(F(i+1, j-1), F(i, j-2) )
// recursive solution
int answer(int *A,int start,int end)
{
    if(start==end)
    return A[start];
    if(end==start+1)
    return max(A[start],A[end]);
    int a=A[start]+min(answer(A,start+1,end-1),answer(A,start+2,end));
    int b=A[end]+min(answer(A,start+1,end-1),answer(A,start,end-2));
    return max(a,b);
}

int maxCoins(int A[],int N)
{
    int n=N;
    int table[n][n]; 
  
    // Fill table using above recursive formula. Note  
    // that the table is filled in diagonal fashion (similar 
    // to http://goo.gl/PQqoS), from diagonal elements to 
    // table[0][n-1] which is the result. 
    for (int gap = 0; gap < n; ++gap) { 
        for (int i = 0;i<n-gap;i++) { 
  
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and 
            // z is F(i, j-2) in above recursive formula 
            int j=i+gap;
            int x = ((i + 2) <= j) ? table[i + 2][j] : 0; 
            int y = ((i + 1) <= (j - 1)) ? table[i + 1][j - 1] : 0; 
            int z = (i <= (j - 2)) ? table[i][j - 2] : 0; 
  
            table[i][j] = max(A[i] + min(x, y), A[j] + min(y, z)); 
        } 
    } 
  
    return table[0][n - 1]; 
}

---------------------------------// also used in matrix chain multiplication

