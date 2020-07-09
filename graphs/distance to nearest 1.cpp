Input:
2
2 2 
1 0 0 1
1 2
1 1

Output:
0 1 1 0
0 0






#include<bits/stdc++.h>
using namespace std;
#define N 500
struct point
{
    int x;
    int y;
};
bool isvalid(int a,int b,int n,int m)
{
    return (a>=0) && (b>=0) && (a<n) && (b<m);
}
struct qpoint
{
    point p;
    int d;
};
int row[]={-1,0,0,1};
int col[]={0,-1,1,0};
void bfs(int mat[][N],int n,int m)
{
    queue<qpoint>q;
    bool visit[n][m];
    int ans[n][m]={0};
    memset(visit,false,sizeof(visit));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mat[i][j]==1)
            {
                qpoint k={{i,j},0};
                q.push(k);
                visit[i][j]=true;
                ans[i][j]=0;
            }
        }
    }
    while(q.empty()==false)
    {
        qpoint pt=q.front();
        point curr=pt.p;
        q.pop();
        for(int k=0;k<4;k++)
        {
            int a=curr.x+row[k];
            int b=curr.y+col[k];
            if(isvalid(a,b,n,m) && !visit[a][b])
            {
                visit[a][b]=true;
                int dis= pt.d+1;
                qpoint de={{a,b},dis};
                q.push(de);
                ans[a][b]=dis;
            }
            
        }
    }
    for(int a=0;a<n;a++)
    {
        for(int b=0;b<m;b++)
        {
            cout<<ans[a][b]<<" ";
        }
    }
    cout<<endl;
    
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,i,j;
	    cin>>n>>m;
	    int mat[N][N],ans[N][N];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        cin>>mat[i][j];
	    }
	    
	    bfs(mat,n,m);
	       
	    
	}
	return 0;
}
