#include <bits/stdc++.h>
using namespace std;



int rown[]={-1,0,0,1};
int coln[]={0,1,-1,0};
bool isvalid(int x,int y,int row,int col)
{
    return (x>=0)&&(y>=0)&&(x<row)&&(y<col);
}
int path(int mat[][3],int row,int col)
{
    int i,j;
    bool visit[row][col]={0};
    visit[0][0]=1;
    queue<pair<int,int> >q;
    q.push(make_pair(0,0));
    while(!q.empty())
    {
        pair<int,int> focus=q.front();
        q.pop();
        pair<int,int> use;
        for(i=0;i<4;i++)
        {
            use.first=focus.first+rown[i];
            use.second=focus.second+coln[i];
            if(!visit[ use.first][ use.second]&&isvalid(use.first,use.second,row,col)&&mat[use.first][use.second])
            {
                if(mat[use.first][use.second]==9)
                    return 1;
                q.push(make_pair(use.first,use.second));
            }

        }

    }
return 0;


}
int main()
{
    int row=3,col=3;
    int mat[3][3]={{1,0,0},{1,1,0},{0,0,1}};
    int res=path(mat,row,col);// we can also use (int*)mat
    cout<<res;


}
