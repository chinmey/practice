/*
        1
      /   \
    2       2
  /   \   /   \
 3     4 4     3  -----mirror image


       1
     /   \
    2      2
     \      \
      3      3 ------not mirror

*/

bool find(Node *l,Node *r)
{
if((l&& !r) || (l && !r)) return 0;
if(!l && !r) return 1;
if(l->key != r->key) return 0;

return (find(l->left,r->right)&&find(l->right,r->left));
}
bool isSymmetric(struct Node* root)
{
if(root) return find(root->left,root->right);
return NULL;}

------------------------------------------------------------------------------


int countLeaves(Node* root)
{

  if(root==NULL)
  return 0;
  if(root->left==NULL && root->right==NULL)
  return 1;
  return countLeaves(root->left)+countLeaves(root->right);




}

/* if we are asked to delete all leaf nodes all we need to do is preorder traversal and delete*/

Node *deleteleaf(node *root)
{
    if(root->left==NULL&& root->right==NULL)
    {
        delete(root);
        return NULL;
    }
    root->left=deleteleaf(root->left);
    root->right=deleteleaf(root->right);

}
