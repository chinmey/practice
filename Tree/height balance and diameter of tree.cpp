/*To check if a tree is height-balanced, get the height of left and right subtrees.
Return true if difference between heights is not more than 1
and left and right subtrees are balanced, otherwise return false.*/



int height(Node *root)
{
    if(root==NULL)
    return 0;
    int l,r;
    l=height(root->left);
    r=height(root->right);
    return max(l,r)+1;
}
bool isBalanced(Node *root)
{
    int lh,rh;
    if(root==NULL)
    return 1;
    lh=height(root->left);
    rh=height(root->right);
    if(abs(lh-rh)<=1 && isBalanced(root->left) && isBalanced(root->right))
    return 1;
    return 0;
}

/*

          1
     /      \
   2        3
The diameter is of 3 length.(lh+rh)


 but if both nodes are at same side lh+rh won't work


         1

     /
     2
 /  \

 4   5
 /\   / \
 8 10  29 35
*/

int height(Node *node)
{
    if(node==NULL)
    return 0;
    return 1+max(height(node->left),height(node->right));
}
int diameter(Node* node)
{
  if(node==NULL)
  return 0;
  int option1=height(node->left)+height(node->right);
  int option2=diameter(node->left);
  int option3=diameter(node->right);
  return 1+ max(option1,max(option2,option3));
}
