#include<bits/stdc++.h>


using namespace std;
int main()
{
 int x,p,q,n;
	    cin>>x>>p>>q>>n;
	    int c[64]={0};
	    int m=x,i=0;
	    while(m)
	    {
	        c[i]=c[i]+m&1;
	        m=m>>1;
	        i++;
	    }
	    while(n--)
	    {
	        int t=c[p];
	        c[p]=c[q];
	        c[q]=t;
	        p++;
	        q++;
	    }
	    int s=1,ans=0;
	    for(i=0;i<64;i++)
	    {
	        ans=ans+s*c[i];
	        s=s<<1;
	    }
	    cout<<ans<<endl;
	}

