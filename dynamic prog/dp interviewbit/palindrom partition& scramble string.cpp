Given a string A, partition A such that every substring of the partition is a palindrome.

Return the minimum cuts needed for a palindrome partitioning of A.

aba ==0, aab===1   check tushar roy video and gfg explaination


// Returns the minimum number of cuts needed to partition a string 
// such that every part is a palindrome 
int minPalPartion(char* str) 
{ 
	// Get the length of the string 
	int n = strlen(str); 

	/* Create two arrays to build the solution in bottom up manner 
	C[i][j] = Minimum number of cuts needed for palindrome partitioning 
				of substring str[i..j] 
	P[i][j] = true if substring str[i..j] is palindrome, else false 
	Note that C[i][j] is 0 if P[i][j] is true */
	int C[n][n]; 
	bool P[n][n]; 

	int i, j, k, L; // different looping variables 

	// Every substring of length 1 is a palindrome 
	for (i = 0; i < n; i++) 
	{ 
		P[i][i] = true; 
		C[i][i] = 0; 
	} 

	/* L is substring length. Build the 
	solution in bottom up manner by 
	considering all substrings of 
	length starting from 2 to n. 
	The loop structure is same as Matrx 
	Chain Multiplication problem 
	( See https:// www.geeksforgeeks.org/matrix-chain-multiplication-dp-8/ )*/
	for (L = 2; L <= n; L++) 
	{ 
		// For substring of length L, set 
		// different possible starting indexes 
		for (i = 0; i < n - L + 1; i++) 
		{ 
			j = i + L - 1; // Set ending index 

			// If L is 2, then we just need to 
			// compare two characters. Else 
			// need to check two corner characters 
			// and value of P[i+1][j-1] 
			if (L == 2) 
				P[i][j] = (str[i] == str[j]); 
			else
				P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1]; 

			// IF str[i..j] is palindrome, then C[i][j] is 0 
			if (P[i][j] == true) 
				C[i][j] = 0; 
			else
			{ 
				// Make a cut at every possible 
				// location starting from i to j, 
				// and get the minimum cost cut. 
				C[i][j] = INT_MAX; 
				for (k = i; k <= j - 1; k++) 
					C[i][j] = min(C[i][j], C[i][k] + C[k + 1][j] + 1); 
			} 
		} 
	} 

	// Return the min cut value for 
	// complete string. i.e., str[0..n-1] 
	return C[0][n - 1]; 
} 
--------------------------------------------------------------------------------------------------------------------------------
scramble string buyhatke
Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.

Input: s1 = "great", s2 = "rgeat"
Output: true

 bool isScramble(string s1, string s2) {
        if(s1==s2)
            return true;
            
        int len = s1.length();
        int count[26] = {0};
        for(int i=0; i<len; i++)
        {
            count[s1[i]-'a']++;
            count[s2[i]-'a']--;
        }
        
        for(int i=0; i<26; i++)
        {
            if(count[i]!=0)
                return false;
        }
        
        for(int i=1; i<=len-1; i++)
        {
            if( isScramble(s1.substr(0,i), s2.substr(0,i)) && isScramble(s1.substr(i), s2.substr(i)))
                return true;
            if( isScramble(s1.substr(0,i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0,len-i)))
                return true; /* learn this step*/
        }
        return false;
    }




