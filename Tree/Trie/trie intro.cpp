/******************************************************************************

  used to do prefix search for a array of string , if a string starting with particular prefix exists or not and so on

*******************************************************************************/

Trie is an efficient information reTrieval data structure. Using Trie, search complexities can be brought to optimal limit (key length).
 If we store keys in binary search tree, a well balanced BST will need time proportional to M * log N, where M is maximum string length and N 
 is number of keys in tree. Using Trie, we can search the key in O(M) time.
 However the penalty is on Trie storage requirements (Please refer Applications of Trie for more details)

// C++ implementation of search and insert 
// operations on Trie 
#include <bits/stdc++.h> 
using namespace std; 

const int ALPHABET_SIZE = 26; 

// trie node 
struct TrieNode 
{ 
	struct TrieNode *children[ALPHABET_SIZE]; 

	// isEndOfWord is true if the node represents 
	// end of a word 
	bool isEndOfWord; 
}; 

// Returns new trie node (initialized to NULLs) 
struct TrieNode *getNode(void) 
{ 
	struct TrieNode *pNode = new TrieNode; 

	pNode->isEndOfWord = false; 

	for (int i = 0; i < ALPHABET_SIZE; i++) 
		pNode->children[i] = NULL; 

	return pNode; 
} 

// If not present, inserts key into trie 
// If the key is prefix of trie node, just 
// marks leaf node 
// time to inset O(length of key*height)
void insert(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) {
		    TrieNode* temp=getNode();
			pCrawl->children[index] = temp;
		}

		pCrawl = pCrawl->children[index]; 
	} 

	// mark last node as leaf 
	pCrawl->isEndOfWord = true; 
} 

// Returns true if key presents in trie, else 
// false 
// time to search O(length of key)
bool search(struct TrieNode *root, string key) 
{ 
	struct TrieNode *pCrawl = root; 

	for (int i = 0; i < key.length(); i++) 
	{ 
		int index = key[i] - 'a'; 
		if (!pCrawl->children[index]) 
			return false; 

		pCrawl = pCrawl->children[index]; 
	} 

	return (pCrawl != NULL && pCrawl->isEndOfWord); 
}

// Returns true if root has no children, else false 
bool isEmpty(TrieNode* root) 
{ 
    for (int i = 0; i < ALPHABET_SIZE; i++) 
        if (root->children[i]) 
            return false; 
    return true; 
} 
  
// Recursive function to delete a key from given Trie 
TrieNode* remove(TrieNode* root, string key, int depth = 0) 
{ 
    // If tree is empty 
    if (!root) 
        return NULL; 
  
    // If last character of key is being processed 
    if (depth == key.size()) { 
  
        // This node is no more end of word after 
        // removal of given key 
        if (root->isEndOfWord) 
            root->isEndOfWord = false; 
  
        // If given is not prefix of any other word 
        if (isEmpty(root)) { 
            delete (root); 
            root = NULL; 
        } 
  
        return root; 
    } 
  
    // If not last character, recur for the child 
    // obtained using ASCII value 
    int index = key[depth] - 'a'; 
    root->children[index] =  
          remove(root->children[index], key, depth + 1); 
  
    // If root does not have any child (its only child got  
    // deleted), and it is not end of another word. 
    if (isEmpty(root) && root->isEndOfWord == false) { 
        delete (root); 
        root = NULL; 
    } 
  
    return root; 
}  

// Driver 
int main() 
{ 
	// Input keys (use only 'a' through 'z' 
	// and lower case) 
	string keys[] = {"the", "a", "there", 
					"answer", "any", "by", 
					"bye", "their" }; 
	int n = sizeof(keys)/sizeof(keys[0]); 

	struct TrieNode *root = getNode(); 

	// Construct trie 
	for (int i = 0; i < n; i++) 
		insert(root, keys[i]); 

	// Search for different keys 
	search(root, "the")? cout << "Yes\n" : 
						cout << "No\n"; 
	search(root, "these")? cout << "Yes\n" : 
						cout << "No\n"; 
						
	  remove(root, "answer");
	return 0; 
} 
