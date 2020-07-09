Given a singly linked list: A0→A1→…→An-1→An,
reorder it to: A0→An→A1→An-1→A2→An-2→…

Given 1->2->3->4->5 its reorder is 1->5->2->4->3.

the basic idea is to divide the list into 2 halfs here they are handled by head and even ,then we reverse 
the second half here even than we simply join first element of first list with first element of second list
and so on ....

int size(Node *node)
{
	int size = 0;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return size;
}
   void reverse(Node** head)
    {


        Node* current = *head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {

            next = current->next;


            current->next = prev;


            prev = current;
            current = next;
        }
        *head = prev;
    }
void reorderList(Node* head)
{
    if(head==NULL || head->next==NULL ||head->next->next ==NULL)
    return;
    Node *first=head;
    Node *l=head;
    Node *even;
    int n=size(head);
    n=n/2;
    int c=1;
    while(c<n)
    {
        first=first->next;
        c++;
    }
    even=first->next;
    first->next=NULL;

    reverse(&even);

    while(head && even)
    {
        Node *t=head->next;
        head->next=even;
        head=t;
        Node *p=even->next;
        even->next=head;
        even=p;
    }
    while(l->next!=NULL)
    l=l->next;
    if(even!=NULL)
    l->next=even;
}
-----------------------------------------------------------

delete node having greater value on right
reverse
delete karo
reverse
