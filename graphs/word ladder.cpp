Given two words A and B, and a dictionary, C, find the length of shortest transformation sequence from A to B, such that:

You must change exactly one character in every transformation.
Each intermediate word must exist in the dictionary.


Input 1:
    A = "hit"
    B = "cog"
    C = ["hot", "dot", "dog", "lot", "log"]

Output 1:
    5

Explanation 1:
    "hit" -> "hot" -> "dot" -> "dog" -> "cog"
    
Approach: This problem can be solved using the standard BFS approach as discussed here but its performance 
can be improved by using bi-directional BFS

Therefore, two queues and two visited arrays are needed to be maintained to track both the paths. 
So, whenever a node (say A) is present in the source queue, encounters a node (say B) which is present in the target queue,
 then we can calculate the answer by adding the distance of A from source and the distance of B from target minus 1 (one node is common). 
 This way we can calculate the answer in half the time as compared to the standard BFS approach.
 This method is also known as the meet-in-the-middle BFS approach.
 
 // C++ implementation of the approach 
#include <bits/stdc++.h> 
using namespace std; 

// Structure for queue 
struct node { 
	string word; 
	int len; 
}; 

// Function that returns true if a and b 
// differ in only a single character 
bool isAdj(string a, string b) 
{ 
	int count = 0; 
	for (int i = 0; i < a.length(); i++) { 
		if (a[i] != b[i]) 
			count++; 
	} 
	if (count == 1) 
		return true; 
	return false; 
} 

// Function to return the length of the shortest 
// chain from ‘beginWord’ to ‘endWord’ 
int ladderLength(string beginWord, string endWord, 
				vector<string>& wordList) 
{ 

	/* q1 is used to traverse the graph from beginWord 
		and q2 is used to traverse the graph from endWord. 
		vis1 and vis2 are used to keep track of the 
		visited states from respective directions */
	queue<node> q1; 
	queue<node> q2; 
	unordered_map<string, int> vis1; 
	unordered_map<string, int> vis2; 

	node start = { beginWord, 1 }; 
	node end = { endWord, 1 }; 

	vis1[beginWord] = 1; 
	q1.push(start); 
	vis2[endWord] = 1; 
	q2.push(end); 

	while (!q1.empty() && !q2.empty()) { 

		// Fetch the current node 
		// from the source queue 
		node curr1 = q1.front(); 
		q1.pop(); 

		// Fetch the current node from 
		// the destination queue 
		node curr2 = q2.front(); 
		q2.pop(); 

		// Check all the neighbors of curr1 
		for (auto it = wordList.begin(); it != wordList.end(); it++) { 

			// If any one of them is adjacent to curr1 
			// and is not present in vis1 
			// then push it in the queue 
			if (isAdj(curr1.word, *it) && vis1.count(*it) == false) { 

				node temp = { *it, curr1.len + 1 }; 
				q1.push(temp); 
				vis1[*it] = curr1.len + 1; 

				// If temp is the destination node 
				// then return the answer 
				if (temp.word == endWord) { 
					return temp.len; 
				} 

				// If temp is present in vis2 i.e. distance from 
				// temp and the destination is already calculated 
				if (vis2.count(temp.word)) { 
					return temp.len + vis2[temp.word] - 1; 
				} 
			} 
		} 

		// Check all the neighbors of curr2 
		for (auto it = wordList.begin(); it != wordList.end(); it++) { 

			// If any one of them is adjacent to curr2 
			// and is not present in vis1 then push it in the queue. 
			if (isAdj(curr2.word, *it) && vis2.count(*it) == false) { 

				node temp = { *it, curr2.len + 1 }; 
				q2.push(temp); 
				vis2[*it] = curr2.len + 1; 

				// If temp is the destination node 
				// then return the answer 
				if (temp.word == beginWord) { 
					return temp.len; 
				} 

				// If temp is present in vis1 i.e. distance from 
				// temp and the source is already calculated 
				if (vis1.count(temp.word)) { 
					return temp.len + vis1[temp.word] - 1; 
				} 
			} 
		} 
	} 
	return 0; 
} 

// Driver code 
int main() 
{ 

	vector<string> wordList; 
	wordList.push_back("poon"); 
	wordList.push_back("plee"); 
	wordList.push_back("same"); 
	wordList.push_back("poie"); 
	wordList.push_back("plie"); 
	wordList.push_back("poin"); 
	wordList.push_back("plea"); 

	string start = "toon"; 
	string target = "plea"; 

	cout << ladderLength(start, target, wordList); 

	return 0; 
} 
------------------------------------------------------------------------------------------------------------------------

start = "hit"
end = "cog"
dict = ["hot","dot","dog","lot","log"]
Return

  [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
  ]
The idea is to first use BFS to search from beginWord to endWord and generate the word-to-children mapping at the same time. 
Then, use DFS (backtracking) to generate the transformation sequences according to the mapping.

class Solution {
    
    // Finds endWord by BFS and create parent->children word relations
    bool findEndWordByBFS(const string& beginWord, 
                          const string& endWord,
                          const vector<string>& wordList,
                          unordered_map<string, vector<string>>& children) {
        unordered_set<string> dict(wordList.begin(), wordList.end()), current, next;
        current.insert(beginWord);
        while (true) {
            for (string word : current) {
                dict.erase(word);
            }
            
            for (string word : current) {
                string parent = word;
                for (int i = 0; i < word.size(); i++) {
                    char t = word[i];
                    for (int j = 0; j < 26; j++) {
                        word[i] = 'a' + j;
                        if (dict.find(word) != dict.end()) {
                            next.insert(word);
                            children[parent].push_back(word);
                        }
                    }
                    word[i] = t;
                }
}
            
            if (next.empty())
                return false;
            
            if (next.find(endWord) != next.end())
                return true;
current.clear();
            swap(current, next);
        } 
        
        return false;
    }
    //  Use DFS (backtracking) to generate the transformation sequences according to the mapping
    void buildLadders(const string& beginWord,
                      const string& endWord,
                      vector<string>& ladder,
                      vector<vector<string>>& ladders,
                      unordered_map<string, vector<string>>& children) {
        if (beginWord == endWord) {
            ladders.push_back(ladder);
        } else {
            for (string word : children[beginWord]) {
                ladder.push_back(word);
                buildLadders(word, endWord, ladder, ladders, children);
                ladder.pop_back();
            }
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end())
            return {};
        unordered_map<string, vector<string>> children;
        if (!findEndWordByBFS(beginWord, endWord, wordList, children))
            return {};
        vector<vector<string>> ladders;
        vector<string> ladder;
        ladder.push_back(beginWord);
        buildLadders(beginWord, endWord, ladder, ladders, children);
        return ladders;
    }
};
