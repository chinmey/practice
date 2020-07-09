Example:
Let n is stored using 8 bits. Left rotation of n = 11100101 by 3 makes n = 00101111 (Left shifted by 3 and first 3 bits are put back in last ). If n is stored using 16 bits or 32 bits then left rotation of n (000…11100101) becomes 00..0011100101000.
Right rotation of n = 11100101 by 3 makes n = 10111100 (Right shifted by 3 and last 3 bits are put back in first ) if n is stored using 8 bits. If n is stored using 16 bits or 32 bits then right rotation of n (000…11100101) by 3 becomes 101000..0011100.


#include<iostream>

using namespace std;
#define INT_BITS 32
class gfg
{

/*Function to left rotate n by d bits*/
public
int leftRotate(int n, unsigned int d)
{

    /* In n<<d, last d bits are 0. To
     put first 3 bits of n at
    last, do bitwise or of n<<d
    with n >>(INT_BITS - d) */
    return (n << d)|(n >> (INT_BITS - d));
}

/*Function to right rotate n by d bits*/
int rightRotate(int n, unsigned int d)
{
    /* In n>>d, first d bits are 0.
    To put last 3 bits of at
    first, do bitwise or of n>>d
    with n <<(INT_BITS - d) */
    return (n >> d)|(n << (INT_BITS - d));
}
};

/* Driver code*/
int main()
{
    gfg g;
    int n = 16;
    int d = 2;
    cout << "Left Rotation of " << n <<
            " by " << d << " is ";
    cout << g.leftRotate(n, d);
    cout << "\nRight Rotation of " << n <<
            " by " << d << " is ";
    cout << g.rightRotate(n, d);
    getchar();
}
-----------------------------------------------------------------
only number that occurs odd number of times

int getOddOccurrence(int ar[], int ar_size)
{
    int res = 0;
    for (int i = 0; i < ar_size; i++)
        res = res ^ ar[i];

    return res;
}
