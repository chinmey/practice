Given an unsorted integer array, find the first missing positive integer.

Example:

Given [1,2,0] return 3,

[3,4,-1,1] return 2,

[-8, -7, -6] returns 1

hint
To simply solve this problem, search all positive integers, starting from 1 in the given array. We may have to search at most n+1 numbers in the given array. So this solution takes O(n^2) in worst case.

We can use sorting to solve it in lesser time complexity. We can sort the array in O(nLogn) time.

Once the array is sorted, then a linear scan of the array is all that remains to be done.

So this approach takes O(nLogn + n) time which is O(nLogn).

We can also use hashing. We can build a hash table of all positive elements in the given array.

Once the hash table is built, all positive integers, starting from 1 can be searched here. As soon as we find a number which is not there in the hash table, we return it.

Approximately, this approach may take O(n) time, but it requires O(n) extra space.

But what we are really looking for is a O(n) time, O(1) space solution.

Note that ( N being the size of the array ), A[i]<=0 and A[i]>N are not the numbers you are looking for because the missing positive integer will be in the range [1, N+1].

The answer will be N+1 only if all of the elements of the array are exact one occurrence of [1, N].

If using extra space was an option, creating buckets would have been an easy solution.

Creating an array of size N initialized to 0, for every value A[i] which lies in the range [1, N], we would have incremented its count in the array. Consequently, we would traverse the array to find the first array position with value 0, hence finding our answer.

However, since we are not allowed buckets, can we use the existing array as bucket somehow?

 int firstMissingPositive(vector<int> &A) {
            int n = A.size();
            for (int i = 0; i < n; i++) {
                if (A[i] > 0 && A[i] <= n) {
                    int pos = A[i] - 1;
                    if (A[pos] != A[i]) {
                        swap(A[pos], A[i]);
                        i--;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (A[i] != i + 1) return (i + 1);
            }
            return n + 1;
        }
    /* mera khud ka code best h*/    
        
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
        }/* this is done to smoothly perform next step*/
        if(f==0) return 1;
        for(i=0;i<n;i++)
        {
            if(nums[i]==0 || nums[i]<0 || nums[i]>n)
                nums[i]=1;
        }
        /* sets all unnecessary elements to 1*/
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
