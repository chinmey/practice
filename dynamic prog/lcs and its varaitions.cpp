#include<bits/stdc++.h>
using namespace std;
int max(int a,int b)
{
    if(a>b)
    return a;
    return b;
}
int find(string s1,string s2,int m,int n)
{
    int table[m+1][n+1];
    int i,j;
    for(i=0;i<=m;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            table[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            table[i][j]=1+table[i-1][j-1];
            else
            table[i][j]=max(table[i][j-1],table[i-1][j]);
        }
    }
    return table[m][n];

}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int m,n;
	    cin>>m>>n;
	    string s1,s2;
	    cin>>s1>>s2;
	    int c=find(s1,s2,m,n);
	    cout<<c<<endl;;

	}
	return 0;
}
---------------------------------------------------------------------------------------------------------------------

Shortest Common Supersequence

Input:   str1 = "geek",  str2 = "eke"
Output: "geeke"

Input:   str1 = "AGGTAB",  str2 = "GXTXAYB"
Output:  "AGXGTXAYB"


Length of the shortest supersequence  = (Sum of lengths of given two strings) -
                                        (Length of LCS of two given strings)
---------------------------------------------------------------------------------------------------------------------------


Minimum insertion to form a palindrom

abcd: Number of insertions required is 3 i.e. dcbabcd

Minimum insertion to form a palindrom:(length of string) - (length of lcs of string and its reverse)
 reverse(str.begin(), str.end());
 // our own reversing function
 
 // A Simple C++ program to reverse a string 
#include <bits/stdc++.h> 
using namespace std; 

// Function to reverse a string 
void reverseStr(string& str) 
{ 
	int n = str.length(); 

	// Swap character starting from two 
	// corners 
	for (int i = 0; i < n / 2; i++) 
		swap(str[i], str[n - i - 1]); 
} 

// Driver program 
int main() 
{ 
	string str = "geeksforgeeks"; 
	reverseStr(str); 
	cout << str; 
	return 0; 
} 


                                        
    -----------------------------------------------------------------------------------------------------------------------
 Longest Repeating Subsequence
 
 Given a string, find length of the longest repeating subseequence such that the two subsequence don’t have same string character at 
 same position,  i.e., any i’th character in the two subsequences shouldn’t have the same index in the original string.
 
 Input: str = "aabb"
Output: 2   ab repeats

same as lcs just with modification if s[i]==s[j] than i !=j

int find(string s1,int n)
{
    int table[n+1][n+1];
    int i,j;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            if(i==0||j==0)
            table[i][j]=0;
            else if(s1[i-1]==s2[j-1] && i!=j) /* only change*/
            table[i][j]=1+table[i-1][j-1];
            else
            table[i][j]=max(table[i][j-1],table[i-1][j]);
        }
    }
    return table[n][n];

}
------------------------------------------------------------------------------------------------------------------------------
Given a two strings S and T, find the count of distinct occurrences of T in S as a subsequence

Input: S = banana, T = ban
Output: 3
Explanation: T appears in S as below three subsequences.
[ban], [ba  n], [b   an]
/* C/C++ program to count number of times S appears 
as a subsequence in T */
#include <bits/stdc++.h> 
using namespace std; 

int findSubsequenceCount(string S, string T) 
{ 
	int m = T.length(), n = S.length(); 

	// T can't appear as a subsequence in S 
	if (m > n) 
		return 0; 

	// mat[i][j] stores the count of occurrences of 
	// T(1..i) in S(1..j). 
	int mat[m + 1][n + 1]; 

	// Initializing first column with all 0s. An empty 
	// string can't have another string as suhsequence 
	for (int i = 1; i <= m; i++) 
		mat[i][0] = 0; 

	// Initializing first row with all 1s. An empty 
	// string is subsequence of all. 
	for (int j = 0; j <= n; j++) 
		mat[0][j] = 1; 

	// Fill mat[][] in bottom up manner 
	for (int i = 1; i <= m; i++) { 
		for (int j = 1; j <= n; j++) { 

			// If last characters don't match, then value 
			// is same as the value without last character 
			// in S. 
			if (T[i - 1] != S[j - 1]) 
				mat[i][j] = mat[i][j - 1]; 

			// Else value is obtained considering two cases. 
			// a) All substrings without last character in S 
			// b) All substrings without last characters in 
			// both. 
			else
				mat[i][j] = mat[i][j - 1] + mat[i - 1][j - 1]; 
		} 
	} 

	/* uncomment this to print matrix mat 
	for (int i = 1; i <= m; i++, cout << endl) 
		for (int j = 1; j <= n; j++) 
			cout << mat[i][j] << " "; */
	return mat[m][n]; 
} 

// Driver code to check above method 
int main() 
{ 
	string T = "ge"; 
	string S = "geeksforgeeks"; 
	cout << findSubsequenceCount(S, T) << endl; 
	return 0; 
} 



