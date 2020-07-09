Node *LevelOrder(Node *root , int data)
{
     if(root==NULL){
        root = getNode(data);
        return root;
     }
     if(data <= root->data)
     root->left = LevelOrder(root->left, data);
     else
     root->right = LevelOrder(root->right, data);
     return root;
}

Node* constructBst(int arr[], int n)
{
    if(n==0)return NULL;
    Node *root =NULL;

    for(int i=0;i<n;i++)
    root = LevelOrder(root , arr[i]);

    return root;
}
