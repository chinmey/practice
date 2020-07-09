/* we would be given an array in which every element is at max k position out of place we nned to sort it*/

#include<bits/stdc++.h>
using namespace std;
void sortK(int arr[],int n,int k)
{
    priority_queue<int,vector<int>,greater<int>>pq(arr,arr+k+1);//min heap using stl
    int index=0;
    for(int i=k+1;i<n;i++)
    {
        arr[index++]=pq.top();
        pq.pop();
        pq.push(arr[i]);

    }
    while(pq.empty()==false)
    {
        arr[index++]=pq.top();
        pq.pop();
    }
}
void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}
int main()
{
     int k = 3;
    int arr[] = { 2, 6, 3, 12, 56, 8 };
    int n = sizeof(arr) / sizeof(arr[0]);
    sortK(arr, n, k);

    cout << "Following is sorted arrayn";
    printArray(arr, n);

    return 0;
}
