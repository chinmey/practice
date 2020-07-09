/*  for undirected graphs*/

/*Before we go to the problem, let us understand what is a connected component.
A connected component of an undirected graph is a subgraph in which every two vertices are connected to each other by a path(s),
and which is connected to no other vertices outside the subgraph.
  */

/* a group of connected ones form a island ,so we basically iterate through the matrix and as we encouter one we
increase the count,and call dfs so all its neighbour are changed to visited
ans are not counted again
same can be done using bfs*/
#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

int isSafe(int M[][COL], int row, int col,
           bool visited[][COL])
{
    // row number is in range, column
    // number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}


void DFS(int M[][COL], int row, int col,
         bool visited[][COL])
{
    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
            DFS(M, row + rowNbr[k], col + colNbr[k], visited);
}


int countIslands(int M[][COL])
{

    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    // Initialize count as 0 and
    // travese through the all cells of
    // given matrix
    int count = 0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new island found
                // Visit all cells in this island.
                DFS(M, i, j, visited);

                // and increment island count
                ++count;
            }

    return count;
}


int main()
{
    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 0, 0, 0, 0 },
                     { 1, 0, 1, 0, 1 } };

    cout << "Number of islands is: " << countIslands(M);

    return 0;
}
---------------------------------------------------------------------

largest area of one 



#include <bits/stdc++.h>
using namespace std;

#define ROW 5
#define COL 5

int isSafe(int M[][COL], int row, int col,
           bool visited[][COL])
{
    // row number is in range, column
    // number is in range and value is 1
    // and not yet visited
    return (row >= 0) && (row < ROW) && (col >= 0) && (col < COL) && (M[row][col] && !visited[row][col]);
}


void DFS(int M[][COL], int row, int col,
         bool visited[][COL],int &count)
{
    // These arrays are used to get
    // row and column numbers of 8
    // neighbours of a given cell
    static int rowNbr[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    static int colNbr[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    // Mark this cell as visited
    visited[row][col] = true;

    // Recur for all connected neighbours
    for (int k = 0; k < 8; ++k)
        if (isSafe(M, row + rowNbr[k], col + colNbr[k], visited))
           {
           	count++;
			 DFS(M, row + rowNbr[k], col + colNbr[k], visited,count);
}}


int countIslands(int M[][COL])
{

    bool visited[ROW][COL];
    memset(visited, 0, sizeof(visited));

    // Initialize count as 0 and
    // travese through the all cells of
    // given matrix
    int count = 1,res=0;
    for (int i = 0; i < ROW; ++i)
        for (int j = 0; j < COL; ++j)

            // If a cell with value 1 is not
            if (M[i][j] && !visited[i][j]) {
                // visited yet, then new island found
                // Visit all cells in this island.
                DFS(M, i, j, visited,count);

                res=max(res,count);
            }

    return res;
}


int main()
{
    int M[][COL] = { { 1, 1, 0, 0, 0 },
                     { 0, 1, 0, 0, 1 },
                     { 1, 0, 0, 1, 1 },
                     { 0, 1, 0, 0, 0 },
                     { 1, 1, 1, 0, 1 } };

    cout << "Number of islands is: " << countIslands(M);

    return 0;
}
---------------------------------------------------------------------------------------------------------------
take input in case of input like  OXXOXXOX etc
  for( i=0;i<n;i++)
          {
              string str;
              cin>>str;
              for( j=0;j<str.size();j++)
                {
                    if(str[j]=='X')
                       adj[i][j]=1;
                    else 
                     adj[i][j]=0;
                     vis[i][j]=0;
                }
          }
