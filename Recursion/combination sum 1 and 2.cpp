8/* Given an array of positive integers arr[] and a sum x, find all unique combinations in arr[] where the sum is equal to x. The same repeated number may be chosen from arr[] unlimited number of times. Elements in a combination (a1, a2, �, ak) must be printed in non-descending order. (ie, a1 <= a2 <= � <= ak).
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

/* combination sum 2 differnt answer
*/

#include<bits/stdc++.h>
using namespace std;

bool solution(vector<int> &cur , map<int,int> &mp)
{
    unordered_map<int,int> haash;
    for(int i=0;i<cur.size();i++)
        haash[cur[i]]++;
    for (auto i : haash)
    {
        if(mp.find(i.first)!=mp.end())
        {
            if(i.second>mp[i.first])
                return false;
        }
    }
    return true;
}

void findnumbers(vector<int>&arr,int sum,int i,vector<vector<int>> &res,vector<int> &cur,map<int,int> &mp)
{
   if(sum==0&& solution(cur,mp))
   {
       res.push_back(cur);
       return;
   }
   if(sum <0)
    return;

   while( i<arr.size()&&sum-arr[i]>=0 )
   {

       cur.push_back(arr[i]);

       findnumbers(arr,sum-arr[i],i,res,cur,mp);
       i++;

       cur.pop_back();
   }


}

vector<vector<int>> combinationSum(vector<int> &arr,int sum)
{
    vector<int> cur;
    vector<vector<int>> res;

    sort(arr.begin(),arr.end());
    map<int,int>mp;

    for(int i=0;i<arr.size();i++)
        mp[arr[i]]++;



 arr.erase(unique(arr.begin(), arr.end()), arr.end()); // delete duplicates

    findnumbers(arr,sum,0,res,cur,mp);
    return res;
}
int main()
{

    vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(6);
    arr.push_back(7);
    arr.push_back(1);

    arr.push_back(5);
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

