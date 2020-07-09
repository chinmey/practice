 Given an array of integers, every element appears N times except for one which occurs once
 
 // see black cover copy afetr backtracking for explain
 
 int Solution::singleNumber(const vector<int> &A) {
    
    int countset[32]={0};
    int i,n=A.size(),j;
    
    for(i=0;i<32;i++)
    {
        for(j=0;j<n;j++)
        {
            if(A[j]&(1<<i))
            countset[i]++;
        }
    }
    
    for(i=0;i<32;i++)
    countset[i]=countset[i]%N;
    int res=0;
    
    for(i=0;i<32;i++)
    {
        if(countset[i])
        res=res+pow(2,i);
    }
    return res;
}
