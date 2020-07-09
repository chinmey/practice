#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
		/* to obtain value of cell first we exclude that coin than we include it
		exclude means just above cell , include means same row cell but with less sum*/
	    int n,i,j;
	    cin>>n;
	    int coins[n];
	    for(i=0;i<n;i++)
	    cin>>coins[i];
	    int sum;
	    cin>>sum;
	    int dp[n+1][sum+1];
	    for(i=0;i<=n;i++)
	    dp[i][0]=1;
	    for(i=1;i<=sum;i++)
	    dp[0][i]=0;
	    for(i=1;i<=n;i++)
	    {
	        for(j=1;j<=sum;j++)
	        {
	            if(coins[i-1]>j)
	            dp[i][j]=dp[i-1][j];
	            else
	            dp[i][j]=dp[i-1][j]+dp[i][j-coins[i-1]];
	        }
	    }
	   
	    cout<<dp[n][sum]<<endl;
	}
	return 0;
}
this technique is aloso used in 0/1 knapsack
----------------------------------------------------------------------------------------------------------

/*this can also be done using if else greedy  shown below*/
#include<bits/stdc++.h>
using namespace std;

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int k,i,j;
	    cin>>k;
	    int coins[10]={1,2,5,10,20,50,100,200,500,2000};
	    int tab[k+1];
	    for(i=0;i<k+1;i++)
	    tab[i]=k+1;
	    tab[0]=0;
	    for(i=1;i<=k;i++)
	    {
	        for(j=0;j<10;j++)
	        {
	            if(i>=coins[j])
	            {
	                tab[i]=min(tab[i],tab[i-coins[j]]+1);
	            }
	        }
	    }
	    cout<<tab[k]<<endl;


	}
	return 0;
}
/* greedy approach*/

int n;
cin>>n;// n=64
int coins[4]={1,2,10,20};
int c=0;
while(n)
{
	if(n>=20)
	{
		n=n-20;
		c++;
	}
	else if(n>=10)
	{
		n=n-10;
		c++;
	}
	and so on
}
