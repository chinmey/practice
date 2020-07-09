int intersectPoint(Node* head1, Node* head2)
{
    Node *p=head1,*q=head2;
    while(p!=NULL)
    {
     p->data=-1*p->data;
     p=p->next;
    }
    while(q!=NULL)
    {
        if(q->data<0)
        break;
        q=q->next;
    }
    return -1*q->data;
}
 /*to delete a node n without head pointer
 void delete(node *n) n is node to be deleted
 {
     *(n)=*(n->next);
 }
 /*implement stack and queue using list
