/*first ele max,second ele min ,third 2nd max*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];

    sort(arr,arr+n);


      int j=0;
	  int k=n-1;
	   for(i=0;i<n;i++)
	   {
	       if(i%2!=0)
	       {
	           cout<<arr[j]<<" ";
	           j++;
	       }
	       else
	       {
	           cout<<arr[k]<<" ";
	           k--;
	       }
	   }

       

}
--------------------------------------------------------------
ugly numbers  (only multiple of 2 3 5)(1 2 3 4 5 6 8 9)
   int n;
	   cin>>n;
	   int arr[n];
	   arr[0]=1;
	   int next_t=2,next_th=3,next_f=5;
	   int i2=0,i3=0,i5=0,ans=0;
	   for(int i=1;i<n;i++)
	   {
	       ans=min(next_t,min(next_th,next_f));
	       arr[i]=ans;
	       
	       if(arr[i]==next_f)
	       {
	           i5++;
	           next_f=arr[i5]*5;
	       }
	        if(arr[i]==next_th)
	       {
	           i3++;
	           next_th=arr[i3]*3;
	       }
	       if(arr[i]==next_t)
	       {
	           i2++;
	           next_t=arr[i2]*2;
	       }
	       
	   }
	   cout<<ans<<endl;
