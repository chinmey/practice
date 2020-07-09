
/*find first point where sum before an element is same as sum after*/
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,sum=0,leftsum=0,ans;
	    cin>>n;


	    int arr[n],i,flag=0;
	    for(i=0;i<n;i++)
	    cin>>arr[i];

	      for(i=0;i<n;i++)
	      sum=sum+arr[i];
	      for(i=0;i<n;i++)
	      {
	          if(arr[i]==sum-2*leftsum)
	          {
	              ans=i+1;

	              flag=1;
	              break;


	          }
	          leftsum=leftsum+arr[i];


	      }
	      if(flag==0)
	     cout<<"-1"<<endl;
	     else

	     cout<<ans<<endl;
	}
	return 0;
}
------------------------------------------------------------------------------------------

Given an array arr[] of size N containing 0s and 1s only. The task is to count the subarrays having equal number of 0s and 1s.

/*This is a function problem.You only need to complete the function given below*/
long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        if(arr[i]==0)
        arr[i]=-1;
    }
    long long int c=0;
    int sum=0;
    map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        sum=sum+arr[i];
        if(sum==0)
        c++;
        
        c=c+mp[sum]; /* if this sum is seen before it means that sum between that period is zero*/
        
        mp[sum]++;
        
    }
    return c;
}
