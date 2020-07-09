You are given a Singly Linked List with N nodes where each node next pointing to its next node,you are also given M random pointer
where you will be given M number of pairs denoting two nodes a and b  i.e. a->arb = b.


--------------------------------------------------------------
sol-- All we need to do is to traverse the original linked list and store it in hash table
than again traverse it to adjust next and random pointer

struct Node {
    int data;
    Node *next;
    Node *arb;
    Node(int x) {
        data = x;
        next = NULL;
        arb = NULL;
    }
};

Node *copyList(Node *head) {
    Node *ori=head;
    Node *copy;
    map<Node *,Node *>mp;
    while(ori)
    {
        copy=new Node(ori->data);
        mp[ori]=copy;
        ori=ori->next;
    }
    ori=head;
    while(ori)
    {
        copy=mp[ori];
        copy->next=mp[ori->next];
        copy->arb=mp[ori->arb];
        ori=ori->next;
    }
    return mp[head];
}
---------------------------------------------------------------------------------------------------
clone tree
  map<Node*,Node*>mp;
   Node* inorderr(Node *ori)
 {
     if(ori==NULL)
     return NULL;

     Node* copy= newNode(ori->data);
     mp[ori]=copy;
     copy->left=inorderr(ori->left);
     copy->right=inorderr(ori->right);
     return copy;

 }
  void inorderrr(Node *ori,Node *copy)
 {
     if(copy==NULL)
     return;
     copy->random=mp[ori->random];
     inorderrr(ori->left,copy->left);
     inorderrr(ori->right,copy->right);
 }

Node* cloneTree(Node* tree)
{
 if(tree==NULL)
 return NULL;
 Node *copy=inorderr(tree);



 inorderrr(tree,copy);
 return copy;
}
