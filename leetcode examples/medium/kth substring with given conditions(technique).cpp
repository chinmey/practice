A happy string is a string that:

consists only of letters of the set ['a', 'b', 'c'].
s[i] != s[i + 1] for all values of i from 1 to s.length - 1 (string is 1-indexed).
For example, strings "abc", "ac", "b" and "abcbabcbcb" are all happy strings and strings "aa", "baa" and "ababbc" are not happy strings.

Given two integers n and k, consider a list of all happy strings of length n sorted in lexicographical order.

Return the kth string of this list or return an empty string if there are less than k happy strings of length n.


Input: n = 3, k = 9
Output: "cab"
Explanation: There are 12 different happy string of length 3 ["aba", "abc", "aca", "acb", "bab", "bac", "bca", "bcb", "cab", "cac", "cba", "cbc"].

// C++ program to print all 
// possible strings of length k 
#include <bits/stdc++.h> 
using namespace std; 
	

// The main recursive method 
// to print all possible 
// strings of length k 
  bool valid(string s)
    {
        int n=s.length();
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
                return false;
        }
        return true;
    }
void printAllKLengthRec(char set[], string prefix, 
									int n, int k,vector<string>&v) 
{ 
	
	// Base case: k is 0, 
	// print prefix 
	if (k == 0 ) 
	{ 
	    if(valid(prefix))
		v.push_back(prefix);
		return; 
	} 

	// One by one add all characters 
	// from set and recursively 
	// call for k equals to k-1 
	for (int i = 0; i < n; i++) 
	{ 
		string newPrefix; 
		
		// Next character of input added 
		newPrefix = prefix + set[i]; 
		
		// k is decreased, because 
		// we have added a new character 
		printAllKLengthRec(set, newPrefix, n, k - 1,v); 
	} 

} 

void printAllKLength(char set[], int k,int n,vector<string>&v) 
{ 
	printAllKLengthRec(set, "", n, k,v); 
} 

// Driver Code 
int main() 
{ 
	
	cout << "First Test" << endl; 
	char set1[] = {'a', 'b'}; 
	vector<string>v;
	int k = 3; 
	printAllKLength(set1, k, 2,v); 
	for(int i=0;i<v.size();i++)
	cout<<v[i]<<" ";
	
	/*cout << "Second Test\n"; 
	char set2[] = {'a', 'b', 'c', 'd'}; 
	 k = 1; 
	printAllKLength(set2, k, 4); */
} 

// This code is contributed 
// by Mohit kumar 



