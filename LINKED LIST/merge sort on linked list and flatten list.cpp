Sort a linked list in O(n log n) time using constant space complexity

Input: 4->2->1->3
Output: 1->2->3->4

Let head be the first node of the linked list to be sorted and headRef be the pointer to head.
 Note that we need a reference to head in MergeSort() as the below implementation changes next links to sort the linked lists
  (not data at the nodes), so head node has to be changed if the data at the original head is not the smallest value in the linked list.

MergeSort(headRef)
1) If the head is NULL or there is only one element in the Linked List 
    then return.
2) Else divide the linked list into two halves.  
      FrontBackSplit(head, &a, &b); /* a and b are two halves */
3) Sort the two halves a and b.
      MergeSort(a);
      MergeSort(b);
4) Merge the sorted a and b (using SortedMerge() discussed here) 
   and update the head pointer using headRef.
     *headRef = SortedMerge(a, b);

#include <bits/stdc++.h> 
using namespace std; 
  
/* Link list node */
class Node { 
public: 
    int data; 
    Node* next; 
}; 
  
/* function prototypes */
Node* SortedMerge(Node* a, Node* b); 
void FrontBackSplit(Node* source, 
                    Node** frontRef, Node** backRef); 
  
/* sorts the linked list by changing next pointers (not data) */
void MergeSort(Node** headRef) 
{ 
    Node* head = *headRef; 
    Node* a; 
    Node* b; 
  
    /* Base case -- length 0 or 1 */
    if ((head == NULL) || (head->next == NULL)) { 
        return; 
    } 
  
    /* Split head into 'a' and 'b' sublists */
    FrontBackSplit(head, &a, &b); 
  
    /* Recursively sort the sublists */
    MergeSort(&a); 
    MergeSort(&b); 
  
    /* answer = merge the two sorted lists together */
    *headRef = SortedMerge(a, b); 
} 
  
/* See https:// www.geeksforgeeks.org/?p=3622 for details of this  
function */
Node* SortedMerge(Node* a, Node* b) 
{ 
    Node* result = NULL; 
  
    /* Base cases */
    if (a == NULL) 
        return (b); 
    else if (b == NULL) 
        return (a); 
  
    /* Pick either a or b, and recur */
    if (a->data <= b->data) { 
        result = a; 
        result->next = SortedMerge(a->next, b); 
    } 
    else { 
        result = b; 
        result->next = SortedMerge(a, b->next); 
    } 
    return (result); 
} 
  
/* UTILITY FUNCTIONS */
/* Split the nodes of the given list into front and back halves,  
    and return the two lists using the reference parameters.  
    If the length is odd, the extra node should go in the front list.  
    Uses the fast/slow pointer strategy. */
void FrontBackSplit(Node* source, 
                    Node** frontRef, Node** backRef) 
{ 
    Node* fast; 
    Node* slow; 
    slow = source; 
    fast = source->next; 
  
    /* Advance 'fast' two nodes, and advance 'slow' one node */
    while (fast != NULL) { 
        fast = fast->next; 
        if (fast != NULL) { 
            slow = slow->next; 
            fast = fast->next; 
        } 
    } 
  
    /* 'slow' is before the midpoint in the list, so split it in two  
    at that point. */
    *frontRef = source; 
    *backRef = slow->next; 
    slow->next = NULL; 
} 
  
/* Function to print nodes in a given linked list */
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data << " "; 
        node = node->next; 
    } 
} 
  
/* Function to insert a node at the beginging of the linked list */
void push(Node** head_ref, int new_data) 
{ 
    /* allocate node */
    Node* new_node = new Node(); 
  
    /* put in the data */
    new_node->data = new_data; 
  
    /* link the old list off the new node */
    new_node->next = (*head_ref); 
  
    /* move the head to point to the new node */
    (*head_ref) = new_node; 
} 
  
/* Drier program to test above functions*/
int main() 
{ 
    /* Start with the empty list */
    Node* res = NULL; 
    Node* a = NULL; 
  
    /* Let us create a unsorted linked lists to test the functions  
Created lists shall be a: 2->3->20->5->10->15 */
    push(&a, 15); 
    push(&a, 10); 
    push(&a, 5); 
    push(&a, 20); 
    push(&a, 3); 
    push(&a, 2); 
  
    /* Sort the above created Linked List */
    MergeSort(&a); 
  
    cout << "Sorted Linked List is: \n"; 
    printList(a); 
  
    return 0; 
} 
  
  ----------------------------------------------------------------------------------------------------------------
  
  Given a Linked List of size N, where every node represents a linked list and contains two pointers of its type:
(i) a next pointer to the next node,
(ii) a bottom pointer to a linked list where this node is head.

You have to flatten the linked list to a single linked list which is sorted.

    5 -> 10 -> 19 -> 28
       |    |     |     |
       V    V     V     V
       7    20    22    35
       |          |     |
       V          V     V
       8          50    40
       |                |
       V                V
       30               45
       
       
Node* merge( Node* a, Node* b ) 
{ 
    // If first list is empty, the second list is result 
    if (a == NULL) 
        return b; 
  
    // If second list is empty, the second list is result 
    if (b == NULL) 
        return a; 
  
    // Compare the data members of head nodes of both lists 
    // and put the smaller one in result 
    Node* result; 
    if (a->data < b->data) 
    { 
        result = a; 
        result->down = merge( a->down, b ); 
    } 
    else
    { 
        result = b; 
        result->down = merge( a, b->down ); 
    } 
  
    return result; 
} 
  
// The main function that flattens a given linked list 
Node* flatten (Node* root) 
{ 
    // Base cases 
    if (root == NULL || root->right == NULL) 
        return root; 
  
    // Merge this list with the list on right side 
    return merge( root, flatten(root->right) ); 
} 
