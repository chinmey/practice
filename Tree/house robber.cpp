The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the “root.” Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that “all houses in this place forms a binary tree”. It will automatically contact the police if two directly-linked houses were broken into on the same night.

Determine the maximum amount of money the thief can rob tonight without alerting the police.

   3
    / \
   2   3
    \   \ 
     3   1
     out--7
     
     
     
In step I, we defined our problem as rob(root), which will yield the maximum amount of money that can be robbed of the binary tree rooted at “root”. This leads to the DP problem summarized in step II.

Now let’s take one step back and ask why do we have overlapping subproblems? If you trace all the way back to the beginning, you’ll find the answer lies in the way how we have defined rob(root). As I mentioned, for each tree root, there are two scenarios: it is robbed or is not. rob(root) does not distinguish between these two cases, so “information is lost as the recursion goes deeper and deeper”, which resulted in repeated subproblems.

If we were able to maintain the information about the two scenarios for each tree root, let’s see how it plays out. Redefine rob(root) as a new function which will return an array of two elements, the first element of which denotes the maximum amount of money that can be robbed if “root” is not robbed, while the second element signifies the maximum amount of money robbed if root is robbed.

Let’s relate rob(root) to rob(root.left) and rob(root.right), etc. For the 1st element of rob(root), we only need to sum up the larger elements of rob(root.left) and rob(root.right), respectively, since root is not robbed and we are free to rob the left and right subtrees. For the 2nd element of rob(root), however, we only need to add up the 1st elements of rob(root.left) and rob(root.right), respectively, plus the value robbed from “root” itself, since in this case it’s guaranteed that we cannot rob the nodes of root.left and root.right.

As you can see, by keeping track of the information of both scenarios, we decoupled the subproblems and the solution essentially boiled down to a greedy one. Here is the program:

public int rob(TreeNode root) {
	int[] res = robSub(root);
    return Math.max(res[0], res[1]);
}

private int[] robSub(TreeNode root) {
    if (root == null) {
    	return new int[2];
    }
    
    int[] left = robSub(root.left);
    int[] right = robSub(root.right);
    
    int[] res = new int[2];
    res[0] = Math.max(left[0], left[1]) + Math.max(right[0], right[1]);
    res[1] = root.val + left[0] + right[0];
    
    return res;
}

