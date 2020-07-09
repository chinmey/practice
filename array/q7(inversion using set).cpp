Input: arr[] = {8, 4, 2, 1}
Output: 6

Explanation: Given array has six inversions:
(8,4), (4,2),(8,2), (8,1), (4,1), (2,1).

/* using set*/



#include<bits/stdc++.h>
using namespace std;
int main()
{
     int arr[5]={2,4,1,3,5};
     set<int>s;
       s.insert(arr[0]);
     int ic=0;
       set<int>::iterator it;
       for(int i=1;i<5;i++)
       {
             s.insert(arr[i]);
           it=s.upper_bound(arr[i]);
           
            ic+= distance(it, s.end());
       }
       cout<<ic;
}

/* using merge sort*/

#include<bits/stdc++.h>
using namespace std;

int Merge(int arr[],int temp[],int left,int mid,int right){

int i,j,k,ic=0;
i=left;
j=mid;
k=left;
while(i<mid&&j<=right)
{
    if(arr[i]<=arr[j]){
        temp[k++]=arr[i++];
    }else{
      temp[k++]=arr[j++];
      ic=ic+(mid-i);
    }

}
while(i<mid)
{
     temp[k++]=arr[i++];
}
while(j<=right){
    temp[k++]=arr[j++];
}
return ic;
}

int mergesort(int arr[],int temp[],int left,int right)
{
    int mid,ic=0;
    if(right>left)
    {
        mid=(right+left)/2;
        ic=mergesort(arr,temp,left,mid);
        ic=ic+mergesort(arr,temp,mid+1,right);
        ic=ic+Merge(arr,temp,left,mid,right);
    }
    return ic;
}

int main()
{
    int arr[5]={2,4,1,3,5};
    int temp[5];
    int c=mergesort(arr,temp,0,4);
    cout<<c;
}
