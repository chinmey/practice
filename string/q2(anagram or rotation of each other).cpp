#include<bits/stdc++.h>
using namespace std;
int main()
 {
int t;
cin>>t;
while(t--)
{
    string s1,s2,t;
    cin>>s1;
    cin>>s2;

    t=s1+s1;
    int i=t.find(s2);
    if(i==-1)
    cout<<"NO"<<endl;
    else
    cout<<"YES"<<endl;


}
	return 0;
}
