/* prateek coding blocks ka video h acha*/

/* is possible or not*/
#include<bits/stdc++.h>

using namespace std;
const int d=10;
bool safe(int board[d][d],int n,int row,int col)
{
for(int i=0;i<=row;i++)
{
	if(board[i][col]==1)
	return false;
}
int x=row;
int y=col;
while(x>=0 && y>=0)
{
	if(board[x][y]==1)
	return false;
	x--;
	y--;
}
 x=row;
 y=col;
while(x>=0 && y<n)
{
	if(board[x][y]==1)
	return false;
	x--;
	y++;
}
return true;
}
bool solve(int board[d][d],int row,int n)
{
	if(row==n)
     return true;


	
	for(int j=0;j<n;j++)
	{
		if(safe(board,n,row,j)){
			board[row][j]=1;
			bool a=solve(board,row+1,n);
			if(a) return true;
			board[row][j]=0;
			
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int board[d][d]={0};
	bool ans=solve(board,0,n);
	cout<<ans<<endl;

	
	
}

/*--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

 /*print all configuration/*
#include<bits/stdc++.h>

using namespace std;
const int d=10;
bool safe(int board[d][d],int n,int row,int col)
{
for(int i=0;i<=row;i++)
{
	if(board[i][col]==1)
	return false;
}
int x=row;
int y=col;
while(x>=0 && y>=0)
{
	if(board[x][y]==1)
	return false;
	x--;
	y--;
}
 x=row;
 y=col;
while(x>=0 && y<n)
{
	if(board[x][y]==1)
	return false;
	x--;
	y++;
}
return true;
}
bool solve(int board[d][d],int row,int n)
{
	if(row==n)
	{
			
			for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<board[i][j]<<" ";
		}
		cout<<endl;
	}
		return true;
	}


	
	for(int j=0;j<n;j++)
	{
		if(safe(board,n,row,j)){
			board[row][j]=1;
			bool a=solve(board,row+1,n);
			board[row][j]=0;
			
		}
	}
	return false;
}
int main()
{
	int n;
	cin>>n;
	int board[d][d]={0};
	bool ans=solve(board,0,n);

	
	
}
