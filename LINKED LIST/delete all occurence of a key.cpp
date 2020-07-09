
---------------------------------------------------------------
Node* deleteAllOccurances(Node *head,int x)
{
    Node* p=head;
    Node* q=NULL;
    int deletion_occur=0;
    while(p!=NULL && p->data==x) /* this steps delete all occurence of key if they occur at start*/
    {
        head=p->next;
        free(p);
        p=head;
    }
    while(p!=NULL)
    {
        deletion_occur=0;
        
        if(p->data==x)
        {
          q->next=p->next;
          free(p);
          p=q->next;
          deletion_occur=1; 
        }
        if(deletion_occur==0) /* if deletion does not occur increment*/
        {
            q=p;
            p=p->next;
        }
    }
    return head;
}
----------------------------------------------------------------
delete without head referance
void deleteNode(Node *node)
{
  *(node)=*(node->next);
} 

-------------------------------------------------------------------------

Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

ListNode* Solution::deleteDuplicates(ListNode* A) {
    
    if(A==NULL || A->next==NULL) return A;
    ListNode *p,*q,*s,*z;
    
    p=A;
    if(p->val ==p->next->val){ /* if takes care of case when we need to move head */
    
    while(1){
      p=A;
   s=A;
    
  
   while(s!=NULL && p->val==s->val)
   /* last of duplicates*/
   {
       q=s;
         s=s->next;
         
   }
 
   /*cout<<s->val;*/
   p->next=q->next; /* deleting all except one*/
   free(q);
  /* s=p->next;*/
  
  if(p->next==NULL) return NULL;
   
   A=p->next;
   free(p);
   p=A;
   if(p)
   q=p->next;
   
   if( q==NULL ||p->val !=q->val)
   break;
   
   
    } }
    
    ListNode *prev;
      z=p->next;
        
        
        while(z)
        {
            if(p->val ==z->val){
                
                s=p;
                
                while(s!=NULL && s->val==p->val)
                {
                    q=s;
                    s=s->next;
                }
                
                if(s==NULL)
                {
                    prev->next=NULL;
                    return A;
                }
               /* ListNode *t=NULL;
                if(q->next!=NULL)
                t=q->next;*/
                p->next=q->next;
                free(q);
               /* if(  t!=NULL && t->next!=NULL)
                q=t->next;*/
                
               /* if(t)
                p=t;*/
                prev->next=s;
                free(p);
                p=s;
                if(s)
                z=s->next;
                
                
            }
            else{
			           prev=p;
                p=z;
                z=z->next;
                
            }
        }
    
    
   return A;
