/*contiguos subarray with maximum sum*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
        int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    int sum=arr[0] ;
	    int globalsum=arr[0] ;

	    for(int i=1;i<n;i++)
	    {
	       sum =max(sum+arr[i],arr[i]);
	        if(sum>globalsum)
	        globalsum=sum;


	    }
	    cout<<globalsum;
	    return 0;
}
--------------------------------------------------------------------------------------
/* contiguos subarray with maximum product*/

// Function to return maximum product of a sub-array of given array
int maxProduct(int arr[], int n)
{
	// maintain two variables to store maximum and minimum product
	// ending at current index
	int max_ending = 0, min_ending = 0;

	// to store maximum product sub-array found so far
	int max_so_far = 0;

	// traverse the given array
	for (int i = 0; i < n; i++)
	{
		int temp = max_ending;

		// update maximum product ending at current index
		max_ending = max(arr[i], max(arr[i] * max_ending, arr[i] * min_ending));

		// update minimum product ending at current index
		min_ending = min(arr[i], min(arr[i] * temp, arr[i] * min_ending));

		max_so_far = max(max_so_far, max_ending);
	}

	// return maximum product
	return max_so_far;
}


