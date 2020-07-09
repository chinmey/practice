#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s,ans;
    getline(cin,s);
    int count[256]={0};
    for(int i=0;i<s.size();i++)
    {
        if(count[s[i]]==0)
        {
            count[s[i]]++;
            ans=ans+s[i];
        }
    }
    cout<<ans;
}
