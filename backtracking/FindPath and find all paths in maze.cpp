


/* find path own solution*/

#include <iostream>
using namespace std;

bool valid(int maze[][20], int n, int x, int y, int path[][20]){
	if(x < 0 || x >= n || y < 0 || y >= n){
			return false;
		}
			if(maze[x][y] == 0 || path[x][y] == 1){
			return false;
		}// if path[x][y]==1 is not included we get struck in loop
		
	return true;
		
}

bool findPath(int maze[][20], int n, int x, int y, int path[][20]){
		
	
		if(x == n - 1 && y == n - 1){
			return true;
		}

		int rowd[]={
		    +1,-1,0,0
		};
		int cold[]={
		    0,0,1,-1
		};
		for(int k=0;k<4;k++)
		{
		    int row=x+rowd[k];
		    int col=y+cold[k];
		    if(valid(maze,n,row,col,path))
		    {
		        path[row][col]=1;
		        if(findPath(maze,n,row,col,path))
		        return true;
		        path[row][col]=0;
		        
		    }
		}
		return false;
		

	
		
}


bool findPath(int maze[][20], int n){

	int path[20][20] = {0};
	path[0][0]=1;
	return findPath(maze, n, 0, 0, path);		

}


int main() {

	// N*N maze
	int n = 3; 

	// Maximum value of N can be 20, so we have kept maze to be big enough 
	int maze[20][20] = {{1,1,0},{1,1,0},{0,1,1}};

	cout << findPath(maze, n) << endl;
	
	


}
----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

/* find all paths own solution*/
#include <iostream>
using namespace std;

bool valid(int maze[][20], int n, int x, int y, int path[][20]){
	if(x < 0 || x >= n || y < 0 || y >= n){
			return false;
		}
			if(maze[x][y] == 0 || path[x][y] == 1){
			return false;
		}// if path[x][y]==1 is not included we get struck in loop
		
	return true;
		
}
void print(int path[][20],int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<path[i][j]<<" ";
		}
		cout<<endl;
	}
}
bool findPath(int maze[][20], int n, int x, int y, int path[][20]){
		
	
		if(x == n - 1 && y == n - 1){
			print(path,n);
			cout<<"*******************************"<<endl;
			return true;
		}

		static int rowd[]={
		    +1,-1,0,0
		};
		static int cold[]={
		    0,0,1,-1
		};
		for(int k=0;k<4;k++)
		{
		    int row=x+rowd[k];
		    int col=y+cold[k];
		    if(valid(maze,n,row,col,path))
		    {
		        path[row][col]=1;
		        bool a=findPath(maze,n,row,col,path);
		        /*if(a) return true;*/
		      
		        path[row][col]=0;
		        
		    }
		}
		return false;
		

	
		
}


bool findPath(int maze[][20], int n){

	int path[20][20] = {0};
	path[0][0]=1;
	return findPath(maze, n, 0, 0, path);		

}


int main() {

	// N*N maze
	int n = 4; 

	// Maximum value of N can be 20, so we have kept maze to be big enough 
	int maze[20][20] = {{1,0,0,0},{1,1,0,1},{1,1,0,0},{0,1,1,1}};  

	cout << findPath(maze, n) << endl;
	
	


}
---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


/* find path in a maze coding ninja */
#include <iostream>
using namespace std;


bool findPath(int maze[][20], int n, int x, int y, int path[][20]){
		if(x < 0 || x >= n || y < 0 || y >= n){
			return false;
		}
	
		if(x == n - 1 && y == n - 1){
			return true;
		}

		if(maze[x][y] == 0 || path[x][y] == 1){
			return false;
		}

		path[x][y] = 1;

		// Right
		if(findPath(maze, n, x, y + 1, path)){
			path[x][y] = 0;
			return true;
		}
		//left

		if(findPath(maze, n, x, y - 1, path)){
			path[x][y] = 0;/*reset the path*/
			return true;
		}

		// top

		if(findPath(maze, n, x - 1, y, path)){
			path[x][y] = 0;
			return true;
		}

		// Down

		if(findPath(maze, n , x + 1, y, path)){
			path[x][y] = 0;
			return true;
		}

		path[x][y] = 0;	
		return false;
}


bool findPath(int maze[][20], int n){

	int path[20][20] = {0};
	return findPath(maze, n, 0, 0, path);		

}


int main() {

	// N*N maze
	int n = 3; 

	// Maximum value of N can be 20, so we have kept maze to be big enough 
	int maze[20][20] = {{1,1,0},{1,1,0},{0,1,1}};

	cout << findPath(maze, n) << endl;

}

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*Find all Paths in a maze*/


#include <iostream>
using namespace std;


void findPath(int maze[][20], int n, int x, int y, int path[][20]){
	if(x < 0 || x >= n || y < 0 || y >= n){
		return; 
	}

	if(x == n - 1 && y == n - 1){
		path[x][y] = 1;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << path[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	if(maze[x][y] == 0 || path[x][y] == 1){
		return; 
	}

	path[x][y] = 1;
	// Right
	findPath(maze, n, x, y + 1, path);
	//left
	findPath(maze, n, x, y - 1, path);
	// top
	findPath(maze, n, x - 1, y, path);
	// Down
	findPath(maze, n , x + 1, y, path);
	path[x][y] = 0;

}


void findPath(int maze[][20], int n){

	int path[20][20] = {0};
	findPath(maze, n, 0, 0, path);		

}


int main() {

	// N*N maze
	int n = 3; 

	// Maximum value of N can be 20, so we have kept maze to be big enough 
	int maze[20][20] = {{1,1,0},{1,1,0},{0,1,1}};

	findPath(maze, n);

}

