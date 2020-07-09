Given a 2D grid of characters and a word, the task is to check if that word exists in the grid or not. A word can be matched in 8 directions at any point.

boggle[][]   = {{'G','I','Z'},
                       {'U','E','K'},
                       {'Q','S','E'}};
                       word == geek output 1
                       
/******************************************************************************

own solution check gfg solution if you want

*******************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int m=5;
bool valid(int x,int y,int row,int col)
{
    return x>=0&&x<row&&y>=0&&y<col;
}
bool find(char grid[m][m],int row,int col,string p,int x,int y,int level)
{
    if(level==p.length())
    return true;
    int rowd[]={1,-1,0,0,-1,-1,1,1};
    int cold[]={0,0,1,-1,1,-1,1,-1};
    for(int k=0;k<8;k++)
    {
        if(valid(x,y,row,col))
        {
            if(grid[x][y]==p[level]){
                char temp=grid[x][y];
                grid[x][y]='@';/* mark this cell as visited*/
                if(find(grid,row,col,p,x+rowd[k],y+cold[k],level+1))
                return true;
                grid[x][y]=temp;
            }
        }
    }
    return false;
}
bool solve(char grid[m][m],int row,int col,string p)
{
    int l=p.length();
    if(l>row*col)
    return false;
    for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            if(grid[i][j]==p[0])
            if(find(grid,row,col,p,i,j,0))
            return true;
        }
    }
    return false;
}

int main()
{
    char grid[m][m]={{'g','i','z'},{'u','e','k'},{'q','s','e'}};
    bool ans=solve(grid,3,3,"geek");
    cout<<ans<<endl;
    
    
}
