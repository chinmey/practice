Given a singly linked list of size N, and an integer K, you need to swap the Kth node from beginning and Kth node from end in linked list.
Note: You need to swap the nodes and not change the content of the nodes.

Node *swapkthnode(Node* head, int num, int K)
{
    int n=num;
    int k=K;
    if(n<k)
    return head;
    Node *x=head;
    Node *x_p=NULL;
    Node *y=head;
    Node *y_p=NULL;
    int i;
    for(i=1;i<K;i++)
    {
        x_p=x;
        x=x->next;
    }
    for(i=1;i<n-k+1;i++)
    {
        y_p=y;
        y=y->next;
    }
    if(x_p)
    x_p->next=y;
    if(y_p)
    y_p->next=x;
    Node *t=x->next;
    x->next=y->next;
    y->next=t;
    if(k==1)
    head=y;
    if(k==n)
    head=x;


return head;
}


----------------------------------------------------------------------------------------------------------------------------------------------

We are given a linked list and positions m and n. We need to reverse the linked list from position m to n.

Input : 10->20->30->40->50->60->70->NULL
        m = 3, n = 6
Output : 10->20->60->50->40->30->70->NULL

To reverse the linked list from position m to n, we find addresses of start and end position of the linked list by running a loop,
 and then we unlink this part from the rest of the list and then use the normal linked list reverse function which we have
  earlier used for reversing the complete linked list, and use it to reverse the portion of the linked list which need to be reversed.
 After reversal, we again attach the portion reversed to the main list.
 
 
 // the standard reverse function used 
// to reverse a linked list 
struct Node* reverse(struct Node* head) 
{ 
    struct Node* prev = NULL;     
    struct Node* curr = head; 
  
    while (curr) { 
        struct Node* next = curr->next; 
        curr->next = prev; 
        prev = curr; 
        curr = next; 
    } 
    return prev; 
} 
  
// function used to reverse a linked list 
// from position m to n which uses reverse 
// function 
Node* reverseBetween(Node* head, int m, int n) 
{ 
    if (m == n) 
        return head; 
  
    // revs and revend is start and end respectively 
    // of the portion of the linked list which 
    // need to be reversed. revs_prev is previous 
    // of starting position and revend_next is next 
    // of end of list to be reversed. 
    Node* revs = NULL, *revs_prev = NULL; 
    Node* revend = NULL, *revend_next = NULL; 
  
    // Find values of above pointers. 
    int i = 1; 
    Node* curr = head; 
    while (curr && i <= n) { 
        if (i < m) 
            revs_prev = curr; 
  
        if (i == m) 
            revs = curr; 
  
        if (i == n) { 
            revend = curr; 
            revend_next = curr->next; 
        } 
  
        curr = curr->next; 
        i++; 
    } 
    revend->next = NULL; 
  
    // Reverse linked list starting with 
    // revs. 
    revend = reverse(revs); 
  
    // If starting position was not head 
    if (revs_prev) 
        revs_prev->next = revend; 
  
    // If starting position was head 
    else
        head = revend; 
  
    revs->next = revend_next; 
    return head; 
} 
