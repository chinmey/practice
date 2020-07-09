
/* get past very large answer problem*/
long int res;

do calculation normally
 return (int)(res%m);
 
 or
 int ans;
    ans=(int)((ans+(count*2LL*(n-count)))%1000000007);
-----------------------------------------------------------------------------------------------

We can multiply recursively to overcome the difficulty of overflow.
 To multiply a*b, first calculate a*b/2 then add it twice. For calculating a*b/2 calculate a*b/4 and so on (similar to log n exponentiation algorithm).
 
 
 // To compute (a * b) % mod
multiply(a,  b, mod)
1)  ll res = 0; // Initialize result
2)  a = a % mod.
3)  While (b > 0)
        a) If b is odd, then add 'a' to result.
               res = (res + a) % mod
        b) Multiply 'a' with 2
           a = (a * 2) % mod
        c) Divide 'b' by 2
           b = b/2  
4)  Return res 


// C++ program for modular multiplication without 
// any overflow 
#include<iostream> 
using namespace std; 

typedef long long int ll; 

// To compute (a * b) % mod 
ll mulmod(ll a, ll b, ll mod) 
{ 
	ll res = 0; // Initialize result 
	a = a % mod; 
	while (b > 0) 
	{ 
		// If b is odd, add 'a' to result 
		if (b % 2 == 1) 
			res = (res + a) % mod; 

		// Multiply 'a' with 2 
		a = (a * 2) % mod; 

		// Divide b by 2 
		b /= 2; 
	} 

	// Return result 
	return res % mod; 
} 

// Driver program 
int main() 
{ 
ll a = 9223372036854775807, b = 9223372036854775807; 
cout << mulmod(a, b, 100000000000); 
return 0; 
} 

/* power of a number*/

// C++ program to calculate pow(x,n) 
#include<iostream> 
using namespace std; 
class gfg 
{ 
	
/* Function to calculate x raised to the power y */
public: 
int power(int x, unsigned int y) 
{ 
	if (y == 0) 
		return 1; 
	else if (y % 2 == 0) 
		return power(x, y / 2) * power(x, y / 2); 
	else
		return x * power(x, y / 2) * power(x, y / 2); 
} 
}; 

/* Driver code */
int main() 
{ 
	gfg g; 
	int x = 2; 
	unsigned int y = 3; 

	cout << g.power(x, y); 
	return 0; 
} 

// This code is contributed by SoM15242 

