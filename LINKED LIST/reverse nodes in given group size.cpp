/* 1
8
1 2 2 4 5 6 7 8
4

Output:
4 2 2 1 8 7 6 5
*/

struct node *reverse (struct node *head, int k)
{
    node *cur=head,*link=NULL,*prev=NULL;
    int count=0;
    while(cur!=NULL && count<k)
    {
      link=cur->next;
          cur->next=prev;
          prev=cur;
          cur=link;
          count++;
    }


    if(link!=NULL)
    {
        head->next=reverse(link,k);
    }
  return prev; /* prev was head of first reversal*/

}
basically reverse first group than use recursion to recall same process.
