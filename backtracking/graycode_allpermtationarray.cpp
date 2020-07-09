The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
	
	00 - 0
01 - 1
11 - 3
10 - 2


  
/* we have 2 choices for each of the n bits either we  
   can include i.e invert the bit or we can exclude the  
   bit i.e we can leave the number as it is. */
void grayCodeUtil(vector<int>& res, int n, int& num) 
{ 
    // base case when we run out bits to process 
    // we simply include it in gray code sequence. 
    if (n == 0) { 
        res.push_back(num); 
        return; 
    } 
  
    // ignore the bit. 
    grayCodeUtil(res, n - 1, num); 
  
    // invert the bit. 
    num = num ^ (1 << (n - 1)); 
    grayCodeUtil(res, n - 1, num); 
} 
  
// returns the vector containing the gray  
// code sequence of n bits. 
vector<int> grayCodes(int n) 
{ 
    vector<int> res; 
  
    // num is passed by reference to keep 
    // track of current code. 
    int num = 0; 
    grayCodeUtil(res, n, num); 
  
    return res; 
} 
-------------------------------------------------------------------------------------------------------------------------------

Given a collection of numbers, return all possible permutations.

[1,2,3]
[1,3,2]
[2,1,3] 
[2,3,1] 
[3,1,2] 
[3,2,1]

void ppermute(vector<vector<int>>&res,vector<int>cur, int l, int r)  
{  
    
    if (l == r)  
        {
            res.push_back(cur);
            return;
        }
    else
    {  
        
        for (int i = l; i <= r; i++)  
        {  
  
            
            swap(cur[l], cur[i]);  
  
            // Recursion called  
            ppermute(res,cur, l+1, r);  
  
            //backtrack  
            swap(cur[l], cur[i]);  
        }  
    }  
} 
vector<vector<int> > Solution::permute(vector<int> &A) {
    
    vector<vector<int>>res;
    vector<int>cur;
    
    cur=A;
    
    ppermute(res,cur,0,A.size()-1);
    return res;
}

