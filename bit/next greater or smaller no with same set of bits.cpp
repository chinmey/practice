Step 1: Flip rightmost non-trailing zero

1    1   0   1  1  0  1  1  1  1  1  1  0  0 ------ 13498
13  12  11  10  9  8  7  6  5  4  3  2  1  0

1    1   0   1  1  0  1  1  1  1  1  1  0  0
13  12  11  10  9  8  7  6  5  4  3  2  1  0
With this change, we have increased the number of 1s of n. We can shrink the number by rearranging all the bits to the right of bit p such that the 0s are on the left and the 1s are on the right. As we do this, we want to replace one of the 1s with a 0.

A relatively easy way of doing this is to count how many ones are to the right of p, clear all the bits from 0 until p, and then add back in c1-1 ones. Let c1 be the number of ones to the right of p and c0 be the number of zeros to the right of p.

Let’s walk through this with an example.

c1 ==> Number of ones to the right of p
c0 ==> Number of zeros to the right of p.
p = c0 + c1
Step 2: Clear bits to the right of p. From before, c0 = 2. c1 = 5. p = 7.

1    1   0   1  1  0  1  0  0  0  0  0  0  0
13  12  11  10  9  8  7  6  5  4  3  2  1  0
To clear these bits, we need to create a mask that is a sequence of ones, followed by p zeros. We can do this as follows:

// all zeros except for a 1 at position p.
a = 1 << p;

// all zeros, followed by p ones.
b = a - 1;

// all ones, followed by p zeros.
mask = ~b;

// clears rightmost p bits.
n = n & mask;

Or, more concisely, we do:
n &= ~((1 << p) - 1).
Step 3: Add one c1 – 1 ones.

1   1   0   1   1  0  1  0  0  0  1  1  1  1
13  12  11  10  9  8  7  6  5  4  3  2  1  0
To insert c1 – 1 ones on the right, we do the following:

// 0s with a 1 at position c1– 1
a = 1 << (c1 - 1);

// 0s with 1s at positions 0 through c1-1
b = a - 1;

// inserts 1s at positions 0 through c1-1
n = n | b;

Or, more concisely:
n | = (1 << (c1 - 1)) - 1;


int getbig(int n)
{

    int c=n;
    int c0=0,c1=0;
    while(c!=0 && (c&1==0))
    {

        c0++;
        c=c>>1;
    }
    while(c&1==1)
    {

        c1++;
        c=c>>1;
    }
    if(c0+c1==31||c0+c1==0)
        return -1;
    int p=c0+c1;
    n=n|(1<<p);
    int a=1<<p;
    int b=a-1;
    int mask=~b;
    n=n&mask;
    a=1<<c1-1;
    b=a-1;
    n=n|b;
    return n;
}


