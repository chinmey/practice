

// A recursive program to test whether a given 
// string can be segmented into space separated 
// words in dictionary 
#include <iostream> 
using namespace std; 

/* A utility function to check whether a word is 
present in dictionary or not. An array of strings 
is used for dictionary. Using array of strings for 
dictionary is definitely not a good idea. We have 
used for simplicity of the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung", 
							"man","mango","icecream","and", 
							"go","i","like","ice","cream","leet","code"}; 
	int size = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
		return true; 
	return false; 
} 

// returns true if string can be segmented into space 
// separated words, otherwise returns false 
bool wordBreak(string str) 
{ 
	int size = str.size(); 

	// Base case 
	if (size == 0) return true; 

	// Try all prefixes of lengths from 1 to size 
	for (int i=1; i<=size; i++) 
	{ 
		// The parameter for dictionaryContains is 
		// str.substr(0, i) which is prefix (of input 
		// string) of length 'i'. We first check whether 
		// current prefix is in dictionary. Then we 
		// recursively check for remaining string 
		// str.substr(i, size-i) which is suffix of 
		// length size-i 
		if (dictionaryContains( str.substr(0, i) ) && 
			wordBreak( str.substr(i, size-i) )) 
			return true; 
	} 

	// If we have tried all prefixes and 
	// none of them worked 
	return false; 
} 

// Driver program to test above functions 
int main() 
{ 
	wordBreak("ilikeleetcode")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
	return 0; 
} 

-------------------------------------------------------------------------------------------------------------------------------------------------------------------
// A Dynamic Programming based program to test whether a given string can 
// be segmented into space separated words in dictionary 
#include <iostream> 
#include <string.h> 
using namespace std; 

/* A utility function to check whether a word is present in dictionary or not. 
An array of strings is used for dictionary. Using array of strings for 
dictionary is definitely not a good idea. We have used for simplicity of 
the program*/
int dictionaryContains(string word) 
{ 
	string dictionary[] = {"mobile","samsung","sam","sung","man","mango", 
						"icecream","and","go","i","like","ice","cream"}; 
	int size = sizeof(dictionary)/sizeof(dictionary[0]); 
	for (int i = 0; i < size; i++) 
		if (dictionary[i].compare(word) == 0) 
		return true; 
	return false; 
} 

// Returns true if string can be segmented into space separated 
// words, otherwise returns false 
bool wordBreak(string str) 
{ 
	int size = str.size(); 
	if (size == 0) return true; 

	// Create the DP table to store results of subroblems. The value wb[i] 
	// will be true if str[0..i-1] can be segmented into dictionary words, 
	// otherwise false. 
	bool wb[size+1]; 
	memset(wb, 0, sizeof(wb)); // Initialize all values as false. 

	for (int i=1; i<=size; i++) 
	{ 
		// if wb[i] is false, then check if current prefix can make it true. 
		// Current prefix is "str.substr(0, i)" 
		if (wb[i] == false && dictionaryContains( str.substr(0, i) )) 
			wb[i] = true; 

		// wb[i] is true, then check for all substrings starting from 
		// (i+1)th character and store their results. 
		if (wb[i] == true) 
		{ 
			// If we reached the last prefix 
			if (i == size) 
				return true; 

			for (int j = i+1; j <= size; j++) 
			{ 
				// Update wb[j] if it is false and can be updated 
				// Note the parameter passed to dictionaryContains() is 
				// substring starting from index 'i' and length 'j-i' 
				if (wb[j] == false && dictionaryContains( str.substr(i, j-i) )) 
					wb[j] = true; 

				// If we reached the last character 
				if (j == size && wb[j] == true) 
					return true; 
			} 
		} 
	} 

	/* Uncomment these lines to print DP table "wb[]" 
	for (int i = 1; i <= size; i++) 
		cout << " " << wb[i]; */

	// If we have tried all prefixes and none of them worked 
	return false; 
} 

// Driver program to test above functions 
int main() 
{ 
	wordBreak("ilikesamsung")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("iiiiiiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("ilikelikeimangoiii")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmango")? cout <<"Yes\n": cout << "No\n"; 
	wordBreak("samsungandmangok")? cout <<"Yes\n": cout << "No\n"; 
	return 0; 
} */

it has a optimised version check it on gfg
-----------------------------------------------------------------------------------------------------------------------------------

word break 2

Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, 
add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences



check out genetic coders solution /* importabt*/


s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
Output:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]

basic idea is that for s we go through all words in wordDict if any matches we redo this process for rest of the string  , 
whenever we reach at end we return " "

map<string,vector<string>>mp; // this is used for memorisation so that we dont check same substring again and again

vector<string> f(string s,wordDict)
{
	if(s.empty()==true) return " ";
	
	if(mp[s]!=0) return mp[s];
	
	vector<string>p;
	for(string word:wordDict)
	{
		if(s.substr(0,word.length())!=word) continue;
		
		p=f(s.substr(word.length()),wordDict);
		
		for(string k:p)
		{
			word +' '+k;
		}
		mp[s]=p;
		return mp[s];
	}
	
	
	
	
	
	
	
}

