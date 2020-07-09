t. As we know that 2 < e < 3, so we should break every Integer into 2 or 3 only for maximum product.
Next thing is 6 = 3 + 3 = 2 + 2 + 2, but 3 * 3 > 2 * 2 * 2, that is every triplet of 2 can be replaced with tuple of 3 for maximum product,
 so we will keep breaking the number in terms of 3 only, until number remains as 4 or 2, which we will be broken into 2*2 (2*2 > 3*1) and 2 respectively
  and we will get our maximum product.
In short, procedure to get maximum product is as follows – Try to break integer in power of 3 only and when integer remains small (<5) then use brute force.

// C/C++ program to find maximum product by breaking 
// the Integer 
#include <bits/stdc++.h> 
using namespace std; 
// faster than 100% both cases
// method return x^a in log(a) time 
  int power(int a,int b)
    {
        if(b==0)
            return 1;
        int t=power(a,b/2);
        if(b%2==0)
            return t*t;
        return a*t*t;
    }

// Method returns maximum product obtained by 
// breaking N 
int breakInteger(int N) 
{ 
	// base case 2 = 1 + 1 
	if (N == 2) 
		return 1; 

	// base case 3 = 2 + 1 
	if (N == 3) 
		return 2; 

	int maxProduct; 

	// breaking based on mod with 3 
	switch (N % 3) 
	{ 
		// If divides evenly, then break into all 3 
		case 0: 
			maxProduct = power(3, N/3); 
			break; 

		// If division gives mod as 1, then break as 
		// 4 + power of 3 for remaining part 
		case 1: 
			maxProduct = 2 * 2 * power(3, (N/3) - 1); 
			break; 

		// If division gives mod as 2, then break as 
		// 2 + power of 3 for remaining part 
		case 2: 
			maxProduct = 2 * power(3, N/3); 
			break; 
	} 
	return maxProduct; 
} 

// Driver code to test above methods 
int main() 
{ 
	int maxProduct = breakInteger(10); 
	cout << maxProduct << endl; 
	return 0; 
} 


--------------------------------------------------------------------------------------------------------------------------

Input: n = 10
Output: 12
Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.

Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. 

  because every number can only be divided by 2, 3, 5, one way to look at the sequence is to split the sequence to three groups as below:
     (1) 1×2, 2×2, 3×2, 4×2, 5×2, …
     (2) 1×3, 2×3, 3×3, 4×3, 5×3, …
     (3) 1×5, 2×5, 3×5, 4×5, 5×5, …
     
         int nthUglyNumber(int n) {
        int ugly[n];
        if(n<7)
            return n;
        ugly[0]=1;
        int i=0;
        int j=0;
        int k=0;
        for(int c=1;c<n;c++)
        {
            ugly[c]=min(ugly[i]*2,min(3*ugly[j],5*ugly[k]));
            if(ugly[c]==2*ugly[i])
                i++;
             if(ugly[c]==3*ugly[j])
                j++;
            if(ugly[c]==5*ugly[k])
                k++;
        }
        return ugly[n-1];
    }

