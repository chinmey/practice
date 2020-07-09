Given a sorted array nums, remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

Given nums = [0,0,1,1,1,2,2,3,3,4],

Your function should return length = 5, with the first five elements of nums being modified to 0, 1, 2, 3, and 4 respectively.

It doesn't matter what values are set beyond the returned length.


 int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        int j=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]!=nums[i+1])
                nums[j++]=nums[i];
        }
        nums[j++]=nums[n-1];
        return j;

    }
    
-----------------------------------------------------------------------------------------------
2 question.)array resize and unique easy way to remove duplicates
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    vector<int> v = { 1, 1, 3, 3, 3, 10, 1, 3, 3, 7, 7, 8 }, i;

    vector<int>::iterator ip;

    // Using std::unique
    ip = std::unique(v.begin(), v.begin() + 12);
    // Now v becomes {1 3 10 1 3 7 8 * * * * *}
    // * means undefined

    // Resizing the vector so as to remove the undefined terms
    v.resize(std::distance(v.begin(), ip));

    // Displaying the vector after applying std::unique
    for (ip = v.begin(); ip != v.end(); ++ip) {
        cout << *ip << " ";
    }

    return 0;
}

1 3 10 1 3 7 8
