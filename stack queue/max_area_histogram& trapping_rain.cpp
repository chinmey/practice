
trapping rain water or max area stack

key===== if l==r is allowed than this solution is not valid ,so just check if (n<2) required ans is zero or A[0],for this is work answer should be A[0];

Given n non-negative integers a1, a2, ..., an , where each represents a point at coordinate (i, ai).
 n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0).
 Find two lines, which together with x-axis forms a container, such that the container contains the most water.
Input: [1,8,6,2,5,4,8,3,7]
Output: 49



The intuition behind this approach is that the area formed between the lines will always be limited by the height of the shorter line.
 Further, the farther the lines, the more will be the area obtained.

We take two pointers, one at the beginning and one at the end of the array constituting the length of the lines. 
Futher, we maintain a variable \text{maxarea}maxarea to store the maximum area obtained till now.
 At every step, we find out the area formed between them, update \text{maxarea}maxarea and 
 move the pointer pointing to the shorter line towards the other end by one step.

    public int maxArea(int[] height) {
        int maxarea = 0, l = 0, r = height.length - 1;
        while (l < r) {
            maxarea = Math.max(maxarea, Math.min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea;
    }
}
------------------------------------------------------------------------------------------------------------

Given an array of integers A of size N. A represents a histogram i.e A[i] denotes height of
the ith histogram’s bar. Width of each bar is 1

input =[1,1,3]  ans ==3

For every bar ‘x’, we calculate the area with ‘x’ as the smallest bar in the rectangle. If we calculate such area for every bar ‘x’ and 
find the maximum of all areas, our task is done. How to calculate area with ‘x’ as smallest bar? We need to know index of the first smaller (smaller than ‘x’) bar
 on left of ‘x’ and index of first smaller bar on right of ‘x’. Let us call these indexes as ‘left index’ and ‘right index’ respectively.
We traverse all bars from left to right, maintain a stack of bars. Every bar is pushed to stack once.
 A bar is popped from stack when a bar of smaller height is seen. When a bar is popped, we calculate the area with the popped bar as smallest bar.
  How do we get left and right indexes of the popped bar – the current index tells us the ‘right index’ and index of previous item in stack is the ‘left index’. 
  Following is the complete algorithm.

1) Create an empty stack.

2) Start from first bar, and do following for every bar ‘hist[i]’ where ‘i’ varies from 0 to n-1.
……a) If stack is empty or hist[i] is higher than the bar at top of stack, then push ‘i’ to stack.
……b) If this bar is smaller than the top of stack, then keep removing the top of stack while top of the stack is greater. 
Let the removed bar be hist[tp]. Calculate area of rectangle with hist[tp] as smallest bar. For hist[tp], the ‘left index’ is previous (previous to tp) 
item in stack and ‘right index’ is ‘i’ (current index).

3) If the stack is not empty, then one by one remove all bars from stack and do step 2.b for every removed bar.



// The main function to find the maximum rectangular 

intituition== each time we pop an element we consider area with it as minimum value
for this we would need max index to right which is smaller in height(given by i) and max index to left which is smaaller(given by index just below it in stack)
and this number 

int Solution::largestRectangleArea(vector<int> &A) {
     int n=A.size();
     int i=0;
     
     int ans=0;
     stack<int>s;
     while(i<n)
     {
         if(s.empty()==true || A[s.top()]<A[i])
         s.push(i++);
         
         else
         {
             int top=A[s.top()];
             s.pop();
             
             if(s.empty()==true)
             ans=max(ans,top*i);
             else
             ans=max(ans,top*(i-1-s.top()));
             
         }
     }
     while(s.empty()==false)
     {
          int top=A[s.top()];
             s.pop();
             
             if(s.empty()==true)
             ans=max(ans,top*i);
             else
             ans=max(ans,top*(i-1-s.top()));
     }
     return ans;
     
}


