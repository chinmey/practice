#include<bits/stdc++.h>
using namespace std;
int main()
{

 int n,i,k,flag=0;
cin>>n;
	    string s;
        int count[256]={0};
	    for(i=0;i<n;i++)
	    {
	        cin>>s;
	        count[s[0]]++;
	         k=s.length();
	        k=k-1;
	        count[s[k]]--;
	    }



	    for(i=0;i<256;i++)
        {
            if(count[i]!=0)
            {
                flag=1;
                break;
            }
        }
     if(flag==0)
        cout<<"possible";
        else
        cout<<"not";
}
// will not work for a case like a a a a a etc
