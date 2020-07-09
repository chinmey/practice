#include <bits/stdc++.h>
using namespace std;

/* Takes pointer to result and two numbers as
    arguments. If there is no overflow, the function
    places the resultant = sum a+b in “result” and
    returns 0, otherwise it returns -1 */
int addOvf(int* result, int a, int b)
{
    *result = a + b;
    if(a > 0 && b > 0 && *result < 0)
        return -1;
    if(a < 0 && b < 0 && *result > 0)
        return -1;
    return 0;
}

// Driver code
int main()
{
    int *res = new int[(sizeof(int))];
    int x = 2147483640;
    int y = 10;

    cout<<addOvf(res, x, y);

    cout<<"\n"<<*res;
    return 0;
}
---------------------------------------------------------------------------------------------------------------

multiply two number without any * / etc

public : int multiply(int x, int y)
{
    /* 0 multiplied with anything gives 0 */
    if(y == 0)
    return 0;

    /* Add x one by one */
    if(y > 0 )
    return (x + multiply(x, y-1));

    /* the case where y is negative */
    if(y < 0 )
    return -multiply(x, -y);
}
};
OR OR OR OR OR

#include <iostream>
using namespace std;

// A method to multiply two numbers using Russian Peasant method
unsigned int russianPeasant(unsigned int a, unsigned int b)
{
    int res = 0;  // initialize result

    // While second number doesn't become 1
    while (b > 0)
    {
         // If second number becomes odd, add the first number to result
         if (b & 1)
             res = res + a;

         // Double the first number and halve the second number
         a = a << 1;
         b = b >> 1;
     }
     return res;
}
