
/*Median can be defined as the element in the data set which separates the higher half of the data sample from the lower half.
In other words we can get the median element as, when the input size is odd, we take the middle element of sorted data. If the input size is even, we pick average of middle two elements in sorted stream.
Input: 5 10 15
Output: 5
        7.5
        10

/*Two heaps: o(logn)
Max heap: Smaller half
Min heap: Larger half
Size diff <= 1 --> same size: average of the top elements of the two heaps. Total even
               --> different size: The top element of the heap with larger size. Total odd

addNum o(logn)
    Push: o(logn)
    optional rebalance: O(logn)
findMedian o(1)*/

 basically we need to maintain middle of array toh lower half ko max heap jo ki uska highest dega aur
 upper half ko min heap  jo uska minimum de dega

#include<bits/stdc++.h>
using namespace std;

priority_queue<int> maxq;
priority_queue<int,vector<int>,greater<int>>minq;

void add(int k)
{
    // adding the  number

    if(maxq.empty()==true||k<maxq.top())
        maxq.push(k);
    else
        minq.push(k);
    // maintaining diff as less than 1

    if(maxq.size()==minq.size()+2)
    {
        minq.push(maxq.top());
        maxq.pop();
    }
    else  if(maxq.size()+2==minq.size())
    {
        maxq.push(minq.top());
        minq.pop();
    }
}
float median()
{
    if(maxq.empty()==true)
        return 0;
    else if(maxq.size()==minq.size())
        return (maxq.top()+minq.top()/2);
    else if (maxq.size() == minq.size() + 1) {
            return maxq.top();
        } else {
            return minq.top();
}
