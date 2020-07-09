/* Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x. The same repeated number may be chosen from arr[] unlimited number of times. Elements in a combination (a1, a2, �, ak) must be printed in non-descending order. (ie, a1 <= a2 <= � <= ak).
The combinations themselves must be sorted in ascending order, i.e., the combination with smallest first element should be printed first. If there is no combination possible the print "Empty" (without quotes).

Examples:

Input : arr[] = 2, 4, 6, 8
            x = 8
Output : [2, 2, 2, 2]
         [2, 2, 4]
         [2, 6]
         [4, 4]
         [8]
*/
/* solution-- we need to basically perform a dfs recursion in which we simulate taking and not taking elements

1. first we take a number
2. perform a search for target
3. we don't take number

*/
#include<bits/stdc++.h>
using namespace std;

void findnumbers(vector<int>&arr,int sum,int i,vector<vector<int> > &res,vector<int> &cur)
{
   if(sum==0)
   {
       res.push_back(cur);
       return;
   }
   if(sum <0)
    return;

   while(i < arr.size() && sum - arr[i] >=0 )
   {

       cur.push_back(arr[i]);

       findnumbers(arr,sum-arr[i],i,res,cur);
       i++;

       cur.pop_back();
   }

}

vector<vector<int> > combinationSum(vector<int> &arr,int sum)
{
    vector<int> cur;
    vector<vector<int>> res;

    sort(arr.begin(),arr.end());

      arr.erase(unique(arr.begin(), arr.end()), arr.end()); // remove duplicates



    findnumbers(arr,sum,0,res,cur);
    return res;
}
int main()
{

    vector<int> arr;
    arr.push_back(2);
    arr.push_back(4);
    arr.push_back(6);
    arr.push_back(8);
    int n = arr.size();

    int sum = 8; // set value of sum
    vector<vector<int> > res = combinationSum(arr, sum);

    // If result is empty, then
    if (res.size() == 0)
    {
        cout << "Emptyn";
        return 0;
    }

    // Print all combinations stored in res.
    for (int i = 0; i < res.size(); i++)
    {
        if (res[i].size() > 0)
        {
            cout << " ( ";
            for (int j = 0; j < res[i].size(); j++)
                cout << res[i][j] << " ";
            cout << ")";
        }
    }
}
-------------------------------------------------------------------------------------------------------------------------------

// combination sum 2 
/*Given an array of integers A and a sum B, find all unique combinations in A where the sum is equal to B.

ach number in A may only be used once in the combination.

Note:
   All numbers will be positive integers.
   Elements in a combination (a1, a2, … , ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
   The combinations themselves must be sorted in ascending order.
   If there is no combination possible the print "Empty" (without qoutes).
Example,
Given A = 10,1,2,7,6,1,5 and B(sum) 8,

A solution set is:

[1, 7]
[1, 2, 5]
[2, 6]
[1, 1, 6] */

/* basically i follow combination 1 soln but each time we do i+1*/

however this will create repetead soln so instead of res pass set<vector<int>>s and just do             for(auto &z:s) res.push_back(z); before submit
    
  /* check interview ypu have solved it there*/  

void findnumbers(vector<int>&arr,int sum,int i,vector<vector<int> > &res,vector<int> &cur)
{
   if(sum==0)
   {
       res.push_back(cur);
       return;
   }
   if(sum <0)
    return;
    
    if(i>=arr.size())
    return;

   while(i < arr.size() && sum - arr[i] >=0 )
   {

       cur.push_back(arr[i]);

       findnumbers(arr,sum-arr[i],i+1,res,cur);
       i++;

       cur.pop_back();
   }

}

---------------------------------------------------------------------------------------------------------------------------------

Given a string s, partition s such that every string of the partition is a palindrome. Return all possible palindrome partitioning of s.

Input  : s = "bcc"
Output : [["b", "c", "c"], ["b", "cc"]]

Input  : s = "geeks"
Output : [["g", "e", "e", "k", "s"], 
          ["g", "ee", "k", "s"]]
          
          
  bool ispal(string A,int l,int h)
{
    while(l<h)
    {
        if(A[l]!=A[h]) return false;
        l++;
        h--;
    }
    return true;
}
void allPalPartUtil(vector<vector<string> >&allPart, vector<string> &currPart,  
                   int start, int n, string str) 
{ 
    // If 'start' has reached len 
    if (start >= n) 
    { 
        allPart.push_back(currPart); 
        return; 
    } 
  
    // Pick all possible ending points for substrings 
    for (int i=start; i<n; i++) 
    { 
        // If substring str[start..i] is palindrome 
        if (ispal(str, start, i)) 
        { 
            // Add the substring to result 
            currPart.push_back(str.substr(start, i-start+1)); 
  
            // Recur for remaining remaining substring 
            allPalPartUtil(allPart, currPart, i+1, n, str); 
              
            // Remove substring str[start..i] from current  
            // partition 
            currPart.pop_back(); 
        } 
    } 
}
vector<vector<string> > Solution::partition(string str) {
    // Do not write main() function.
    // Do not read input, instead use the arguments to the function.
    // Do not print the output, instead return values as specified
    // Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

    
    int n = str.length(); 
  
    // To Store all palindromic partitions 
    vector<vector<string> > allPart; 
  
    // To store current palindromic partition 
    vector<string> currPart;  
  
    // Call recursive function to generate all partiions 
    // and store in allPart 
    allPalPartUtil(allPart, currPart, 0, n, str);
    
    return allPart;
}
        
