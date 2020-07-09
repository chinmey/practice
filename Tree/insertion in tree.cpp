// C++ program to demonstrate insert operation 
// in binary search tree 
#include <bits/stdc++.h> 
using namespace std; 

// BST node 
struct Node { 
	int key; 
	struct Node *left, *right; 
}; 

// Utitlity function to create a new node 
Node* newNode(int data) 
{ 
	Node* temp = new Node(); 

	temp->key = data; 

	temp->left = NULL; 
	temp->right = NULL; 

	return temp; 
} 

// A utility function to insert a new 
// Node with given key in BST 
Node* insert(Node* root, int key) 
{ 
	// Create a new Node containing 
	// the new element 
	Node* newnode = newNode(key); 

	// Pointer to start traversing from root and 
	// traverses downward path to search 
	// where the new node to be inserted 
	Node* x = root; 

	// Pointer y maintains the trailing 
	// pointer of x 
	Node* y = NULL; 

	while (x != NULL) { 
		y = x; 
		if (key < x->key) 
			x = x->left; 
		else
			x = x->right; 
	} 

	// If the root is NULL i.e the tree is empty 
	// The new node is the root node 
	if (y == NULL) 
		y = newnode; 

	// If the new key is less then the leaf node key 
	// Assign the new node to be its left child 
	else if (key < y->key) 
		y->left = newnode; 

	// else assign the new node its right child 
	else
		y->right = newnode; 

	// Returns the pointer where the 
	// new node is inserted 
	return y; 
} 

// A utility function to do inorder 
// traversal of BST 
void Inorder(Node* root) 
{ 
	if (root == NULL) 
		return; 
	else { 
		Inorder(root->left); 
		cout << root->key << " "; 
		Inorder(root->right); 
	} 
} 

// Driver code 
int main() 
{ 
	/* Let us create following BST 
			50 
		/ \ 
		30	 70 
		/ \ / \ 
	20 40 60 80 */

	Node* root = NULL; 
	root = insert(root, 50); 
		root = insert(root, 30); 
		root = insert(root, 20); 
		root = insert(root, 40); 
		root = insert(root, 70); 
		root = insert(root, 60); 
		root = insert(root, 80); 

	// Print inoder traversal of the BST 
	Inorder(root); 

	return 0; 
} 
/* or we can insert recursively*/
struct node* insert(struct node* node, int key) 
{ 
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key); 
  
    /* Otherwise, recur down the tree */
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else
        node->right = insert(node->right, key); 
  
    /* return the (unchanged) node pointer */
    return node; 
} 

/* delete node in a tree


1) Node to be deleted is leaf: Simply remove from the tree
2) Node to be deleted has only one child: Copy the child to the node and delete the child
3) Node to be deleted has two children: Find inorder successor of the node. 
Copy contents of the inorder successor to the node and delete the inorder successor. Note that inorder predecessor can also be used.*/
struct node* deleteNode(struct node* root, int key) 
{ 
    // base case 
    if (root == NULL) return root; 
  
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    if (key < root->key) 
        root->left = deleteNode(root->left, key); 
  
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (key > root->key) 
        root->right = deleteNode(root->right, key); 
  
    // if key is same as root's key, then This is the node 
    // to be deleted 
    else
    { 
        // node with only one child or no child 
        if (root->left == NULL) 
        { 
            struct node *temp = root->right; 
            free(root); 
            return temp; 
        } 
        else if (root->right == NULL) 
        { 
            struct node *temp = root->left; 
            free(root); 
            return temp; 
        } 
  
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        struct node* temp = minValueNode(root->right); 
  
        // Copy the inorder successor's content to this node 
        root->key = temp->key; 
  
        // Delete the inorder successor 
        root->right = deleteNode(root->right, temp->key); 
    } 
    return root; 
} 
