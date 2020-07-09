Given a linked list and a value x, partition it such that all nodes less than x come first, then all nodes with value equal to x and
 finally nodes with value greater than or equal to x. The original relative order of the nodes in each of the three partitions should be preserved. 
The partition must work in-place

Input : 1->4->3->2->5->2->3, 
        x = 3
Output: 1->2->2->3->3->4->5

Input : 1->4->10->2 
        x = 5
Output: 1->4->2->10

Input : 10->4->20->10->3 
        x = 3
Output: 3->10->4->20->10

Below is the algorithm to solve this problem :

Initialize first and last nodes of below three linked lists as NULL.
Linked list of values smaller than x.
Linked list of values equal to x.
Linked list of values greater than x.
Now iterate through the original linked list. If a node’s value is less than x then append it at the end of smaller list. 
If the value is equal to x, then at the end of equal list. And if value is greater, then at the end of greater list.
Now concatenate three lists

struct Node *partition(struct Node *head, int x) 
{ 
    /* Let us initialize first and last nodes of 
      three linked lists 
        1) Linked list of values smaller than x. 
        2) Linked list of values equal to x. 
        3) Linked list of values greater than x.*/
    struct Node *smallerHead = NULL, *smallerLast = NULL; 
    struct Node *greaterLast = NULL, *greaterHead = NULL; 
    struct Node *equalHead = NULL, *equalLast = NULL; 
  
    // Now iterate original list and connect nodes 
    // of appropriate linked lists. 
    while (head != NULL) 
    { 
        // If current node is equal to x, append it 
        // to the list of x values 
        if (head->data == x) 
        { 
            if (equalHead == NULL) 
                equalHead = equalLast = head; 
            else
            { 
                equalLast->next = head; 
                equalLast = equalLast->next; 
            } 
        } 
  
        // If current node is less than X, append 
        // it to the list of smaller values 
        else if (head->data < x) 
        { 
            if (smallerHead == NULL) 
                smallerLast = smallerHead = head; 
            else
            { 
                smallerLast->next = head; 
                smallerLast = head; 
            } 
        } 
        else // Append to the list of greater values 
        { 
            if (greaterHead == NULL) 
                greaterLast = greaterHead = head; 
            else
            { 
                greaterLast->next  = head; 
                greaterLast = head; 
            } 
        } 
  
        head = head->next; 
    } 
  
    // Fix end of greater linked list to NULL if this 
    // list has some nodes 
    if (greaterLast != NULL) 
        greaterLast->next = NULL; 
  
    // Connect three lists 
  
    // If smaller list is empty 
    if (smallerHead == NULL) 
    { 
        if (equalHead == NULL) 
            return greaterHead; 
        equalLast->next = greaterHead; 
        return equalHead; 
    } 
  
    // If smaller list is not empty 
    // and equal list is empty 
    if (equalHead == NULL) 
    { 
        smallerLast->next = greaterHead; 
        return smallerHead; 
    } 
  
    // If both smaller and equal list 
    // are non-empty 
    smallerLast->next = equalHead; 
    equalLast->next = greaterHead; 
    return  smallerHead; 
} 


-------------------------------------------------------------------------------------------------------------------------------------------------

Sort a linked list using insertion sort

Input : 1 -> 3 -> 2

Return 1 -> 2 -> 3

1) Create an empty sorted (or result) list
2) Traverse the given list, do following for every node.
......a) Insert current node in sorted way in sorted or result list.
3) Change head of given linked list to head of sorted (or result) list.

/* sorted insertion process*/

example   2 5 7 10 15
after insertion of 9=>  2 5 7 9 10 15
1) If Linked list is empty then make the node as
   head and return it.
2) If the value of the node to be inserted is smaller 
   than the value of the head node, then insert the node 
at the start and make it head.
3) In a loop, find the appropriate node after 
   which the input node (let 9) is to be inserted. 
   To find the appropriate node start from the head, 
   keep moving until you reach a node GN (10 in
   the below diagram) who's value is greater than 
   the input node. The node just before GN is the
appropriate node (7).
4) Insert the node (9) after the appropriate node
   (7) found in step 3.
   
   void insertionSort(struct Node **head_ref) 
{ 
    // Initialize sorted linked list 
    struct Node *sorted = NULL; 
  
    // Traverse the given linked list and insert every 
    // node to sorted 
    struct Node *current = *head_ref; 
    while (current != NULL) 
    { 
        // Store next for next iteration 
        struct Node *next = current->next; 
  
        // insert current in sorted linked list 
        sortedInsert(&sorted, current); 
  
        // Update current 
        current = next; 
    } 
  
    // Update head_ref to point to sorted linked list 
    *head_ref = sorted; 
} 
  
/* function to insert a new_node in a list. Note that this 
  function expects a pointer to head_ref as this can modify the 
  head of the input linked list (similar to push())*/
void sortedInsert(struct Node** head_ref, struct Node* new_node) 
{ 
    struct Node* current; 
    /* Special case for the head end */
    if (*head_ref == NULL || (*head_ref)->data >= new_node->data) 
    { 
        new_node->next = *head_ref; 
        *head_ref = new_node; 
    } 
    else
    { 
        /* Locate the node before the point of insertion */
        current = *head_ref; 
        while (current->next!=NULL && 
               current->next->data < new_node->data) 
        { 
            current = current->next; 
        } 
        new_node->next = current->next; 
        current->next = new_node; 
    } 
} 
  
/* BELOW FUNCTIONS ARE JUST UTILITY TO TEST sortedInsert */
  
/* Function to print linked list */
void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    while(temp != NULL) 
    { 
        printf("%d  ", temp->data); 
        temp = temp->next; 
    } 
} 
