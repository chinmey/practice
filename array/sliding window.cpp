/*1. find sum of all subarray with size k*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[6]={1,2,3,4,5,6};
    int k=3;
    int i,j=0,sum=0;
    for(i=0;i<k;i++)
    {
        sum=sum+arr[i];

    }

    cout<<sum;
    for(i=k;i<6;i++)
    {
        sum=sum+arr[i]-arr[j];
        j++;
        cout<<sum;

    }

}
/* given an array find length of smallest subarry with sum=k*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[5]={1,2,3,4,5};
    int k=12;
    int i=-1,j=-1,sum=0,ans=100;
    while(j<5 && i<5 && i<=j)
    {
        if(sum<k)
            {
                j++;
                sum=sum+arr[j];
            }
        else if(sum >k)
            {
                i++;
                sum=sum-arr[i];
            }
        else if(sum==k)
            {
                ans=min(ans,j-i);

                j++;
                sum=sum+arr[j];
            }
    }
    cout<<ans;
}
/*Smallest subarray with sum greater than a given value

arr[] = {1, 4, 45, 6, 0, 19}
   x  =  51
Output: 3
Minimum length subarray is {4, 45, 6}*/
int smallestSubWithSum(int arr[], int n, int x)
{
    // Initialize current sum and minimum length
    int curr_sum = 0, min_len = n+1;

    // Initialize starting and ending indexes
    int start = 0, end = 0;
    while (end < n)
    {
        // Keep adding array elements while current sum
        // is smaller than x
        while (curr_sum <= x && end < n)
            curr_sum += arr[end++];

        // If current sum becomes greater than x.
        while (curr_sum > x && start < n)
        {
            // Update minimum length if needed
            if (end - start < min_len)
                min_len = end - start;

            // remove starting elements
            curr_sum -= arr[start++];
        }
    }
    return min_len;
}

/* given an array print largrst element in each subarray of size k*/

deque<int> q(k);
for(i=0;i<k;i++)
{

    while(!q.empty() && a[i]>a[q.back()])
        q.pop_back();
    q.push_back(i);
}
for(;i<n;i++)
{

    cout<<a[q.front()];
    while(!q.empty() && q.front()<=i-k)
        q.pop_front();
          while(!q.empty() && a[i]>a[q.back()])
        q.pop_back();
         q.push_back(i);


}








