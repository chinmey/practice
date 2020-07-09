/* an element is leader if it is greater than all elements right to it , rightmost element is always leader*/
/* we scan our array from right , initialising our max as rightmost element now if an elemnet is greater than this one we add it to answer array*/



#include<bits/stdc++.h>
using namespace std;
int main()
{
    int ans[5],k=0;
    int arr[5]={5,2,3,4,1};
    int max=arr[4];
    int i;
    for(i=3;i>=0;i--)
    {
        if(arr[i]>=max)
        {
        ans[k]=arr[i];
        k++;
         max=arr[i];
        }
    }
    int rans[5];
    for(int i=0;i<k;i++)
        rans[i]=ans[k-i-1];
    rans[k]=1;

    for(int i=0;i<=k;i++)
        cout<<rans[i];
      /*   vector<int> g1;

    for (int i = 1; i <= 5; i++)
        g1.push_back(i);*/
}
