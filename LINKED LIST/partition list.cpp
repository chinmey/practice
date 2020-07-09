Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5

We can take two pointers before and after to keep track of the two linked lists as described above. 
These two pointers could be used two create two separate lists and then these lists could be combined to form the desired reformed list.


1.Initialize two pointers before and after. In the implementation we have initialized these two with a dummy ListNode. 
This helps to reduce the number of conditional checks we would need otherwise. 
You can try an implementation where you don't initialize with a dummy node and see it yourself!

2.Iterate the original linked list, using the head pointer.

3.If the node's value pointed by head is lesser than x, the node should be part of the before list. So we move it to before list.(1)

4.Else, the node should be part of after list. So we move it to after list.((4))

5.Once we are done with all the nodes in the original linked list, we would have two list before and after.
 The original list nodes are either part of before list or after list, depending on its value.
 
 class Solution {
    public ListNode partition(ListNode head, int x) {

        // before and after are the two pointers used to create the two list
        // before_head and after_head are used to save the heads of the two lists.
        // All of these are initialized with the dummy nodes created.
        ListNode before_head = new ListNode(0);
        ListNode before = before_head;
        ListNode after_head = new ListNode(0);
        ListNode after = after_head;

        while (head != null) {

            // If the original list node is lesser than the given x,
            // assign it to the before list.
            if (head.val < x) {
                before.next = head;
                before = before.next;
            } else {
                // If the original list node is greater or equal to the given x,
                // assign it to the after list.
                after.next = head;
                after = after.next;
            }

            // move ahead in the original list
            head = head.next;
        }

        // Last node of "after" list would also be ending node of the reformed list
        after.next = null;

        // Once all the nodes are correctly assigned to the two lists,
        // combine them to form a single list which would be returned.
        before.next = after_head.next;

        return before_head.next;
    }
}
