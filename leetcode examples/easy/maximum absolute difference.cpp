You are given an array of N integers, A1, A2 ,…, AN. Return maximum value of f(i, j) for all 1 = i, j = N.
f(i, j) is defined as |A[i] - A[j]| + |i - j|, where |x| denotes absolute value of x.

A=[1, 3, -1]

f(1, 1) = f(2, 2) = f(3, 3) = 0
f(1, 2) = f(2, 1) = |1 - 3| + |1 - 2| = 3
f(1, 3) = f(3, 1) = |1 - (-1)| + |1 - 3| = 4
f(2, 3) = f(3, 2) = |3 - (-1)| + |2 - 3| = 5

So, we return 5.

time ---O(N);

Just try to expand this expression and see what all possible values can they be without using ABSOLUTE OPERATORS
|A[i] - A[j]| + |i - j|

It should boil down to following 4 values (because |x-y| = |y-x|).

(A[i]-A[j]) + (i-j) 
(-A[i]+A[j]) + (i-j)  
(A[i]-A[j]) + (-i+j)
(-A[i]+A[j]) + (-i+j)
Let’s try to be symmetrical here by organizing above four expressions.

(A[i]-A[j]) + (i-j)   = (A[i]+i) - (A[j]+j)
(-A[i]+A[j]) + (i-j)  = (A[j]-j) - (A[i]-i)
(A[i]-A[j]) + (-i+j)  = (A[i]-i) - (A[j]-j)
(-A[i]+A[j]) + (-i+j) = (A[j]+j) - (A[i]+i)
If we ignore indices i and j. Then 1, 4 is same and 2, 3 are same.

So it boils down to two final expressions:
Difference of sums: (A[i]+i) - (A[j]+j)
or
Difference of differences: (A[i]-i) - (A[j]-j)

We need to find which one yields max value of these. Hope that helps!


int Solution::maxArr(vector<int> &A) {
    
    int n=A.size(),i,j;
    int max_sum=INT_MIN,min_sum=INT_MAX,res=0;
    
    for(i=0;i<n;i++)
    {
        max_sum=max(max_sum,A[i]+i);
        min_sum=min(min_sum,A[i]+i);
    }
    res=max_sum-min_sum;
    
    max_sum=INT_MIN,min_sum=INT_MAX;
    
    for(i=0;i<n;i++)
    {
        max_sum=max(max_sum,A[i]-i);
        min_sum=min(min_sum,A[i]-i);
    }
    res=max(res,max_sum-min_sum);
    return res;
}

