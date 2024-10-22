Given an integer array of n integers, find sum of bit differences in all pairs that can be formed from array elements. 
Bit difference of a pair (x, y) is count of different bits at same positions in binary representations of x and y.
For example, bit difference for 2 and 7 is 2. Binary representation of 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).

Input: arr[] = {1, 2}
Output: 4
All pairs in array are (1, 1), (1, 2)
                       (2, 1), (2, 2)
Sum of bit differences = 0 + 2 +
                         2 + 0
                      = 4
                      
                      
An Efficient Solution can solve this problem in O(n) time using the fact that all numbers are represented using 32 bits (or some fixed number of bits).
 The idea is to count differences at individual bit positions. We traverse from 0 to 31 and count numbers with i�th bit set. Let this count be �count�.
  There would be �n-count� numbers with i�th bit not set. So count of differences at i�th bit would be �count * (n-count) * 2�, 
  the reason for this formula is as every pair having one element which has set bit at i�th position and 
  second element having unset bit at i�th position contributes exactly 1 to sum, therefore total permutation count will be count*(n-count) and multiply by 2 
  is due to one more repetition of all this type of pair as per given condition for making pair 1<=i,j<=N.
  
  
int Solution::hammingDistance(const vector<int> &A) {
    int n=A.size();
     int  ans=0;
    int i,j;
    for(int i=0;i<32;i++)
    {
        int count=0;
        for(j=0;j<n;j++)
        {
            if((A[j] & (1<<i)))
            count++;
        }
        ans=(int)((ans+(count*2LL*(n-count)))%1000000007);
    }
    
   return ans;
}
