/*A knight's tour is a sequence of moves of a knight on a chessboard such that the knight visits every square exactly once. 
If the knight ends on a square that is one knight's move from the beginning square (so that it could tour the board again immediately, following the same path), 
the tour is closed; otherwise open*/

#include<bits/stdc++.h>
using namespace std;
const int d=8;
bool canplace(int board[d][d],int n,int r,int c)
{
	return r>=0&&r<n&&c>=0&&c<n&&board[r][c]==0;
}
bool solve(int board[d][d],int n,int move,int currow,int curcol)
{
	if(move==n*n)
	return true;
	static int rowdir[]={+2,+1,-1,-2,-2,-1,+1,+2};
	static int coldir[]={+1,+2,+2,+1,-1,-2,-2,-1};
	for(int k=0;k<8;k++)
	{
		int nextrow=currow+rowdir[k];
		int nextcol=curcol+coldir[k];
		if(canplace(board,n,nextrow,nextcol))
		{
			board[nextrow][nextcol]=move+1;// placing the knight
			bool a=solve(board,n,move+1,nextrow,nextcol);
			if(a)
			return true;
			board[nextrow][nextcol]=0;// removing my knight
		}
	}
	return false;
}
int main()
{
	int board[d][d]={0};
	int n;
	cin>>n;
	board[0][0]=1;
	bool ans=solve(board,n,1,0,0);
	if(ans)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	else
	{
		cout<<"sorry";
	}
}
------------------------------------------------------------------------------------------------------------------------------------------

/* to print all solution*/

// Deepak Aggarwal, Coding Blocks
// deepak@codingblocks.com
#include <iostream>
#include <iomanip>
using namespace std;
const int D = 8;

bool canPlace(int board[D][D], int n, int r, int c){
    return 
        r >= 0 && r < n &&
        c >= 0 && c < n &&
        board[r][c] == 0;
}
void printBoard(int board[D][D], int n){
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << setw(3) << board[i][j] << " ";
        }
        cout << endl;
    }
}

bool solveKnightMove(int board[D][D], int n, int move_no, int curRow, int curCol){
    if (move_no == n*n){
        printBoard(board, n);
        cout << "===========================\n";
        return true;
    }

    static int rowDir[] = {+2, +1, -1, -2, -2, -1, +1, +2};
    static int colDir[] = {+1, +2, +2, +1, -1, -2, -2, -1};
    for(int curDir = 0; curDir < 8; ++curDir){
        int nextRow = curRow + rowDir[curDir];
        int nextCol = curCol + colDir[curDir];
        if (canPlace(board, n, nextRow, nextCol) == true){
            // place the knight
            board[nextRow][nextCol] = move_no + 1; // place the knight
            bool isSuccessful = solveKnightMove(board, n, move_no + 1, nextRow, nextCol);
            // if (isSuccessful == true) return true;
            board[nextRow][nextCol] = 0;    // erase the knight
        }
    }
    return false;
}



int main(){
    int board[D][D] = {0};
    int n; cin >> n;

    board[0][0] = 1;
    bool ans = solveKnightMove(board, n, 1, 0, 0);
    // if (ans == true){
    //     // my function was able to solve it
    //     printBoard(board, n);
    // }
    // else {
    //     cout << "Sorry Man! Can't visit your board";
    // }

    
}
