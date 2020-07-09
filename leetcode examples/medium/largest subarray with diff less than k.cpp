Given an array of integers nums and an integer limit, 
return the size of the longest continuous subarray such that the absolute difference between any two elements is less than or equal to limit.


Input: nums = [8,2,4,7], limit = 4
Output: 2 
Explanation: All subarrays are: 
[8] with maximum absolute diff |8-8| = 0 <= 4.
[8,2] with maximum absolute diff |8-2| = 6 > 4. 
[8,2,4] with maximum absolute diff |8-2| = 6 > 4.
[8,2,4,7] with maximum absolute diff |8-2| = 6 > 4.
[2] with maximum absolute diff |2-2| = 0 <= 4.
[2,4] with maximum absolute diff |2-4| = 2 <= 4.
[2,4,7] with maximum absolute diff |2-7| = 5 > 4.
[4] with maximum absolute diff |4-4| = 0 <= 4.
[4,7] with maximum absolute diff |4-7| = 3 <= 4.
[7] with maximum absolute diff |7-7| = 0 <= 4. 
Therefore, the size of the longest subarray is 2.


class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n=nums.size();
        
        multiset<int>m;
        
        int i=0,j=0,ans=0;
        
        for(j=0;j<n;j++)
        {
            m.insert(nums[j]);
            
            while(*m.rbegin() - *m.begin() > limit)
            {
                m.erase(m.find(nums[i++]));
            }
           ans=max(ans,j-i+1) ;
        }
        return ans;
        
    }
};
