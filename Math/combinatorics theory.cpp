Combinatorics is the branch of Mathematics dealing with the study of finite or countable discrete structures. 
It includes the enumeration or counting of objects having certain properties. Counting helps us solve several types of problems
 such as counting the number of available IPv4 or IPv6 addresses.

Counting Principles –

There are two basic counting principles, sum rule and product rule.




Sum Rule – If a task can be done in one of n_1 ways or one of n_2 ways, where none of the set of n_1 ways is the same as any of the set of n_2 ways, 
then there are n_1 + n_2 ways to do the task.

Product Rule – If a task can be broken down into a sequence of k subtasks, where each subtask can be performed in n_1, n_2,.. n_k respectively,
 then the total number of ways the task can be performed is n_1 * n_2 * ... * n_k.

Example 1 – In how many ways can 3 winning prizes be given to the top 3 players in a game played by 12 players?
Solution – We have to distribute 3 prizes among 12 players. This task can be divided into 3 subtasks of assigning a single prize to a certain player.
Giving out the first prize can be done in 12 different ways. After giving out the first prize, two prizes remain and 11 players remain.
 Similarly, the second prize and third prize can be given in 11 ways and 10 ways. The total number of ways by the product rule is 12 * 11 * 10 = 1320.
 
 
 
 
Example 2 – In how many ways can a person choose a project from three lists of projects of sizes 10, 15, and 19 respectively?
Solution – The person has a choice of choosing a project from either of the three lists. 
So the person can choose from either 10 projects or 15 projects or 19 projects. Since choosing from one list is not the same as choosing another list, 
the total number of ways of choosing a project by the sum-rule is 10 + 15 + 19 = 44.



Example 4 – How many variable names of length upto 3 exist if the variable names are alphanumeric and case sensitive with the 
restriction that the first character has to be an alphabet?
Solution – Let N_1, N_2, and N_3 denote the number of possible variable names of length 1, 2, and 3.
 Therefore, total number of variable names is N_1 + N_2 + N_3.
For N_1 there are only 52 possibilities since the first character has to be an alphabet.
For N_2, there are 52 * 62 = 3224 possibilities
For N_3, there are 52 * 62 * 62 = 199888 possibilities
Therefore, total number of variable names = 52 + 3224 + 199888 = 203164




Principle of Inclusion-Exclusion :

The sum-rule mentioned above states that if there are multiple sets of ways of doing a task, 
there shouldn’t be any way that is common between two sets of ways because if there is, it would be counted twice and the enumeration would be wrong.
The principle of inclusion-exclusion says that in order to count only unique ways of doing a task, we must add the number of ways to do it in one way 
and the number of ways to do it in another and then subtract the number of ways to do the task that are common to both sets of ways.
The principle of inclusion-exclusion is also known as the subtraction principle. For two sets of ways A_1 and A_2, the enumeration would like-

|A_1 \cup A_2| = |A_1| + |A_2| - |A_1\cap A_2|
Example 1 – How many binary strings of length 8 either start with a ‘1’ bit or end with two bits ’00’?
Solution – If the string starts with one, there are 7 characters left which can be filled in 2^7 = 128 ways.
If the string ends with ’00’ then 6 characters can be filled in 2^6 = 64 ways.
Now if we add the above sets of ways and conclude that it is the final answer, then it would be wrong. This is because there are strings with start with ‘1’ and end with ’00’ both, and since they satisfy both criteria they are counted twice.
So we need to subtract such strings to get a correct count.
Strings that start with ‘1’ and end with ’00’ have five characters that can be filled in 2^5 = 32 ways.
So by the inclusion-exclusion principle we get-
Total strings = 128 + 64 – 32 = 160
Example 2 – How many numbers between 1 and 1000, including both, are divisible by 3 or 4?
Solution – Number of numbers divisible by 3 = |A_1| =\lfloor 1000/3\rfloor = 333.
Number of numbers divisible by 4 = |A_2| = \lfloor 1000/4\rfloor = 250.
Number of numbers divisible by 3 and 4 = |A_1 \cap A_2| = \lfloor 1000/12\rfloor = 83.
Therefore, number of numbers divisible by 3 or 4 = |A_1 \cup A_2| = 333 + 250 – 83 = 500



Why is Quick Sort preferred for arrays?

Below are recursive and iterative implementations of Quick Sort and Merge Sort for arrays.
Recursive Quick Sort for array.
Iterative Quick Sort for arrays.
Recursive Merge Sort for arrays
Iterative Merge Sort for arrays




Quick Sort in its general form is an in-place sort (i.e. it doesn’t require any extra storage) whereas merge sort requires O(N) extra storage,
 N denoting the array size which may be quite expensive. Allocating and de-allocating the extra space used 
 for merge sort increases the running time of the algorithm.
Comparing average complexity we find that both type of sorts have O(NlogN) average complexity but the constants differ. 
For arrays, merge sort loses due to the use of extra O(N) storage space.
Most practical implementations of Quick Sort use randomized version. The randomized version has expected time complexity of O(nLogn).
 The worst case is possible in randomized version also, but worst case doesn’t occur for a particular pattern (like sorted array) and randomized Quick Sort works well in practice.
Quick Sort is also a cache friendly sorting algorithm as it has good locality of reference when used for arrays.
Quick Sort is also tail recursive, therefore tail call optimizations is done.
Why is Merge Sort preferred for Linked Lists?

Below are implementations of Quicksort and Mergesort for singly and doubly linked lists.

Quick Sort for Doubly Linked List
Quick Sort for Singly Linked List
Merge Sort for Singly Linked List
Merge Sort for Doubly Linked List

In case of linked lists the case is different mainly due to difference in memory allocation of arrays and linked lists. Unlike arrays, linked list nodes may not be adjacent in memory.
Unlike array, in linked list, we can insert items in the middle in O(1) extra space and O(1) time. Therefore merge operation of merge sort can be implemented without extra space for linked lists.
In arrays, we can do random access as elements are continuous in memory. Let us say we have an integer (4-byte) array A and let the address of A[0] be x then to access A[i], we can directly access the memory at (x + i*4). Unlike arrays, we can not do random access in linked list.
Quick Sort requires a lot of this kind of access. In linked list to access i’th index, we have to travel each and every node from the head to i’th node as we don’t have continuous block of memory. Therefore, the overhead increases for quick sort. Merge sort accesses data sequentially and the need of random access is low.
