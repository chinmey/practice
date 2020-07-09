
Input: List1: 5->6->3  // represents number 365
       List2: 8->4->2 //  represents number 248
Output: Resultant list: 3->1->6  // represents number 613

Input: List1: 7->5->9->4->6  // represents number 64957
       List2: 8->4 //  represents number 48
Output: Resultant list: 5->0->0->5->6  // represents number 65005


Node* addTwoLists (Node* first, Node* second)  
{  
    Node* res = NULL; // res is head node of the resultant list  
    Node *temp, *prev = NULL;  
    int carry = 0, sum;  
  
    while (first != NULL || second != NULL) //while both lists exist  
    {  
        // Calculate value of next digit in resultant list.  
        // The next digit is sum of following things  
        // (i) Carry  
        // (ii) Next digit of first list (if there is a next digit)  
        // (ii) Next digit of second list (if there is a next digit)  
        sum = carry + (first? first->data: 0) + 
                      (second? second->data: 0);  
  
        // update carry for next calulation  
        carry = (sum >= 10)? 1 : 0;  
  
        // update sum if it is greater than 10  
        sum = sum % 10;  
  
        // Create a new node with sum as data  
        temp = newNode(sum);  
  
        // if this is the first node then 
        // set it as head of the resultant list  
        if(res == NULL)  
            res = temp;  
              
        // If this is not the first  
        // node then connect it to the rest. 
        else  
            prev->next = temp;  
  
        // Set prev for next insertion  
        prev = temp;  
  
        // Move first and second pointers to next nodes  
        if (first) first = first->next;  
        if (second) second = second->next;  
    }  
  
    if (carry > 0)  
    temp->next = newNode(carry);  
  
    // return head of the resultant list  
    return res;  
}  


-------------------------------------------------------------------------------------------------------------------------------------------------------------
// A C++ recursive program to add two linked lists
#include <bits/stdc++.h>
using namespace std;

// A linked List Node
class Node
{
	public:
	int data;
	Node* next;
};

typedef Node node;

/* A utility function to insert
a node at the beginning of linked list */
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

/* A utility function to print linked list */
void printList(Node *node)
{
	while (node != NULL)
	{
		cout<<node->data<<" ";
		node = node->next;
	}
	cout<<endl;
}

// A utility function to swap two pointers
void swapPointer( Node** a, Node** b )
{
	node* t = *a;
	*a = *b;
	*b = t;
}

/* A utility function to get size of linked list */
int getSize(Node *node)
{
	int size = 0;
	while (node != NULL)
	{
		node = node->next;
		size++;
	}
	return size;
}

// Adds two linked lists of same size
// represented by head1 and head2 and returns
// head of the resultant linked list. Carry
// is propagated while returning from the recursion
node* addSameSize(Node* head1, Node* head2, int* carry)
{
	// Since the function assumes linked lists are of same size,
	// check any of the two head pointers
	if (head1 == NULL)
		return NULL;

	int sum;

	// Allocate memory for sum node of current two nodes
	Node* result = new Node();

	// Recursively add remaining nodes and get the carry
	result->next = addSameSize(head1->next, head2->next, carry);

	// add digits of current nodes and propagated carry
	sum = head1->data + head2->data + *carry;
	*carry = sum / 10;
	sum = sum % 10;

	// Assigne the sum to current node of resultant list
	result->data = sum;

	return result;
}




// The main function that adds two linked lists
// represented by head1 and head2. The sum of
// two lists is stored in a list referred by result
void addList(Node* head1, Node* head2, Node** result)
{
	Node *cur;

	// first list is empty
	if (head1 == NULL)
	{
		*result = head2;
		return;
	}

	// second list is empty
	else if (head2 == NULL)
	{
		*result = head1;
		return;
	}

	int size1 = getSize(head1);
	int size2 = getSize(head2) ;

	int carry = 0;

	// Add same size lists
	if (size1 == size2)
		*result = addSameSize(head1, head2, &carry);

	else
	{
		 int diff = abs(size1 - size2);

		// First list should always be larger than second list.
		// If not, swap pointers
		if (size1 < size2)
			swapPointer(&head1, &head2);
			while(diff--)
      push(&head2,0);





		*result = addSameSize(head1,head2,&carry);

		// get addition of remaining first list and carry

	}

	// if some carry is still there, add a new node to the fron of
	// the result list. e.g. 999 and 87
	if(carry)
      push(result,carry);
}

// Driver code
int main()
{
	Node *head1 = NULL, *head2 = NULL, *result = NULL;

	int arr1[] = {9, 9, 9};
	int arr2[] = {8,7};

	int size1 = sizeof(arr1) / sizeof(arr1[0]);
	int size2 = sizeof(arr2) / sizeof(arr2[0]);

	// Create first list as 9->9->9
	int i;
	for (i = size1-1; i >= 0; --i)
		push(&head1, arr1[i]);

	// Create second list as 1->8
	for (i = size2-1; i >= 0; --i)
		push(&head2, arr2[i]);

	addList(head1, head2, &result);

	printList(result);

	return 0;
}
-------------------------------------------------------------------------------------------------------------------------------------------------------



