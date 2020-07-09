void bToDLL(Node *root, Node **head_ref)
{
    if(root==NULL)
    return;
    static Node *pre=NULL;/*only one copy for entire recursion*/
    bToDLL(root->left,head_ref);
    if(pre==NULL)
    *head_ref=root;
    else
    {
     root->left=pre;
     pre->right=root;
    }
    pre=root;
    bToDLL(root->right,head_ref);

}
/*check vivekanand video if any doubt*/

flatten tree to linked list

Input :
        1
       / \
      3   4
         /
        2
         \
          5
Output :
     1
      \
       3
        \
         4
          \
           2
            \ 
             5
             
TreeNode* Solution::flatten(TreeNode* A) {
 

    if(A==NULL) return NULL;
    
    stack<TreeNode*>s;
    s.push(A);
    while(s.empty()==false)
    {
        TreeNode* x=s.top();
        s.pop();
        
      
        
        if(x->right!=NULL) s.push(x->right);
        
          if(x->left!=NULL) s.push(x->left);
        if(s.empty()==false)
        x->right=s.top();
        x->left=NULL;
    }
    return A;
}


**************************************************************************************

postorder without stack
// CPP program or postorder traversal 
#include <bits/stdc++.h> 
using namespace std; 

/* A binary tree node has data, pointer to left child 
and a pointer to right child */
struct Node { 
	int data; 
	struct Node *left, *right; 
	bool visited; 
}; 

void postorder(struct Node* head) 
{ 
	struct Node* temp = head; 
	while (temp && temp->visited == false) { 

		// Visited left subtree 
		if (temp->left && temp->left->visited == false) 
			temp = temp->left; 

		// Visited right subtree 
		else if (temp->right && temp->right->visited == false) 
			temp = temp->right; 

		// Print node 
		else { 
			printf("%d ", temp->data); 
			temp->visited = true; 
			temp = head; 
		} 
	} 
} 

struct Node* newNode(int data) 
{ 
	struct Node* node = new Node; 
	node->data = data; 
	node->left = NULL; 
	node->right = NULL; 
	node->visited = false; 
	return (node); 
} 

/* Driver program to test above functions*/
int main() 
{ 
	struct Node* root = newNode(8); 
	root->left = newNode(3); 
	root->right = newNode(10); 
	root->left->left = newNode(1); 
	root->left->right = newNode(6); 
	root->left->right->left = newNode(4); 
	root->left->right->right = newNode(7); 
	root->right->right = newNode(14); 
	root->right->right->left = newNode(13); 
	postorder(root); 
	return 0; 
} 

