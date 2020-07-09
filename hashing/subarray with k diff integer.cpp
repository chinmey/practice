Given an array arr[] of size N and an integer K. The task is to find the count of subarrays such that each subarray has exactly K distinct elements.

Input: arr[] = {2, 1, 2, 1, 6}, K = 2
Output: 7
{2, 1}, {1, 2}, {2, 1}, {1, 6}, {2, 1, 2},
{1, 2, 1} and {2, 1, 2, 1} are the only valid subarrays.

Approach: To directly count the subarrays with exactly K different integers is hard but to find the count of subarrays with at most K different integers is easy.
 So the idea is to find the count of subarrays with at most K different integers, let it be C(K), and the count of subarrays with at most (K – 1) different integers,
  let it be C(K – 1) and finally take their difference, C(K) – C(K – 1) which is the required answer.
Count of subarrays with at most K different elements can be easily calculated through the sliding window technique. 
The idea is to keep expanding the right boundary of the window till the count of distinct elements in the window is less than or equal to K and
 when the count of distinct elements inside the window becomes more than K, start shrinking the window from the left till the count becomes less than or equal to K.
  Also for every expansion, keep counting the subarrays as right – left + 1 where right and left are the boundaries of the current window.
  
  
  // Function to return the count of subarrays 
// with at most K distinct elements using 
// the sliding window technique 
int atMostK(int arr[], int n, int k) 
{ 
  
    // To store the result 
    int count = 0; 
  
    // Left boundary of window 
    int left = 0; 
  
    // Right boundary of window 
    int right = 0; 
  
    // Map to keep track of number of distinct 
    // elements in the current window 
    map<int,int> map; 
    // Loop to calculate the count 
    while (right < n) { 
  
        // Calculating the frequency of each 
        // element in the current window 
        if (map.find(arr[right])==map.end()) 
            map[arr[right]]=0; 
        map[arr[right]]++; 
  
        // Shrinking the window from left if the 
        // count of distinct elements exceeds K 
        while (map.size() > k) { 
            map[arr[left]]= map[arr[left]] - 1; 
            if (map[arr[left]] == 0) 
                map.erase(arr[left]); 
            left++; 
        } 
  
        // Adding the count of subarrays with at most 
        // K distinct elements in the current window 
        count += right - left + 1; 
        right++; 
    } 
    return count; 
} 
  
// Function to return the count of subarrays 
// with exactly K distinct elements 
int exactlyK(int arr[], int n, int k) 
{ 
  
    // Count of subarrays with exactly k distinct 
    // elements is equal to the difference of the 
    // count of subarrays with at most K distinct 
    // elements and the count of subararys with 
    // at most (K - 1) distinct elements 
    return (atMostK(arr, n, k) - atMostK(arr, n, k - 1)); 
} 
  
