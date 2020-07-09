  
  Given a Binary Tree find the length of the longest path which comprises of nodes with consecutive values in increasing order. 
  Every node is considered as a path of length 1.
  
                      1
                     /  \
					
					2     4
					/
				3	 
				ans=3 (1,2,3);
				
	void longestConsecutiveUtil(Node* root, int curLength, 
                              int expected, int& res) 
{ 
    if (root == NULL) 
        return; 
  
    // if root data has one more than its parent 
    // then increase current length 
    if (root->data == expected) 
        curLength++; 
    else
        curLength = 1; 
  
    //  update the maximum by current length 
    res = max(res, curLength); 
  
    // recursively call left and right subtree with 
    // expected value 1 more than root data 
    longestConsecutiveUtil(root->left, curLength, 
                           root->data + 1, res); 
    longestConsecutiveUtil(root->right, curLength, 
                           root->data + 1, res); 
} 
  
// method returns length of longest consecutive 
// sequence rooted at node root 
int longestConsecutive(Node* root) 
{ 
    if (root == NULL) 
        return 0; 
  
    int res = 0; 
  
    //  call utility method with current length 0 
    longestConsecutiveUtil(root, 0, root->data, res); 
  
    return res; 
} 
***************************************************************************************************************************




*******************************************************************************************************************************

Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.

A node is deepest if it has the largest depth possible among any node in the entire tree.

The subtree of a node is that node, plus the set of all descendants of that node.

Return the node with the largest depth such that it contains all the deepest nodes in its subtree.

Input: [3,5,1,6,2,0,8,null,null,7,4]
Output: [2,7,4]

The Result (on some subtree) returned by our (depth-first search) recursion will have two parts:
Result.node: the largest depth node that is equal to or an ancestor of all the deepest nodes of this subtree.
Result.dist: the number of nodes in the path from the root of this subtree, to the deepest node in this subtree.
We can calculate these answers disjointly for dfs(node):
To calculate the Result.node of our answer:
If one childResult has deeper nodes, then childResult.node will be the answer.
/* basically kya h ki child ka dekho agar uska pass deeper node h toh woh answer warna parent answer*/
class Solution {
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return dfs(root).second;
    }
    
private:
    pair<int, TreeNode*> dfs(TreeNode* curr)
    {
        if(!curr)return {0, nullptr};
        auto left = dfs(curr->left);
        auto right = dfs(curr->right);
        if(left.first > right.first)return {left.first + 1, left.second};
        else if(left.first < right.first)return {right.first + 1, right.second};
        else return {left.first + 1, curr};
    }
};
-------------------------------------------------------------------------------------------------------------

yeh wala samjhan h checkpoint tha

Given A, generate all structurally unique BST’s (binary search trees) that store values 1…A

Input 1:
    A = 3

Output 1:

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3
   
/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 
 vector<TreeNode*> construct(int s, int e)
 {
     vector<TreeNode*> send;
     
     if(s > e)
     {
         send.push_back(NULL);
         return send;
     }
     
     for(int i = s; i <= e; i++)
     {
         vector<TreeNode*> left = construct(s, i-1);
         vector<TreeNode*> right = construct(i+1, e);
         
         for(int j = 0; j < left.size(); j++)
         {
             TreeNode *l = left[j];
             for(int k = 0; k < right.size(); k++)
            {
                 TreeNode *r = right[k];
                 TreeNode *x = new TreeNode(i);
                 x->left = l;
                 x->right = r;
                 send.push_back(x);
             }
         }
     }
     return send;
 }
vector<TreeNode*> Solution::generateTrees(int A) {
    
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

     vector<TreeNode*> ans = construct(1,A);
     return ans;
    
}

