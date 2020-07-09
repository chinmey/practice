Given a binary tree with N nodes, in which each node value represents number of candies present at that node, and there are N candies in total. In one move, one may choose two adjacent nodes and move one candy from one node to another (the move may be from parent to child, or from child to parent.)

The task is to find the number of moves required such that every node have exactly one candy

Input :      3
           /   \
          0     0 
Output : 2
Explanation: From the root of the tree, we move one 
candy to its left child, and one candy to
its right child.

The idea is to traverse the tree from leaf to root i.e postorder and consecutively balance all of the nodes. 
To balance a node, the number of candy at that node must be 1.

There can be two cases:

If a node needs candies, if the node of the tree has 0 candies (an excess of -1 from what it needs), then we should push a 
candy from its parent onto the node.
If the node has more than 1 candy. If it has say, 4 candies (an excess of 3), then we should push 3 candies off the node to its parent.

int distributeCandyUtil(Node* root, int& ans) 
{ 
    // Base Case 
    if (root == NULL) 
        return 0; 
  
    // Traverse left subtree 
    int l = distributeCandyUtil(root->left, ans); 
  
    // Traverse right subtree 
    int r = distributeCandyUtil(root->right, ans); 
  
    // Update number of moves 
    ans += abs(l) + abs(r); 
  
    // Return number of moves to balance 
    // current node 
    return root->key + l + r - 1; 
} 
  
// Function to find the number of moves to 
// distribute all of the candies 
int distributeCandy(Node* root) 
{ 
    int ans = 0; 
  
    distributeCandyUtil(root, ans); 
  
    return ans; 
} 
