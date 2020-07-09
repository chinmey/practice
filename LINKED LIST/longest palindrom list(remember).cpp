// function for counting the common elements
int countCommon(Node *a, Node *b)
{
    int count = 0;

    // loop to count coomon in the list starting
    // from node a and b
    for (; a && b; a = a->next, b = b->next)

        // increment the count for same values
        if (a->data == b->data)
            ++count;
        else
            break;

    return count;
}

// Returns length of the longest palindrome
// sublist in given list
int maxPalindrome(Node *head)
{
    int result = 0;
    Node *prev = NULL, *curr = head;

    // loop till the end of the linked list
    while (curr)
    {
        // The sublist from head to current
        // reversed.
        Node *next = curr->next;
        curr->next = prev;

        // check for odd length palindrome
        // by finding longest common list elements
        // beginning from prev and from next (We
        // exclude curr)
        result = max(result,
                     2*countCommon(prev, next)+1);

        // check for even length palindrome
        // by finding longest common list elements
        // beginning from curr and from next
        result = max(result,
                     2*countCommon(curr, next));

        // update prev and curr for next iteration
        prev = curr;
        curr = next;
    }
    return result;
}

Note that the above code modifies the given linked list and may not work if modifications to linked list are not allowed. However we can finally do one more reverse to get original list back.
