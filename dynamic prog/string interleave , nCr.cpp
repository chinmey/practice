Given three strings A, B and C your task is to complete the function isInterleave which returns true if C is an interleaving of A and B else returns false.
 C is said to be interleaving A and B, if it contains all characters of A and B and order of all characters in individual strings is preserved.
 
 2
YX  X  XXY
XY X XXY

Output
0
1

// A simple recursive function to check whether C is an interleaving of A and B 
bool isInterleaved(char* A, char* B, char* C) 
{ 
	// Base Case: If all strings are empty 
	if (!(*A || *B || *C)) 
		return true; 

	// If C is empty and any of the two strings is not empty 
	if (*C == '\0') 
		return false; 

	// If any of the above mentioned two possibilities is true, 
	// then return true, otherwise false 
	return ((*C == *A) && isInterleaved(A + 1, B, C + 1)) 
		|| ((*C == *B) && isInterleaved(A, B + 1, C + 1)); 
} 

// A Dynamic Programming based program to check whether a string C is 
// an interleaving of two other strings A and B. 
#include <iostream> 
#include <string.h> 
using namespace std; 

// The main function that returns true if C is 
// an interleaving of A and B, otherwise false. 
bool isInterleaved(char* A, char* B, char* C) 
{ 
	// Find lengths of the two strings 
	int M = strlen(A), N = strlen(B); 

	// Let us create a 2D table to store solutions of 
	// subproblems. C[i][j] will be true if C[0..i+j-1] 
	// is an interleaving of A[0..i-1] and B[0..j-1]. 
	bool IL[M + 1][N + 1]; 

	memset(IL, 0, sizeof(IL)); // Initialize all values as false. 

	// C can be an interleaving of A and B only of sum 
	// of lengths of A & B is equal to length of C. 
	if ((M + N) != strlen(C)) 
		return false; 

	// Process all characters of A and B 
	for (int i = 0; i <= M; ++i) { 
		for (int j = 0; j <= N; ++j) { 
			// two empty strings have an empty string 
			// as interleaving 
			if (i == 0 && j == 0) 
				IL[i][j] = true; 

			// A is empty 
			else if (i == 0) { 
				if (B[j - 1] == C[j - 1]) 
					IL[i][j] = IL[i][j - 1]; 
			} 

			// B is empty 
			else if (j == 0) { 
				if (A[i - 1] == C[i - 1]) 
					IL[i][j] = IL[i - 1][j]; 
			} 

			// Current character of C matches with current character of A, 
			// but doesn't match with current character of B 
			else if (A[i - 1] == C[i + j - 1] && B[j - 1] != C[i + j - 1]) 
				IL[i][j] = IL[i - 1][j]; 

			// Current character of C matches with current character of B, 
			// but doesn't match with current character of A 
			else if (A[i - 1] != C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
				IL[i][j] = IL[i][j - 1]; 

			// Current character of C matches with that of both A and B 
			else if (A[i - 1] == C[i + j - 1] && B[j - 1] == C[i + j - 1]) 
				IL[i][j] = (IL[i - 1][j] || IL[i][j - 1]); 
		} 
	} 

	return IL[M][N]; 
} 

// A function to run test cases 
void test(char* A, char* B, char* C) 
{ 
	if (isInterleaved(A, B, C)) 
		cout << C << " is interleaved of " << A << " and " << B << endl; 
	else
		cout << C << " is not interleaved of " << A << " and " << B << endl; 
} 

// Driver program to test above functions 
int main() 
{ 
	test("XXY", "XXZ", "XXZXXXY"); 
	test("XY", "WZ", "WZXY"); 
	test("XY", "X", "XXY"); 
	test("YX", "X", "XXY"); 
	test("XXY", "XXZ", "XXXXZY"); 
	return 0; 
} 
----------------------------------------------------------------------------------------------------------------------------------------------------------

ncr 

#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll M = (1e9+7);

ll inv(ll a , ll b) {
    
    if(b==0) return 1;
    
    if(b%2==0) return inv((a*a)%M , b/2);
    else return (a*(inv((a*a)%M, b/2)))%M;
    
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    unsigned long long int n,r,i,j;
	    unsigned long long  int p=(1e9+7);
	    cin>>n>>r;
	    if(n<r)
	    cout<<"0"<<endl;
	    else{
	    
	    unsigned long long int f[n+1];
	    f[0]=1;
	    for(i=1;i<=n;i++)
	    f[i]=(f[i-1]*i)%p;
	    
	    long long  int num=f[n];
	    long long  int den=(f[r]*f[n-r])%p;
	    
	    den = inv(den , p-2);
	    
	    cout<<(num*den)%M<<endl;
	}
	    
	}
	return 0;
}
