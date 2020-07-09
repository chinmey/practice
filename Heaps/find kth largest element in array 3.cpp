/* first approach would be to sort an array and give it kth largest term time is O(nlogn)
if this does not work we would need minheap

Minheap method  time is O(n-k *logn)

-- build a minheap with first k elements arr[0] to arr[k-1]
---- now for i=k to i=size-1 check with root if greater than root than make it root and call heapify
---- at end root is kth largest element */
  #include<bits/stdc++.h>
  using namespace std;
void minHeapify(int a[], int size, int i)
{
    int l = 2*i;
    int r = 2*i+1;
    int smallest = i;
    if(l<size && a[l]<a[smallest])
        smallest = l;
    if(r<size && a[r]<a[smallest])
        smallest = r;
    if(smallest!=i)
    {
        swap(a[i],a[smallest]);
        minHeapify(a,size,smallest);
    }
     
}
  
  
void buildMinHeap(int a[], int size) {
    for(int i=size/2;i>=0;i--)
        minHeapify(a,size,i);
         
}
  
  
int kthLargest(int a[], int size, int k)
{
    int minHeap[k];
    int i;
    for(i=0;i<k;i++)
        minHeap[i] = a[i];
    buildMinHeap(minHeap,k);
    for(i=k;i<size;i++)
    {
        if(a[i]>minHeap[0])
        {
            minHeap[0]=a[i];
            minHeapify(minHeap,k,0);
        }
    }
    return minHeap[0];
}
  
  
int main() {
    int a[] = {16,7,18,4,12,9,5,1};
    int size = sizeof(a)/sizeof(a[0]);
    int k = 3;
    printf("%d ",kthLargest(a,size,k));
    return 0;
}
-------------------------------------------------------------------

kth largest element in bst with no extra space 

// A function to find k'th largest element in a given tree. 
void kthLargestUtil(Node *root, int k, int &c) 
{ 
    // Base cases, the second condition is important to 
    // avoid unnecessary recursive calls 
    if (root == NULL || c >= k) 
        return; 
  
    // Follow reverse inorder traversal so that the 
    // largest element is visited first 
    kthLargestUtil(root->right, k, c); 
  
    // Increment count of visited nodes 
    c++; 
  
    // If c becomes k now, then this is the k'th largest  
    if (c == k) 
    { 
        cout << "K'th largest element is "
             << root->key << endl; 
        return; 
    } 
  
    // Recur for left subtree 
    kthLargestUtil(root->left, k, c); 
} 
  
// Function to find k'th largest element 
void kthLargest(Node *root, int k) 
{ 
    // Initialize count of nodes visited as 0 
    int c = 0; 
  
    // Note that c is passed by reference 
   

