#include<bits/stdc++.h>
using namespace std;
int main()
{
   /* int n,i,k;
    cin>>n;
    int arr[n];
    for(i=0;i<n;i++)
        cin>>arr[i];
    cin>>k;
    for(i=0;i<n;i=i+k)
    {
        int l=i;
        int r=min(i+k-1,n-1);
        while(l<r)
            swap(arr[l++],arr[r--]);

    }
      for(i=0;i<n;i++)
        cout<<arr[i]<<" ";*/
        
  int n,i,k;
  cin>>n;
  vector<int>arr;
  for(i=0;i<n;i++)
  cin>>arr[i];
  cin>>k;
  for(i=0;i<n;i=i+k)
  {
  	while(i+k<=n)
  	reverse(arr.begin()+i,arr.begin()+i+k);
  }
      for(i=0;i<n;i++)
        cout<<arr[i]<<" ";
  
}
