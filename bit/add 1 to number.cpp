Input:  12
Output: 13

Input:  6
Output: 7

To add 1 to a number x (say 0011000111), flip all the bits after the rightmost 0 bit (we get 0011000000).
 Finally, flip the rightmost 0 bit also (we get 0011001000) to get the answer.
int addOne(int x)
{
    int m = 1;

     Flip all the set bits
     until we find a 0
    while( x & m )
    {
        x = x ^ m;
        m <<= 1;
    }

    flip the rightmost 0 bit
    x = x ^ m;
    return x;
}

2 method--return (~(~x));

-------------------------------------------------------------------------
to multiply a number with 3.5  1. We can get x*3.5 by adding 2*x, x and x/2. To calculate 2*x, left shift x by 1 and to calculate x/2, right shift x by 2.

 return (x<<1) + x + (x>>1);
