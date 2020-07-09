Given an undirected graph and an integer M. The task is to determine
 if the graph can be colored with at most M colors such that no two adjacent vertices of the graph are colored with the same color.
 Here coloring of a graph means assignment of colors to all vertices. Print 1 if it is possible to colour vertices and 0 otherwise.
 
 The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of four lines. 
 The first line of each test case contains an integer N denoting the number of vertices.
  The second line of each test case contains an integer M denoting the number of colors available.
   The third line of each test case contains an integer E denoting the number of edges available. 
 The fourth line of each test case contains E pairs of space separated integers denoting the edges between vertices.
 
1
4
3
5
1 2 2 3 3 4 4 1 1 3

output==1 as 1 2 3 2

/* the idea  is the general bt one we basically assign color to graph vertix vise we run through one by one 
check if that color is safe ,if safe we assign it than ask recursion to come with entire solution
if it returns true than we are done else we backtrack*/

#include<bits/stdc++.h>
using namespace std;
const int m=50;
struct data{
    int x;
    int y;
};
bool valid(int mat[m][m],int color[],int n,int row,int curcolor)
{
    for(int i=0;i<n;i++)
    {
        if(mat[row][i]&&color[i]==curcolor)
        return false;
    }
    return true;
}
bool solve(int mat[m][m],int color[],int n,int row,int k)
{
    if(row==n)
    return true;
    for(int i=1;i<=k;i++)
    {
        if(valid(mat,color,n,row,i))
        {
            color[row]=i;
            if(solve(mat,color,n,row+1,k))
            return true;
            color[row]=0;
        }
    }
    return false;
}
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,i,j=0;
	    cin>>n;
	    int k;
	    cin>>k;
	    int edge;
	    cin>>edge;
	    data p[edge];
	    int arr[2*edge];
	    for(i=0;i<2*edge;i++)/* graph making process
	    {
	       cin>>arr[i];
	    }
	     for(i=0;i<2*edge;i++)
	    {
	       if(i%2==0)
	       {
	           p[j].x=arr[i];
	           j++;
	       }
	    }
	    j=0;
	       for(i=0;i<2*edge;i++)
	    {
	       if(i%2!=0)
	       {
	           p[j].y=arr[i];
	           j++;
	       }
	    }
	    
	    for(i=0;i<edge;i++)
	    {
	        p[i].x=p[i].x-1;
	        p[i].y=p[i].y-1;*/
	    }
	   /* for(i=0;i<edge;i++)
	    {
	        cout<<p[i].x<<" "<<p[i].y;
	    }*/
	    int mat[m][m]={0};
	    for(i=0;i<edge;i++)
	    {
	        mat[p[i].x][p[i].y]=1;
	        mat[p[i].y][p[i].x]=1;
	    }
	   /* for(i=0;i<n;i++)
	    {
	        for(j=0;j<n;j++)
	        {
	            cout<<mat[i][j]<<" ";
	        }
	        cout<<endl;
	    }*/
	    int color[n]={0};
	    bool ans=solve(mat,color,n,0,k);
	    cout<<ans<<endl;
	    
	}
	return 0;
}
-------------------------------------------------------------------------------------------------------------

gfg editorial

#include<stdio.h> 
#include<stdbool.h> 

// Number of vertices in the graph 
#define V 4 

void printSolution(int color[]); 

/* A utility function to check if the current color assignment 
is safe for vertex v i.e. checks whether the edge exists or not 
(i.e, graph[v][i]==1). If exist then checks whether the color to 
be filled in the new vertex(c is sent in the parameter) is already 
used by its adjacent vertices(i-->adj vertices) or not (i.e, color[i]==c) */
bool isSafe (int v, bool graph[V][V], int color[], int c) 
{ 
	for (int i = 0; i < V; i++) 
		if (graph[v][i] && c == color[i]) 
			return false; 
	return true; 
} 

/* A recursive utility function to solve m coloring problem */
bool graphColoringUtil(bool graph[V][V], int m, int color[], int v) 
{ 
	/* base case: If all vertices are assigned a color then 
	return true */
	if (v == V) 
		return true; 

	/* Consider this vertex v and try different colors */
	for (int c = 1; c <= m; c++) 
	{ 
		/* Check if assignment of color c to v is fine*/
		if (isSafe(v, graph, color, c)) 
		{ 
		color[v] = c; 

		/* recur to assign colors to rest of the vertices */
		if (graphColoringUtil (graph, m, color, v+1) == true) 
			return true; 

			/* If assigning color c doesn't lead to a solution 
			then remove it */
		color[v] = 0; 
		} 
	} 

	/* If no color can be assigned to this vertex then return false */
	return false; 
} 

/* This function solves the m Coloring problem using Backtracking. 
It mainly uses graphColoringUtil() to solve the problem. It returns 
false if the m colors cannot be assigned, otherwise return true and 
prints assignments of colors to all vertices. Please note that there 
may be more than one solutions, this function prints one of the 
feasible solutions.*/
bool graphColoring(bool graph[V][V], int m) 
{ 
	// Initialize all color values as 0. This initialization is needed 
	// correct functioning of isSafe() 
	int color[V]; 
	for (int i = 0; i < V; i++) 
	color[i] = 0; 

	// Call graphColoringUtil() for vertex 0 
	if (graphColoringUtil(graph, m, color, 0) == false) 
	{ 
	printf("Solution does not exist"); 
	return false; 
	} 

	// Print the solution 
	printSolution(color); 
	return true; 
} 

/* A utility function to print solution */
void printSolution(int color[]) 
{ 
	printf("Solution Exists:"
			" Following are the assigned colors \n"); 
	for (int i = 0; i < V; i++) 
	printf(" %d ", color[i]); 
	printf("\n"); 
} 

// driver program to test above function 
int main() 
{ 
	/* Create following graph and test whether it is 3 colorable 
	(3)---(2) 
	| / | 
	| / | 
	| / | 
	(0)---(1) 
	*/
	bool graph[V][V] = {{0, 1, 1, 1}, 
		{1, 0, 1, 0}, 
		{1, 1, 0, 1}, 
		{1, 0, 1, 0}, 
	}; 
	int m = 3; // Number of colors 
	graphColoring (graph, m); 
	return 0; 
} 


