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

----------------------------------------------------------------------------------------------------------------------------------------------------------------

search an element in rotated sorted array

Input  : arr[] = {5, 6, 7, 8, 9, 10, 1, 2, 3};
         key = 3
Output : Found at index 8

Input arr[] = {3, 4, 5, 1, 2}
Element to Search = 1
  1) Find out pivot point and divide the array in two
      sub-arrays. (pivot = 2) /*Index of 5*/
  2) Now call binary search for one of the two sub-arrays.
      (a) If element is greater than 0th element then
             search in left array
      (b) Else Search in right array
          (1 will go in else as 1 < 0th element(3))
  3) If element is found in selected sub-array then return index
     Else return -1.
     
     -------------------------------------------------------------------------------------------------------------------------------------------------------------
     
    first missing positive number
    
    Input: [1,2,0]
Output: 3

Input: [3,4,-1,1]
Output: 2

The idea is similar to this post. We use array elements as index. To mark presence of an element x, we change the value at the index x to negative. But this approach doesn’t work if there are non-positive (-ve and 0) numbers. So we segregate positive from negative numbers as first step and then apply the approach.

Following is the two step algorithm.
1) Segregate positive numbers from others i.e., move all non-positive numbers to left side. In the following code, segregate() function does this part.
2) Now we can ignore non-positive elements and consider only the part of array which contains all positive elements.
 We traverse the array containing all positive numbers and to mark presence of an element x, 
 we change the sign of value at index x to negative. We traverse the array again and print the first index which has positive value.
 In the following code, findMissingPositive() function does this part. Note that in findMissingPositive, we have subtracted 1 from the values as indexes start from 0 in C.

my own solution leetcode + ghg type par better
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        int n=nums.size(),i,f=0;
        if(nums.size()==1 && nums[0]==1) return 2;
        if(nums.size()==1) return 1;
        for(i=0;i<n;i++)
        {
            if(nums[i]==1) {
                f=1;
                break;
            }
        }
        if(f==0) return 1;
        for(i=0;i<n;i++)
        {
            if(nums[i]==0 || nums[i]<0 || nums[i]>n)
                nums[i]=1;
        }
        
          for(i=0;i<n;i++)
        {
           
                int k=abs(nums[i]);
                if(k==n)
                {
                    if(nums[0]>0) nums[0]=-1*nums[0];
                }
              else{
                  if(nums[k]>0)
                      nums[k]=-1*nums[k];
              }
                   
        }
        for(i=1;i<n;i++)
        {
        
            if(nums[i]>0) {
                return i;
            }
        }
        if(nums[0]<0) return n+1;
        
        
        return n;
        
    }
};
