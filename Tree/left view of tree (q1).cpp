/*Input :
        1
      /   \
    2       3
      \   
        4  
          \
            5
             \
               6
Output :1 2 4 5 6

left view are elements visible from left side / first elemnet at each level(in level order traversal)
Right view are last element at each level

Input : 
                 1
               /   \
              2     3
              \    / \
               5   2.5  6             
Output : 1 2 5  --left 
Output : 1 3 6  --right  */

void leftViewUtil(node *root, int level, int *max_level)  
{  
     
    if (root==NULL) return;  
  
    // If this is the first node of its level  
    if (*max_level < level)  
    {  
        cout<<root->data<<"\t";  
        *max_level = level;  
    }  
  
      
    leftViewUtil(root->left, level+1, max_level);  /* just reverse these two to obtain right view of tree*/
    leftViewUtil(root->right, level+1, max_level);  
}  
  

void leftView(node *root)  
{  
    int max_level = 0;  
    leftViewUtil(root, 1, &max_level);  
} 

------------------------------------------------

using queue
 queue<Node *>q;
   q.push(root);
   while(!q.empty())
   {
       int n=q.size();
       for(i=1;i<=n;i++)
       {
           Node *x=q.front();
           q.pop();
           if(i==1)
           cout<<x->data<<" ";
        
           if(x->left!=NULL)
           q.push(x->left);
                if(x->right!=NULL)
           q.push(x->right);
         
       }
       
       
   }
}



