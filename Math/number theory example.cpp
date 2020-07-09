Given an integer n, return the number of trailing zeroes in n!.

n = 5
n! = 120 
Number of trailing zeros = 1
So, return 1


So if we count 5s in prime factors, we are done. How to count total number of 5s in prime factors of n!?
 A simple way is to calculate floor(n/5). For example, 7! has one 5, 10! has two 5s. It is done yet, there is one more thing to consider. 
 Numbers like 25, 125, etc have more than one 5. For example if we consider 28!, we get one extra 5 and number of 0s become 6.
  Handling this is simple, first divide n by 5 and remove all single 5s, 
then divide by 25 to remove extra 5s and so on. Following is the summarized formula for counting trailing 0s.

Trailing 0s in n! = Count of 5s in prime factors of n!
                  = floor(n/5) + floor(n/25) + floor(n/125) + ....
                  
// Function to return trailing  
// 0s in factorial of n 
int findTrailingZeros(int n) 
{ 
    // Initialize result 
    int count = 0; 
  
    // Keep dividing n by powers of  
    // 5 and update count 
    for (int i = 5; n / i >= 1; i *= 5) 
        count += n / i; 
  
    return count; 
} 
-----------------------------------------------------------------------------------------------------------------------
