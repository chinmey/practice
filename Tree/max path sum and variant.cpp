
simlar to distribute coins try to relate
Input: Root of below tree
       1
      / \
     2   3
Output: 6

basically 4 path ho sakte h root+left ,root+right,only root, root+left+right(but possible only once in a tree)
// C/C++ program to find maximum path sum in Binary Tree 
#include<bits/stdc++.h> 
using namespace std; 

// A binary tree node 
struct Node 
{ 
	int data; 
	struct Node* left, *right; 
}; 

// A utility function to allocate a new node 
struct Node* newNode(int data) 
{ 
	struct Node* newNode = new Node; 
	newNode->data = data; 
	newNode->left = newNode->right = NULL; 
	return (newNode); 
} 

// This function returns overall maximum path sum in 'res' 
// And returns max path sum going through root. 
int findMaxUtil(Node* root, int &res) 
{ 
	//Base Case 
	if (root == NULL) 
		return 0; 

	// l and r store maximum path sum going through left and 
	// right child of root respectively 
	int l = findMaxUtil(root->left,res); 
	int r = findMaxUtil(root->right,res); 

	// Max path for parent call of root. This path must 
	// include at-most one child of root 
	int max_single = max(max(l, r) + root->data, root->data); 

	// Max Top represents the sum when the Node under 
	// consideration is the root of the maxsum path and no 
	// ancestors of root are there in max sum path 
	int max_top = max(max_single, l + r + root->data); 

	res = max(res, max_top); // Store the Maximum Result. 

	return max_single; 
} 

// Returns maximum path sum in tree with given root 
int findMaxSum(Node *root) 
{ 
	// Initialize result 
	int res = INT_MIN; 

	// Compute and return result 
	findMaxUtil(root, res); 
	return res; 
} 

// Driver program 
int main(void) 
{ 
	struct Node *root = newNode(10); 
	root->left	 = newNode(2); 
	root->right	 = newNode(10); 
	root->left->left = newNode(20); 
	root->left->right = newNode(1); 
	root->right->right = newNode(-25); 
	root->right->right->left = newNode(3); 
	root->right->right->right = newNode(4); 
	cout << "Max path sum is " << findMaxSum(root); 
	return 0; 
}
------------------------------------------------------------------------------------------------------------------------------------------
maximum differnce between node and ancestor

// Helper function to find maximum difference between a node and its
// descendants in a binary tree
int maxDifference(Node* root, int &diff)
{
    // base case: if tree is empty, return infinity
    if (root == nullptr)
        return INT_MAX;

    // recur for left and right subtree
    int left = maxDifference(root->left, diff);
    int right = maxDifference(root->right, diff);

    // find maximum difference between current node and its descendants
    int d = root->data - min(left, right);

    // update the maximum difference found so far if required
    diff = max(diff, d);

    // in order for difference to be maximum, the function should return
    // minimum value among all nodes in sub-tree rooted at it
    return min(min(left, right), root->data);
}

// Find maximum difference between a node and its descendants in a binary tree
int maxDifference(Node *root)
{
    int diff = INT_MIN;
    maxDifference(root, diff);

    return diff;
}


