// C++ program for to print all combination 
// of 4 elements in A[] with sum equal to X 
#include<bits/stdc++.h> 
using namespace std; 

/* Following function is needed 
for library function qsort(). */
int compare (const void *a, const void * b) 
{ 
	return ( *(int *)a - *(int *)b ); 
} 

/* A sorting based solution to print 
all combination of 4 elements in A[] 
with sum equal to X */
void find4Numbers(int A[], int n, int X) 
{ 
	int l, r; 

	// Sort the array in increasing 
	// order, using library function 
	// for quick sort 
	qsort (A, n, sizeof(A[0]), compare); 

	/* Now fix the first 2 elements 
	one by one and find 
	the other two elements */
	for (int i = 0; i < n-3; i++) 
	{ 
		for (int j = i+1; j < n-2; j++) 
		{ 
			// Initialize two variables as 
			// indexes of the first and last 
			// elements in the remaining elements 
			l = j + 1; 
			r = n-1; 

			// To find the remaining two 
			// elements, move the index 
			// variables (l & r) toward each other. 
			while (l < r) 
			{ 
				if( A[i] + A[j] + A[l] + A[r] == X) 
				{ 
					cout << A[i]<<", " << A[j] << 
						", " << A[l] << ", " << A[r]; 
					int leftvalue=A[l];
					while(l<n && A[l]==leftvalue) l++; // handles duplicates
					int rightvalue=A[r];
						while(r>l && A[r]==rightvalue) r--;
					
				} 
				else if (A[i] + A[j] + A[l] + A[r] < X) 
					l++; 
				else // A[i] + A[j] + A[l] + A[r] > X 
					r--; 
			} // end of while 
			while(j<n-2 && A[j+1]==A[j]) j++;
		}// end of inner for loop 
		 while(i<n-3 && A[i+1]==A[i])i++;
	} // end of outer for loop 
} 

/* Driver code */
int main() 
{ 
	int A[] = {-1, 0, 0, 1, -2, 2}; 
	int X = 0; 
	int n = sizeof(A) / sizeof(A[0]); 
	find4Numbers(A, n, X); 
	return 0; 
} 
-----------------------------------------------------------------------------------------------------(hash table)

// C++ program to find if there exist 4 elements 
// with given sum 
vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    
    int n=A.size(),i,j;
    unordered_map<int,vector<pair<int,int>>>mp;
    
    sort(A.begin(),A.end());
    vector<vector<int>>res;
    set<vector<int>>sss;/* important technique removes duplicates from answer*/
    
    for(i=0;i<n-1;i++)
    {
        for(j=i+1;j<n;j++)
        {
            int sum=A[i]+A[j];
            
            if(mp.find(B-sum)!=mp.end())
            {
                auto x=mp.find(B-sum);
                vector<pair<int,int>>v=x->second;
                for(int k=0;k<x->second.size();k++)
                {
                    pair<int,int>p=v[k];
                    
                    if(p.first!=i && p.first!=j && p.second!=i && p.second!=j)
                    {
                        vector<int>ans;
                        ans.push_back(A[i]);
                        ans.push_back(A[j]);
                        ans.push_back(A[p.first]);     or     vector<int>ans= {A[i],A[j],A[p.first],A[p.second]};
                        ans.push_back(A[p.second]);
                        sort(ans.begin(),ans.end());
                        sss.insert(ans);
                    }
                }
            }
            mp[sum].push_back(make_pair(i,j));
        }
          for(auto &z:sss)
    res.push_back(z);
    return res;



