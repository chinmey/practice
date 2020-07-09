


    int majorityElement(vector<int>& nums) {
      int ind=0,c=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[ind])
                c++;
            else
                c--;
            if(c==0)
            {
                c=1;
                ind=i;
            }
        }
        return nums[ind];
    }
Let the array be A[] = 2, 2, 3, 5, 2, 2, 6

Initialize maj_index = 0, count = 1
Next element is 2, which is same as a[maj_index] => count = 2
Next element is 3, which is different from a[maj_index] => count = 1
Next element is 5, which is different from a[maj_index] => count = 0
Since count = 0, change candidate for majority element to 5 => maj_index = 3, count = 1
Next element is 2, which is different from a[maj_index] => count = 0
Since count = 0, change candidate for majority element to 2 => maj_index = 4
Next element is 2, which is same as a[maj_index] => count = 2
Next element is 6, which is different from a[maj_index] => count = 1
Finally candidate for majority element is 2.
