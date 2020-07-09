/*

 Input Tree
       A
      / \
     B   C
    / \   \
   D   E   F


Output Tree
       A--->NULL
      / \
     B-->C-->NULL
    / \   \
   D-->E-->F-->NULL

   we would be passing an argument called nextRight we need to connect it*/

/*modified level order traversal is used with NULL used to indicate end of a level*/


void connect(Node *p)
{
   queue<Node *>q;
   q.push(p);
   q.push(NULL);
   while(!q.empty())
   {
       Node *p=q.front();
       q.pop();
       if(p!=NULL)
       {
           p->nextRight=q.front();
           if(p->left!=NULL)
           q.push(p->left);
           if(p->right!=NULL)
           q.push(p->right);

       }
       else if(!q.empty())
       q.push(NULL);
   }

}

------------------------------------------------------------------------------------------------------------

using constant extra space(read from gfg)

node *getNextRight(node *p)  
{  
    node *temp = p->nextRight;  
  
    /* Traverse nodes at p's level 
    and find and return the first  
    node's first child */
    while (temp != NULL)  
    {  
        if (temp->left != NULL)  
            return temp->left;  
        if (temp->right != NULL)  
            return temp->right;  
        temp = temp->nextRight;  
    }  
  
    // If all the nodes at p's level  
    // are leaf nodes then return NULL  
    return NULL;  
}  
  
/* Sets nextRight of all nodes 
of a tree with root as p */
void connectRecur(node* p)  
{  
    node *temp;  
  
    if (!p)  
    return;  
  
    // Set nextRight for root  
    p->nextRight = NULL;  
  
    // set nextRight of all levels one by one  
    while (p != NULL)  
    {  
        node *q = p;  
  
        /* Connect all childrem nodes of p and 
        children nodes of all other nodes at 
        same level as p */
        while (q != NULL)  
        {  
            // Set the nextRight pointer 
            // for p's left child  
            if (q->left)  
            {  
                // If q has right child, then  
                // right child is nextRight of  
                // p and we also need to set 
                // nextRight of right child  
                if (q->right)  
                    q->left->nextRight = q->right;  
                else
                    q->left->nextRight = getNextRight(q);  
            }  
  
            if (q->right)  
                q->right->nextRight = getNextRight(q);  
  
            // Set nextRight for other  
            // nodes in pre order fashion  
            q = q->nextRight;  
        }  
  
        // start from the first  
        // node of next level  
        if (p->left)  
            p = p->left;  
        else if (p->right)  
            p = p->right;  
        else
            p = getNextRight(p);  
    }  
}  

