Given n people standing in a circle where 1st is having sword, 
find the luckiest person in the circle, if from 1st soldier who is having a sword each have to kill the next soldier 
and handover the sword to next soldier, in turn the soldier will kill the adjacent soldier and handover the sword to next soldier such that one soldier remain in this war who is not killed by anyone.



If you work this out for different values of n the you will find a pattern here.
 If n is a true power of 2 then the answer is always 1. For every n greater than that power of 2 the answer is incremented by 2.

1	1 + 0	2 * 0 + 1 = 1
2	2 + 0	2 * 0 + 1 = 1
3	2 + 1	2 * 1 + 1 = 3
4	4 + 0	2 * 0 + 1 = 1
5	4 + 1	2 * 1 + 1 = 3
6	4 + 2	2 * 2 + 1 = 5
7	4 + 3	2 * 3 + 1 = 7
8	8 + 0	2 * 0 + 1 = 1
9	8 + 1	2 * 1 + 1 = 3
10	8 + 2	2 * 2 + 1 = 5
11	8 + 3	2 * 3 + 1 = 7
12	8 + 4	2 * 4 + 1 = 9

#include<bits/stdc++.h>
using namespace std;
int perfect(int n)
{
    int m=1,c=0;
    while(n)
    {
        if(n&&m)
        c++;
        n=n>>1;
    }
    if(c==1)
    return 1;
    else
    return 0;
}
int highest(int n)
{
    int m=1,c=0,ans=0;
    while(n)
    {
        if(n&&m)
        ans=c;
        c++;
        n=n>>1;
        
    }
    return ans;
    
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,f=0;
	    cin>>n;
	    if(perfect(n))
	    {
	        
	        cout<<"1"<<endl;
	    }
	    else
	    {
	        int k=highest(n);
	        int j=1;
	        n=n-pow(2,k);
	        while(n--)
	        {
	           j=j+2; 
	        }
	        cout<<j<<endl;
	    }
	    
	}
	
}
