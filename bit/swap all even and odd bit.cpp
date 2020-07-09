Given an unsigned integer, swap all odd bits with even bits. For example,
if the given number is 23 (00010111), it should be converted to 43 (00101011).

---------------------------------------------------------

method 1 (khud ka)
	    int n;
	    cin>>n;
	    int c[64]={0};
	       int i=0;
	    while(n)
	    {

	        c[i]=c[i]+n&1;
	        i++;
	        n=n>>1;

	    }

	    for(i=0;i<64;i++)
	    {
	        if(i%2==0)
	        {
	            int t=c[i];
	            c[i]=c[i+1];
	            c[i+1]=t;
	        }
	    }

	    int ans=0;
	    int p=1;
	    for(i=0;i<64;i++)
	    {
	        ans=ans+p*c[i];
	        p=p<<1;
	    }
	    cout<<ans<<endl;
	}
	return 0;
-----------------------------------------------------------------------------------------------------

method 2 ----gfg
Let the input number be x
1) Get all even bits of x by doing bitwise and of x with 0xAAAAAAAA. The number 0xAAAAAAAA is a 32 bit number with all even bits set as 1 and all odd bits as 0.
2) Get all odd bits of x by doing bitwise and of x with 0x55555555. The number 0x55555555 is a 32 bit number with all odd bits set as 1 and all even bits as 0.
3) Right shift all even bits.
4) Left shift all odd bits.
5) Combine new even and odd bits and return.

#include <bits/stdc++.h>
using namespace std;

// Function to swap even
// and odd bits
unsigned int swapBits(unsigned int x)
{
    // Get all even bits of x
    unsigned int even_bits = x & 0xAAAAAAAA;

    // Get all odd bits of x
    unsigned int odd_bits = x & 0x55555555;

    even_bits >>= 1; // Right shift even bits
    odd_bits <<= 1; // Left shift odd bits

    return (even_bits | odd_bits); // Combine even and odd bits
}

// Driver code
int main()
{
    unsigned int x = 23; // 00010111

    // Output is 43 (00101011)
    cout<<swapBits(x);

    return 0;
}

