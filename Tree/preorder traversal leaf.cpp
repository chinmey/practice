Input: given preorder traversal of tree find leaf nodes
2
5
890 325 290 530 965 
3
3 2 4

Output:
290 530 965
2 4





#include<bits/stdc++.h>
using namespace std;
void show(int *arr,int n)
{
    stack<int>s;
    for(int i=0, j=1;j<n;i++,j++)
    {
        bool a=false;
        if(arr[i]>arr[j])
        s.push(arr[i]);
        else
        {
            while(s.empty()==false)
            {
                if(arr[j]>s.top())
                {
                    s.pop();
                    a=true;
                }
                else
                {
                    break;
                }
            }
        }
        if(a)
        cout<<arr[i]<<" ";
    }
    cout<<arr[n-1]<<endl;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    show(arr,n);
	}
	return 0;
}

-----------------------------------------------------------------------------------------------------------------------
valid bst
  
int isBSTUtil(node* node, int min, int max);  
  
/* Returns true if the given  
tree is a binary search tree  
(efficient version). */
int isBST(node* node)  
{  
    return(isBSTUtil(node, INT_MIN, INT_MAX));  
}  
  
/* Returns true if the given 
tree is a BST and its values 
are >= min and <= max. */
int isBSTUtil(node* node, int min, int max)  
{  
    /* an empty tree is BST */
    if (node==NULL)  
        return 1;  
              
    /* false if this node violates 
    the min/max constraint */
    if (node->data < min || node->data > max)  
        return 0;  
      
    /* otherwise check the subtrees recursively,  
    tightening the min or max constraint */
    return
        isBSTUtil(node->left, min, node->data-1) && // Allow only distinct values  
        isBSTUtil(node->right, node->data+1, max); // Allow only distinct values  
}  
  
