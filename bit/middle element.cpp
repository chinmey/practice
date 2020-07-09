/*Given an array a[] of n integers, a triplet (a[i], a[j], a[k]) is called Magic Triplet if a[i] < a[j] < a[k] and i < j < k.  The task is to count number of magic triplets in a given array.

Say we have the array { 1, 2, 3, 4, 5, 6 }

We want a[i] < a[j] < a[k].

Let us assume each element of the array is a[j], or the middle number in the inequality.
We can loop through the array to find the number of array elements
before a[j] which are smaller then a[j] and the the number of array elements after a[j]
which are bigger than a[j].

In this example
a[j] numSmaller numBigger
1 0 5 (elements 2, 3, 4, 5, 6)
2 1 (element 1) 4 (elements 3, 4, 5, 6)
3 2 (elements 1, 2) 3 (elements 4, 5, 6)
4 3 (elements 1, 2, 3) 2 (elements 5, 6)
5 4 (elements 1, 2, 3, 4) 1 (element 1)
6 5 (elements 1, 2, 3, 4, 5) 0

ans = (0*5) + (1*4) + (2*3) + (3*2) + (4*1) + (5*0) = 20*/

#include<bits/stdc++.h>
using namespace std;
int small(int arr[],int n,int k)
{
    int c=0;
    for(int i=0;i<k;i++)
    {
        if(arr[i]<arr[k])
        c++;
    }
    return c;
}
int big(int arr[],int n,int k)
{
    int c=0;
    for(int i=k+1;i<n;i++)
    {
        if(arr[i]>arr[k])
        c++;
    }
    return c;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int res=0;
	    for(int i=0;i<n;i++)
	    {
	        int a=small(arr,n,i);
	        int b=big(arr,n,i);
	        res=res+a*b;
	    }
	    cout<<res<<endl;
	}
	return 0;
}
