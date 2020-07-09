/* since the input is in form of array there is no chance that all level except last are filled can be violated so we only need to check its heap property*/

#include<bits/stdc++.h>
using namespace std;

bool isHeap(int arr[], int i, int n)
{
// If a leaf node
if (2*i+2>n)
    return true;

// If an internal node and is greater than its children, and
// same is recursively true for the children
if (arr[i] >= arr[2*i + 1] && arr[i] >= arr[2*i + 2] &&
    isHeap(arr, 2*i + 1, n) && isHeap(arr, 2*i + 2, n))
    return true;

return false;
}
int main()
{

    int arr[] = {90, 15, 10, 7, 12, 2, 7, 3};
    int n = sizeof(arr) / sizeof(int);
     isHeap(arr, 0, n)? printf("Yes"): printf("No");

    return 0;
}
