#include<bits/stdc++.h>
using namespace std;
bool cmp(string x,string y)
{
    string xy=x+y;
    string yx=y+x;
    return xy>yx;  /* if we return yx>xy we get smallest no*/
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j;
	    string s;
	    cin>>n;
	    vector<string> v;
	    for(i=0;i<n;i++)
	    {
	        cin>>s;
	        v.push_back(s);
	    }
	    sort(v.begin(),v.end(),cmp);
	    for(auto it=v.begin();it!=v.end();it++)
	    cout<<*it;
	    cout<<endl;
	}
	return 0;
}

// a/2 +b/2+a%2&b%2 ---average of two numbers
