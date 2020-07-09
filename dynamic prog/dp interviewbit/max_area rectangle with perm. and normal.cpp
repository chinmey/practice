Max Rectangle in Binary Matrix


Given a 2D binary matrix filled with 0’s and 1’s, find the largest rectangle containing all ones and return its area.


see tushar roy video for clear explaination

A : [  1 1 1
       0 1 1
       1 0 0 
    ]

Output : 4 

int find(int *A,int n) /* largest histogram solution using stack*/
{
    int i=0;
    stack<int>s;
    int ans=0;
      while(i<n)
     {
         if(s.empty()==true || A[s.top()]<A[i])
         s.push(i++);
         
         else
         {
             int top=A[s.top()];
             s.pop();
             
             if(s.empty()==true)
             ans=max(ans,top*i);
             else
             ans=max(ans,top*(i-1-s.top()));
             
         }
     }
       while(s.empty()==false)
     {
          int top=A[s.top()];
             s.pop();
             
             if(s.empty()==true)
             ans=max(ans,top*i);
             else
             ans=max(ans,top*(i-1-s.top()));
     }
     return ans;
    
}

int Solution::maximalRectangle(vector<vector<int> > &A) {
    
    int rowsize=A.size();
    int colsize=A[0].size();
    int i,j;
    
    int dp[colsize];
    
    for(j=0;j<colsize;j++)
    dp[j]=A[0][j];
    
    int res=find(dp,colsize);
    int var=1;
    while(var<rowsize){
    for(j=0;j<colsize;j++)
    {
        if(A[var][j]==0)
        dp[j]=0;
        else
        dp[j]=dp[j]+1;
    }
    res=max(res,find(dp,colsize));
    var++;
    }
    return res;
}
/* maximum square in a binary matrix*/

    #include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,i,j,res=0;
	    cin>>n>>m;
	    int mat[n][m],dp[n][m];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            cin>>mat[i][j];
	            dp[i][j]=mat[i][j];
	        }
	    }
	    for(i=1;i<n;i++)
	    {
	        for(j=1;j<m;j++)
	        {
	            if(mat[i][j])
	            {
	                dp[i][j]=min(dp[i][j-1],min( dp[i-1][j],  /*important step*/
                                dp[i-1][j-1])) + 1;
	            }
	        }
	    }
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            res=max(res,dp[i][j]);
	        }
	    }
	    cout<<res<<endl;
	}
	return 0;
}








/*---------------------------------------------------------------------------------------------------------------------------------------------------*/

Largest rectangle with permutation of row allowed


Given a matrix with 0 and 1’s, find the largest rectangle of all 1’s in the matrix. The rectangle can be formed by swapping any pair of columns of given matrix.

Input: bool mat[][] = { {0, 1, 0, 1, 0},
                        {0, 1, 0, 1, 1},
                        {1, 1, 0, 1, 0}
                      };
Output: 6
The largest rectangle's area is 6. The rectangle 
can be formed by swapping column 2 with 3
The matrix after swapping will be
     0 0 1 1 0
     0 0 1 1 1
     1 0 1 1 0
     
step 1: First of all, calculate no. of consecutive 1’s in every column. An auxiliary array hist[][] is used to store the counts of consecutive 1’s.
 So for the above first example, contents of hist[R][C] would be

    0 1 0 1 0
    0 2 0 2 1
    1 3 0 3 0
Time complexity of this step is O(R*C)

Step 2: Sort the columns in non-increasing fashion. After sorting step the matrix hist[][] would be

    1 1 0 0 0
    2 2 1 0 0
    3 3 1 0 0
This step can be done in O(R * (R + C)). Since we know that the values are in range from 0 to R, we can use counting sort for every row.
The sorting is actually the swapping of columns. If we look at the 3rd row under step 2:
3 3 1 0 0
The sorted row corresponds to swapping the columns so that the column with the highest possible rectangle is placed first,
 after that comes the column that allows the second highest rectangle and so on. So, in the example there are 2 columns that can form a rectangle of height 3. 
 That makes an area of 3*2=6. If we try to make the rectangle wider the height drops to 1, because there are no columns left that allow a higher rectangle on the 
 3rd row.

Step 3: Traverse each row of hist[][] and check for the max area. Since every row is sorted by count of 1’s,
 current area can be calculated by multiplying column number with value in hist[i][j]. This step also takes O(R * C) time.
