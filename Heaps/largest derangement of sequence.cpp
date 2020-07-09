#include<bits/stdc++.h>
using namespace std;
void printLargest(int seq[],int n)
{
    priority_queue<int>pq; // if we use min heap we would get smallest derangement
    for(int i=0;i<n;i++)
        pq.push(seq[i]);
    int res[n];
    for(int i=0;i<n;i++)
    {
        int d=pq.top();
        pq.pop();
        if(seq[i]!=d||i==n-1)
        {
            res[i]=d;
        }
        else
        {
            res[i]=pq.top();
            pq.pop();
            pq.push(d);
        }
    }

      // If given sequence is in descending order then
    // we need to swap last two elements again
    if (res[n - 1] == seq[n - 1]) {
        res[n - 1] = res[n - 2];
        res[n - 2] = seq[n - 1];
    }
       printf("\nLargest Derangement \n");
    for (int i = 0; i < N; i++)
        printf("%d ", res[i]);
}
int main()
{
    int seq[]= { 92, 3, 52, 13, 2, 31, 1 };
     int n = sizeof(seq)/sizeof(seq[0]);
    printLargest(seq, n);


    return 0;
}
