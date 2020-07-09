/*0/1 KNAPSACK*/

int knapSack(int W, int wt[], int val[], int n)
{
   int i, w;
   int K[n+1][W+1];

   // Build table K[][] in bottom up manner
   for (i = 0; i <= n; i++)
   {
       for (w = 0; w <= W; w++)
       {
           if (i==0 || w==0)
               K[i][w] = 0;
           else if (wt[i-1] <= w)
                 K[i][w] = max(val[i-1] + K[i-1][w-wt[i-1]],  K[i-1][w]);
           else
                 K[i][w] = K[i-1][w];
       }
   }

   return K[n][W];
}


-------------------------------------------------------------------------------


/* fractional knapsack*/

Given weights and values of N items, we need to put these items in a knapsack of capacity W to get the maximum total value in the knapsack
2
3 50
60 10 100 20 120 30
ans=240.00

#include<bits/stdc++.h>
using namespace std;
struct given{
    float value;
    float weight;
};
bool com(struct given a, struct given b) 
{ 
    double r1 = (double)a.value / a.weight; 
    double r2 = (double)b.value / b.weight; 
    return r1 > r2; 
} 
int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    int W;
	    cin>>n>>W;
	    given arr[n];
	    int i,j;
	    for(i=0;i<n;i++)
	    {
	        cin>>arr[i].value;
	        cin>>arr[i].weight;
	    }
	   sort(arr,arr+n,com);
	   float sum=0.00;
	   for(i=0;i<n;i++)
	   {
	       if(W>=arr[i].weight)
	       {
	           sum=sum+arr[i].value;
	           W=W-arr[i].weight;
	       }
	       else if(W>0 && W<arr[i].weight)
	       {
	           
	           sum += arr[i].value * ((double) W / arr[i].weight); 
	           break;
	       }
	   }
	     printf("%.2f", sum); 
	     cout<<endl;
	  
	   
	}
	return 0;
}

----------------------------------------------------------------------------------

subset with given sum

// A Dynamic Programming solution for subset sum problem 
#include <stdio.h> 

// Returns true if there is a subset of set[] with sun equal to given sum 
bool isSubsetSum(int set[], int n, int sum) 
{ 
	// The value of subset[i][j] will be true if there is a 
	// subset of set[0..j-1] with sum equal to i 
	bool subset[n+1][sum+1]; 

	// If sum is 0, then answer is true 
	for (int i = 0; i <= n; i++) 
	subset[i][0] = true; 

	// If sum is not 0 and set is empty, then answer is false 
	for (int i = 1; i <= sum; i++) 
	subset[0][i] = false; 

	// Fill the subset table in botton up manner 
	for (int i = 1; i <= n; i++) 
	{ 
	for (int j = 1; j <= sum; j++) 
	{ 
		if(j<set[i-1]) 
		subset[i][j] = subset[i-1][j]; 
		if (j >= set[i-1]) 
		subset[i][j] = subset[i-1][j] || 
								subset[i - 1][j-set[i-1]]; 
	} 
	} 

	/* // uncomment this code to print table 
	for (int i = 0; i <= n; i++) 
	{ 
	for (int j = 0; j <= sum; j++) 
		printf ("%4d", subset[i][j]); 
	printf("\n"); 
	}*/

	return subset[n][sum]; 
} 

// Driver program to test above function 
int main() 
{ 
int set[] = {3, 34, 4, 12, 5, 2}; 
int sum = 9; 
int n = sizeof(set)/sizeof(set[0]); 
if (isSubsetSum(set, n, sum) == true) 
	printf("Found a subset with given sum"); 
else
	printf("No subset with given sum"); 
return 0; 
} 

------------------------------------------------------------------------------------------------------------------------------------------



