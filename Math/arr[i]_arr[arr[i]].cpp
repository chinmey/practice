Rearrange a given array so that Arr[i] becomes Arr[Arr[i]] with O(1) extra space.


Input: arr[]  = {3, 2, 0, 1}
Output: arr[] = {1, 0, 3, 2}
Explanation: 
In the given array 
arr[arr[0]] is 1 so arr[0] in output array is 1
arr[arr[1]] is 0 so arr[1] in output array is 0
arr[arr[2]] is 3 so arr[2] in output array is 3
arr[arr[3]] is 2 so arr[3] in output array is 2



Approach: The array elements of the given array lies from 0 to n-1. Now an array element is needed that can store two different values at the same time. 
To achieve this increment every element at ith index is incremented by (arr[arr[i]] % n)*n.
After the increment operation of first step, every element holds both old values and new values. 
Old value can be obtained by arr[i]%n and a new value can be obtained by arr[i]/n.

How this can be achieved?
Let’s assume an element is a and another element is b, both the elements are less than n. 
So if an element a is incremented by b*n. So the element becomes a + b*n so when a + b*n is divided by n then the value is b and a + b*n % n is a.


 
  
// The function to rearrange an array  
// in-place so that arr[i] becomes arr[arr[i]]. 
void rearrange(int arr[], int n) 
{ 
    // First step: Increase all values by (arr[arr[i]]%n)*n 
    for (int i=0; i < n; i++) 
        arr[i] += (arr[arr[i]]%n)*n; 
  
    // Second Step: Divide all values by n 
    for (int i=0; i<n; i++) 
        arr[i] /= n; 
} 


-------------------------------------------------------------------------------

int Solution::gcd(int A, int B) {
   if(A==0) return B;
   if(B==0) return A;
    
    if(A==B) return A;
    if(A>B)
    return gcd(A-B,B);
    return gcd(A,B-A);
}

