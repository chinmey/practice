Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.
The amount of petrol that every petrol pump has.
Distance from that petrol pump to the next petrol pump.
Calculate the first point from where a truck will be able to complete the circle (The truck will stop at each petrol pump and it has infinite capacity). 
Expected time complexity is O(n). Assume for 1-litre petrol, the truck can go 1 unit of distance.

For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}.
 The first point from where the truck can make a circular tour is 2nd petrol pump. Output should be “start = 1” (index of 2nd petrol pump).
 
 
 /* see tech dose video */
 
 An efficient approach is to use a Queue to store the current tour. We first enqueue first petrol pump to the queue, we keep enqueueing petrol pumps 
 till we either complete the tour, or the current amount of petrol becomes negative. 
 If the amount becomes negative, then we keep dequeuing petrol pumps until the queue becomes empty.
 
 // C++ program to find circular tour for a truck 
#include <bits/stdc++.h> 
using namespace std; 

// A petrol pump has petrol and distance to next petrol pump 
class petrolPump 
{ 
	public: 
	int petrol; 
	int distance; 
}; 

// The function returns starting point if there is a possible solution, 
// otherwise returns -1 
int printTour(petrolPump arr[], int n) 
{ 
	// Consider first petrol pump as a starting point 
	int start = 0; 
	int end = 1; 

	int curr_petrol = arr[start].petrol - arr[start].distance; 

	/* Run a loop while all petrol pumps are not visited. 
	And we have reached first petrol pump again with 0 or more petrol */
	while (end != start || curr_petrol < 0) 
	{ 
		// If curremt amount of petrol in truck becomes less than 0, then 
		// remove the starting petrol pump from tour 
		while (curr_petrol < 0 && start != end) 
		{ 
			// Remove starting petrol pump. Change start 
			curr_petrol -= arr[start].petrol - arr[start].distance; 
			start = (start + 1) % n; 

			// If 0 is being considered as start again, then there is no 
			// possible solution 
			if (start == 0) 
			return -1; 
		} 

		// Add a petrol pump to current tour 
		curr_petrol += arr[end].petrol - arr[end].distance; 

		end = (end + 1) % n; 
	} 

	// Return starting point 
	return start; 
} 

// Driver code 
int main() 
{ 
	petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}}; 

	int n = sizeof(arr)/sizeof(arr[0]); 
	int start = printTour(arr, n); 

	(start == -1)? cout<<"No solution": cout<<"Start = "<<start; 

	return 0; 
} 


// This code is contributed by rathbhupendra 

