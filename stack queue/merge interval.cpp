Merge Overlapping Intervals
Given a set of time intervals in any order, merge all overlapping intervals into one and output the result which should have only mutually exclusive intervals. Let the intervals be represented as pairs of integers for simplicity.
For example, let the given set of intervals be {{1,3}, {2,4}, {5,7}, {6,8} }. The intervals {1,3} and {2,4} overlap with each other, so they should be merged 
and become {1, 4}. Similarly {5, 7} and {6, 8} should be merged and 
become {5, 8}


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 
 bool cmp(Interval i1,Interval i2)
 {
     return i1.start<i2.start;
 }
vector<Interval> Solution::merge(vector<Interval> &A) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    int n=A.size();
    
    sort(A.begin(),A.end(),cmp);
    
     stack<Interval> s; 
  
    
  
    
    s.push(A[0]); 
     for (int i = 1 ; i < n; i++) 
    { 
        
        Interval top = s.top(); 
  
        
        if (top.end < A[i].start) 
            s.push(A[i]); 
  
        
        else if (top.end < A[i].end) 
        { 
            top.end = A[i].end; 
            s.pop(); 
            s.push(top); 
        } 
    } 
    
    vector<Interval>v;
    int k=0;
    
     while (!s.empty()) 
    { 
        Interval t = s.top(); 
        v.push_back(t);
        s.pop(); 
        
    } 
    
