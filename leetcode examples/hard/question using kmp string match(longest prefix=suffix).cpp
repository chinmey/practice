A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).

Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string

Input: s = "leetcodeleet"
Output: "leet"

The preprocessing for KMP actually computes the longest prefix that is a suffix, so we can just use the same algorithm with the additional
 check if there is no valid prefix-suffix match (If the greatest element in the prefix-suffix array is 0, then there is no valid prefix-suffix match).
 
  https://www.youtube.com/watch?v=GTJr8OvyEVQ--explanation

class Solution {
public:
    vector<int> lps(string& word)
    {
        vector<int> lp(word.length(), 0);
        
        int index = 0;
        for(int i = 1; i < word.length();)
        {
            if(word[i] == word[index])
            {
                index++;
                lp[i] = index;
                i++;
            }
            else
            {
                if(index != 0)
                    index = lp[index-1];
                else
                    i++;
            }
        }
        
        return lp;
    }
    
    string longestPrefix(string s) {
        vector<int> lp = lps(s);
        
        return s.substr(0, lp.back());
    }
};

-----------------------------------------------------------------------------------------------------------------------------
KMP string matching algorithum

// C++ program for implementation of KMP pattern searching 
// algorithm 
#include <bits/stdc++.h> 

void computeLPSArray(char* pat, int M, int* lps); 

// Prints occurrences of txt[] in pat[] 
void KMPSearch(char* pat, char* txt) 
{ 
	int M = strlen(pat); 
	int N = strlen(txt); 

	// create lps[] that will hold the longest prefix suffix 
	// values for pattern 
	int lps[M]; 

	// Preprocess the pattern (calculate lps[] array) 
	computeLPSArray(pat, M, lps); 

	int i = 0; // index for txt[] 
	int j = 0; // index for pat[] 
	while (i < N) { 
		if (pat[j] == txt[i]) { 
			j++; 
			i++; 
		} 

		if (j == M) { 
			printf("Found pattern at index %d ", i - j); 
			j = lps[j - 1]; /* imp step*/
		} 

		// mismatch after j matches 
		else if (i < N && pat[j] != txt[i]) { 
			// Do not match lps[0..lps[j-1]] characters, 
			// they will match anyway 
			if (j != 0) 
				j = lps[j - 1]; /* imp step*/
			else
				i = i + 1; 
		} 
	} 
} 

// Fills lps[] for given patttern pat[0..M-1] 
void computeLPSArray(char* pat, int M, int* lps) 
{ 
	// length of the previous longest prefix suffix 
	int len = 0; 

	lps[0] = 0; // lps[0] is always 0 

	// the loop calculates lps[i] for i = 1 to M-1 
	int i = 1; 
	while (i < M) { 
		if (pat[i] == pat[len]) { 
			len++; 
			lps[i] = len; 
			i++; 
		} 
		else // (pat[i] != pat[len]) 
		{ 
			// This is tricky. Consider the example. 
			// AAACAAAA and i = 7. The idea is similar 
			// to search step. 
			if (len != 0) { 
				len = lps[len - 1]; 

				// Also, note that we do not increment 
				// i here 
			} 
			else // if (len == 0) 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
} 

// Driver program to test above function 
int main() 
{ 
	char txt[] = "ABABDABACDABABCABAB"; 
	char pat[] = "ABABCABAB"; 
	KMPSearch(pat, txt); 
	return 0; 
} 

-----------------------------------------------------------------------------------------------------------------


Given a string str we need to tell minimum characters to be added at front of string to make string palindrome.

Input  : str = "ABC"
Output : 2
We can make above string palindrome as "CBABC"
by adding 'B' and 'C' at front.

Input  : str = "AACECAAAA";
Output : 2
We can make above string palindrome as AAAACECAAAA
by adding two A's at front of string.

Efficient approach: We can solve this problem efficiently in O(n) time using lps array of KMP algorithm.
First we concat string by concatenating given string, a special character and reverse of given string then we will get lps array for this concatenated string, recall that each index of lps array represent longest proper prefix which is also suffix. We can use this lps array for solving the problem.

For string = AACECAAAA
Concatenated String = AACECAAAA$AAAACECAA
LPS array will be {0, 1, 0, 0, 0, 1, 2, 2, 2, 
                   0, 1, 2, 2, 2, 3, 4, 5, 6, 7}
Here we are only interested in the last value of this lps array because it shows us the largest suffix of the reversed string that matches
 the prefix of the original string i.e these many characters already satisfy the palindrome property. 
Finally minimum number of character needed to make the string a palindrome is length of the input string minus 
last entry of our lps array

