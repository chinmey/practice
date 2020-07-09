/*Given a N X N matrix (M) filled with 1, 0, 2, 3. The task is to find whether there is a path possible from source to destination, 
while traversing through blank cells only. You can traverse up, down, right and left.

A value of cell 1 means Source.
A value of cell 2 means Destination.
A value of cell 3 means Blank cell.
A value of cell 0 means Blank Wall.
example
4
3 0 0 0 0 3 3 0 0 1 0 3 0 2 3 3
3 0 0 0
0 3 3 0
0 1 0 3
0 2 3 3*/


#include<bits/stdc++.h>

using namespace std;
#define N 20
struct point
{
    int x;
    int y;
};
int rown[]={-1,0,0,1};
int coln[]={0,1,-1,0};
bool isvalid(int a,int b,int n)
{
     return (a>=0)&&(b>=0)&&(a<n)&&(b<n);
}

bool isexists(int n,int mat[][N],point s,point d)
{
    point u;
    queue<point>q;
    int i;

    bool visit[n][n];
    memset(visit,false,sizeof visit);
    visit[s.x][s.y]=true;
    q.push(s);
    while(!q.empty())
    {
        point cur=q.front();
        if(cur.x==d.x && cur.y ==d.y)
        return 1;
        q.pop();
        for(i=0;i<4;i++)
        {
            u.x=cur.x+rown[i];
            u.y=cur.y+coln[i];
            if(isvalid(u.x,u.y,n) && mat[u.x][u.y]!=0 && visit[u.x][u.y]==0)
            {
                visit[u.x][u.y]=1;
                q.push(u);
            }
        }
    }
    return 0;








}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j;
	    cin>>n;
	    int mat[N][N];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        cin>>mat[i][j];
	    }
	    point s;
	    point d;
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            if(mat[i][j]==1)
	            {
	                s.x=i;
	                s.y=j;
	            }
	            if(mat[i][j]==2)
	            {
	                d.x=i;
	                d.y=j;
	            }
	        }
	    }
	    bool path;
	    path=isexists(n,mat,s,d);
	    cout<<path<<endl;


	}
	return 0;
}
