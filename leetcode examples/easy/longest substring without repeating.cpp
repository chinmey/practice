Given a string, find the length of the longest substring without repeating characters.

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 

solution 1 -- slidind window easy to understand

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
           int n=s.size();
        
        set<char>m;
        
        
        int ans=0,i=0,j=0;
        
        while(i<n && j<n)
        {
            if(m.find(s[j])==m.end())
            {
                m.insert(s[j++]);
                ans=max(ans,j-i);
            }
            else{
            m.erase(s[i++]);}
        }
        return ans;
    }
       
};

Method 2 (Linear Time): Let us talk about the linear time solution now. This solution uses extra space to store the last indexes of already visited characters. 
The idea is to scan the string from left to right, keep track of the maximum length Non-Repeating Character Substring (NRCS) seen so far. Let the maximum length be max_len.
 When we traverse the string, we also keep track of the length of the current NRCS using cur_len variable. 
 For every new character, we look for it in already processed part of the string (A temp array called visited[] is used for this purpose).
  If it is not present, then we increase the cur_len by 1. If present, then there are two cases:

The previous instance of character is not part of current NRCS (The NRCS which is under process). In this case, we need to simply increase cur_len by 1.
If the previous instance is part of the current NRCS, then our current NRCS changes. It becomes the substring starting from the next character of the previous instance to currently scanned character.
 We also need to compare cur_len and max_len, before changing current NRCS (or changing cur_len).
 
 // C++ program to find the length of the longest substring 
// without repeating characters 
#include <bits/stdc++.h> 
using namespace std; 
#define NO_OF_CHARS 256 

int longestUniqueSubsttr(string str) 
{ 
	int n = str.size(); 
	int cur_len = 1; // length of current substring 
	int max_len = 1; // result 
	int prev_index; // previous index 
	
	int* visited = new int[sizeof(int) * NO_OF_CHARS]; 

	/* Initialize the visited array as -1, -1 is used to 
	indicate that character has not been visited yet. */
	for (int i = 0; i < NO_OF_CHARS; i++) 
		visited[i] = -1; 

	/* Mark first character as visited by storing the index 
	of first character in visited array. */
	visited[str[0]] = 0; 

	/* Start from the second character. First character is 
	already processed (cur_len and max_len are initialized 
	as 1, and visited[str[0]] is set */
	for (int i = 1; i < n; i++) { 
		prev_index = visited[str[i]]; 

		/* If the currentt character is not present in the 
		already processed substring or it is not part of 
		the current NRCS, then do cur_len++ */
		if (prev_index == -1 || i - cur_len > prev_index) 
			cur_len++; 

		/* If the current character is present in currently 
		considered NRCS, then update NRCS to start from 
		the next character of the previous instance. */
		else { 
			/* Also, when we are changing the NRCS, we 
			should also check whether length of the 
			previous NRCS was greater than max_len or 
			not.*/
			if (cur_len > max_len) 
				max_len = cur_len; 

			cur_len = i - prev_index; 
		} 

		// update the index of current character 
		visited[str[i]] = i; 
	} 

	// Compare the length of last NRCS with max_len and 
	// update max_len if needed 
	if (cur_len > max_len) 
		max_len = cur_len; 

	free(visited); // free memory allocated for visited 
	return max_len; 
} 


// Driver code 
int main() 
{ 
	string str = "ABDEFGABEF"; 
	
	cout << "The input string is " << str << endl; 
	
	int len = longestUniqueSubsttr(str); 
	
	cout << "The length of the longest non-repeating "
			"character substring is "
		<< len; 
	return 0; 
} 

// This code is contributed by rathbhupendra 

