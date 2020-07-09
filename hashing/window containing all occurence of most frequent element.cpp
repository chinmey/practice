#include<bits/stdc++.h>
using namespace std;
int main()
{
    int arr[7]={4,1,1,2,2,1,3},i,x,maximum=0,maxi=0,l=0,u=0;
    map<int,int>fir;
    for(i=0;i<7;i++)
        fir[arr[i]]++;
    for(auto it=fir.begin();it!=fir.end();it++)
    {
        if(it->second>maximum)
        {
            maximum=it->second;
            x=it->first;
        }
    }
    map<int,int>mp;
    for(i=0;i<7;i++)
    {
        if(arr[i]==x)
        {
            if(mp.find(x)==mp.end())
                mp[x]=i;
            else
            {
                if(i-mp[x]>maxi)
                {
                    l=mp[x];
                    u=i;
                }
            }
        }
    }
    cout<<l<<" "<<u;
}
