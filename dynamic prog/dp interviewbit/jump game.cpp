Given an array of non-negative integers, A, of length N, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Return the minimum number of jumps required to reach the last index.

If it is not possible to reach the last index, return -1.


   A = [2,3,1,1,4]

Output : 2

int Solution::jump(vector<int> &A) {
    
    int n=A.size();
    
    
    if(n<=1) return 0;
    if(A[0]==0) return -1;
    
    
    int lad=A[0]; /* stores maximum reachable index*/
	int step=A[0]; /* no of stairs in current ladder if it is zero we need to jump */
    int jump=1;
    
    for(int cur=1;cur<n;cur++)
    {
        if(cur==n-1) return jump;
        
        lad=max(lad,cur+A[cur]);
        step--;
        
        if(step==0)
        {
            jump++;
            if(cur>=lad) return -1; /* if we cant reach ending index*/
            step=lad-cur;
        }
    }
    return jump;
}

    
