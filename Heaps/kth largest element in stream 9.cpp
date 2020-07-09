#include<bits/stdc++.h>
using namespace std;

void kthLargest(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq;
    int i;
    for(i=0;i<k-1;i++)
    {
        pq.push(arr[i]);
        cout<<"-1"<<endl;
    }
    pq.push(arr[k-1]);

    for(i=k;i<n;i++)
    {
        if(i<n-1)
            cout<<pq.top()<<endl;
        if(arr[i]>pq.top())
        {
            pq.pop();
            pq.push(arr[i]);
        }
    }
    cout<<pq.top()<<endl;
}

int main()
{
   int arr[] = {10, 20, 11, 70, 50, 40, 100, 55};
   int k = 3;
   int n = sizeof(arr)/sizeof(arr[0]);
   kthLargest(arr, n, k);
   return 0;
}

