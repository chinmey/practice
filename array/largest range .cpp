
/*we will be given an array we need to find largest continous range of numbers present in array
arr[]={0,34,1,2,9,8,13,4,5,23,6}
     ans is [0,6]*/
     output not coming algoexpert ka h dekh lena

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[12] ={1,11,3,0,15,5,2,4,10,7,12,6};

    int left,right,max=0,a,b;
    map<int,bool>visit;
    for(int i=0;i<12;i++)
        visit[arr[i]]=true;
    for(int i=0;i<12;i++)
    {
       int cur=0;
        if(visit[arr[i]]==false)
            continue;
        else
        {
            cur=1;
            left=arr[i]-1;
            right=arr[i]+1;
            while(visit[arr[left]]==true)
            {
               visit[arr[left]] =false;
               left=left-1;
               cur++;
            }
              while(visit[arr[right]]==true)
            {
               visit[arr[right]] =false;
               right=right+1;
               cur++;
            }

        }
        if(cur>max)
           {
               max=cur;

             a=left+1;
             b=right-1;

           }
    }
    cout<<a<<" "<<b;
}
