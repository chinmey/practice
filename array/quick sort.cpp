#include<bits/stdc++.h>
using namespace std;
void Swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
int Partition(int l,int h,int *arr)
{
    int p=arr[h];
    int i=l-1;
    for(int j=l;j<h;j++)
    {
        if(arr[j]<p)
        {
            i++;
            Swap(&arr[i],&arr[j]);
        }
    }
    Swap(&arr[i+1],&arr[h]);
    return i+1;
}
void quicksort(int *arr,int l,int h)
{
    if(l<h)
    {
        int pi=Partition(l,h,arr);
        quicksort(arr,l,pi-1);
        quicksort(arr,pi+1,h);
    }
}
int main()
{

    int arr[6]={11,9,5,13,12,6};
    quicksort(arr,0,5);
    for(int i=0;i<6;i++)
        cout<<arr[i];
}
