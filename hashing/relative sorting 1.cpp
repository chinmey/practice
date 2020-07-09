
Given two arrays A1[] and A2[] of size N and M respectively.
 The task is to sort A1 in such a way that the relative order among the elements will be same as those in A2.
For the elements not present in A2, append them at last in sorted order. .
It is also given that the number of elements in A2[] are smaller than or equal to number of elements in A1[] and A2[] has all distinct elements

 We can also write our own comparator function and pass it as a third parameter. This “comparator” function returns a value; convertible to bool,
  which basically tells us whether the passed “first” argument should be placed before the passed “second” argument or not.

#include<bits/stdc++.h>
using namespace std;
  map<int,int>oc;
bool cmp(int a,int b)
{
    return oc[a]<oc[b];
}
int main()
{
    int arr[10]={1,5,2,0,3,6,3,3,6,6};
    int test[4]={3,2,5,6};

    int i;
    for(i=0;i<4;i++)
        oc[test[i]]=i+1;
    vector<int>ans;
    vector<int>res;
     for(i=0;i<10;i++)
	  {
	      if(oc.find(arr[i])==oc.end())
	      res.push_back(arr[i]);
	      else
	      ans.push_back(arr[i]);
	  }
	  sort(res.begin(),res.end());
	  sort(ans.begin(),ans.end(),cmp);
	   for(i=0;i<res.size();i++)
	  ans.push_back(res[i]);
	    for(i=0;i<ans.size();i++)
	  cout<<ans[i]<<" ";

}

/* same method can be used to sort elements by frequency by making some changes
  int n;
	    cin>>n;
	    int i,arr[n];
	    vector<int>ans;

	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i];
	         ans.push_back(arr[i]);
	         mp[arr[i]]++;
	    }
	    sort(ans.begin(),ans.end(),cmp);
	      for(i=0;i<ans.size();i++)
	  cout<<ans[i]<<" ";
	   bool cmp(int a,int b)
{
    if(mp[a]!=mp[b])
    return mp[a]>mp[b];
    return  a<b;
}*/
