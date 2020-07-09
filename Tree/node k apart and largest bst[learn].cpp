

Given a binary tree, a target node in the binary tree, and an integer value k, print all the nodes that are at distance k from the given target node. No parent pointers are available.



               20 
                 \
            /
          8       22
      /      \
            
     4       12
            /  \
            
            10   14
            
    nput: target = pointer to node with data 8.
root = pointer to node with data 20.
k = 2.
Output : 10 14 22

If target is 14 and k is 3, then output
should be “4 20”

There are two types of nodes to be considered.
1) Nodes in the subtree rooted with target node. For example if the target node is 8 and k is 2, then such nodes are 10 and 14.
2) Other nodes, may be an ancestor of target, or a node in some other subtree. For target node 8 and k is 2, the node 22 comes in this category.

Finding the first type of nodes is easy to implement. Just traverse subtrees rooted with the target node and decrement k in recursive call. When the k becomes 0, print the node currently being traversed (See this for more details). Here we call the function as printkdistanceNodeDown().

How to find nodes of second type? For the output nodes not lying in the subtree with the target node as the root, we must go through all ancestors. For every ancestor, we find its distance from target node, let the distance be d, now we go to other subtree (if target was found in left subtree, then we go to right subtree and vice versa) of the ancestor and find all nodes at k-d distance from the ancestor.

Following is the implementation of the above approach.

#include <iostream> 
using namespace std; 

// A binary Tree node 
struct node 
{ 
	int data; 
	struct node *left, *right; 
}; 

/* Recursive function to print all the nodes at distance k in the 
tree (or subtree) rooted with given root. See */
void printkdistanceNodeDown(node *root, int k) 
{ 
	// Base Case 
	if (root == NULL || k < 0) return; 

	// If we reach a k distant node, print it 
	if (k==0) 
	{ 
		cout << root->data << endl; 
		return; 
	} 

	// Recur for left and right subtrees 
	printkdistanceNodeDown(root->left, k-1); 
	printkdistanceNodeDown(root->right, k-1); 
} 

// Prints all nodes at distance k from a given target node. 
// The k distant nodes may be upward or downward. This function 
// Returns distance of root from target node, it returns -1 if target 
// node is not present in tree rooted with root. 
int printkdistanceNode(node* root, node* target , int k) 
{ 
	// Base Case 1: If tree is empty, return -1 
	if (root == NULL) return -1; 

	// If target is same as root. Use the downward function 
	// to print all nodes at distance k in subtree rooted with 
	// target or root 
	if (root == target) 
	{ 
		printkdistanceNodeDown(root, k); 
		return 0; 
	} 

	// Recur for left subtree 
	int dl = printkdistanceNode(root->left, target, k); 

	// Check if target node was found in left subtree 
	if (dl != -1) 
	{ 
		// If root is at distance k from target, print root 
		// Note that dl is Distance of root's left child from target 
		if (dl + 1 == k) 
			cout << root->data << endl; 

		// Else go to right subtree and print all k-dl-2 distant nodes 
		// Note that the right child is 2 edges away from left child 
		else
			printkdistanceNodeDown(root->right, k-dl-2); 

		// Add 1 to the distance and return value for parent calls 
		return 1 + dl; 
	} 

	// MIRROR OF ABOVE CODE FOR RIGHT SUBTREE 
	// Note that we reach here only when node was not found in left subtree 
	int dr = printkdistanceNode(root->right, target, k); 
	if (dr != -1) 
	{ 
		if (dr + 1 == k) 
			cout << root->data << endl; 
		else
			printkdistanceNodeDown(root->left, k-dr-2); 
		return 1 + dr; 
	} 

	// If target was neither present in left nor in right subtree 
	return -1; 
} 

// A utility function to create a new binary tree node 
node *newnode(int data) 
{ 
	node *temp = new node; 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 

// Driver program to test above functions 
int main() 
{ 
	/* Let us construct the tree shown in above diagram */
	node * root = newnode(20); 
	root->left = newnode(8); 
	root->right = newnode(22); 
	root->left->left = newnode(4); 
	root->left->right = newnode(12); 
	root->left->right->left = newnode(10); 
	root->left->right->right = newnode(14); 
	node * target = root->left->right; 
	printkdistanceNode(root, target, 2); 
	return 0; 
}
*****************************************************************************************************

largest bst in binary tree

    50
     /    \
  30       60
 /  \     /  \ 
5   20   45    70
              /  \
            65    80
Output: 5



// C++ program to find largest BST in a 
// Binary Tree. 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, 
pointer to left child and a 
pointer to right child */
struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
}; 

/* Helper function that allocates a new 
node with the given data and NULL left 
and right pointers. */
struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 

	return(node); 
} 

// Information to be returned by every 
// node in bottom up traversal. 
struct Info 
{ 
	int sz; // Size of subtree 
	int max; // Min value in subtree 
	int min; // Max value in subtree 
	int ans; // Size of largest BST which 
	// is subtree of current node 
	bool isBST; // If subtree is BST 
}; 

// Returns Information about subtree. The 
// Information also includes size of largest 
// subtree which is a BST. 
Info largestBSTBT(Node* root) 
{ 
	// Base cases : When tree is empty or it has 
	// one child. 
	if (root == NULL) 
		return {0, INT_MIN, INT_MAX, 0, true}; 
	if (root->left == NULL && root->right == NULL) 
		return {1, root->data, root->data, 1, true}; 

	// Recur for left subtree and right subtrees 
	Info l = largestBSTBT(root->left); 
	Info r = largestBSTBT(root->right); 

	// Create a return variable and initialize its 
	// size. 
	Info ret; 
	ret.sz = (1 + l.sz + r.sz); 

	// If whole tree rooted under current root is 
	// BST. 
	if (l.isBST && r.isBST && l.max < root->data && 
			r.min > root->data) 
	{ 
		ret.min = min(l.min, min(r.min, root->data)); 
		ret.max = max(r.max, max(l.max, root->data)); 

		// Update answer for tree rooted under 
		// current 'root' 
		ret.ans = ret.sz; 
		ret.isBST = true; 

		return ret; 
	} 

	// If whole tree is not BST, return maximum 
	// of left and right subtrees 
	ret.ans = max(l.ans, r.ans); 
	ret.isBST = false; 

	return ret; 
} 

/* Driver program to test above functions*/
int main() 
{ 
	/* Let us construct the following Tree 
		60 
	/ \ 
	65 70 
	/ 
	50 */

	struct Node *root = newNode(60); 
	root->left = newNode(65); 
	root->right = newNode(70); 
	root->left->left = newNode(50); 
	printf(" Size of the largest BST is %d\n", 
		largestBSTBT(root).ans); 
	return 0; 
} 


