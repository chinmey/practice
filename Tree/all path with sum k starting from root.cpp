/*Input : sum = 8, 
        Root of tree
         1
       /   \
     20      3
           /    \
         4       15    
        /  \     /  \
       6    7   8    9 
       
       Output :
Path: 1 3 4*/

// C++ program to print all paths begiinning with 
// root and sum as given sum 
#include<bits/stdc++.h> 
using namespace std; 

// A Tree node 
struct Node 
{ 
	int key; 
	struct Node *left, *right; 
}; 

// Utility function to create a new node 
Node* newNode(int key) 
{ 
	Node* temp = new Node; 
	temp->key = key; 
	temp->left = temp->right = NULL; 
	return (temp); 
} 


void printPathsUtil(Node* curr_node, int sum, 
			int sum_so_far, vector<int> &path) 
{ 
	if (curr_node == NULL) 
		return; 

	// add the current node's value 
	sum_so_far += curr_node->key; 

	// add the value to path 
	path.push_back(curr_node->key); 

	// print the required path 
	if (sum_so_far == sum )  /* && !cur_node->left  && !cur_node->right if we are given path is from root to leaf*/     
	{ 
		cout << "Path found: "; 
		for (int i=0; i<path.size(); i++) 
			cout << path[i] << " "; 

		cout << endl; 
	} 

	// if left child exists 
	if (curr_node->left != NULL) 
		printPathsUtil(curr_node->left, sum, sum_so_far, path); 

	// if right child exists 
	if (curr_node->right != NULL) 
		printPathsUtil(curr_node->right, sum, sum_so_far, path); 


	// Remove last element from path 
	// and move back to parent 
	path.pop_back(); 
} 

// Wrapper over printPathsUtil 
void printPaths(Node *root, int sum) 
{ 
	vector<int> path; 
	printPathsUtil(root, sum, 0, path); 
} 

// Driver program 
int main () 
{ 
	/* 10 
	/	 \ 
	28	 13 
		/	 \ 
		14	 15 
		/ \	 / \ 
	21 22 23 24*/
	Node *root = newNode(10); 
	root->left = newNode(28); 
	root->right = newNode(13); 

	root->right->left = newNode(14); 
	root->right->right = newNode(15); 

	root->right->left->left = newNode(21); 
	root->right->left->right = newNode(22); 
	root->right->right->left = newNode(23); 
	root->right->right->right = newNode(24); 

	int sum = 38; 

	printPaths(root, sum); 

	return 0; 
} 

