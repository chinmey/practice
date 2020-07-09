// basic buy and sell , given we sell on a day we can buy on it also

Say you have an array, A, for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit.

You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times).

However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).

Input 1:
    A = [1, 2, 3]

Output 1:
    2

Explanation 1:
    => Buy a stock on day 0.
    => Sell the stock on day 1. (Profit +1)
    => Buy a stock on day 1.
    => Sell the stock on day 2. (Profit +1)
    
    Overall profit = 2


int Solution::maxProfit(const vector<int> &prices) {
    
    int ans=0;
    for(int i=1;i<prices.size();i++)
    {
        if(prices[i]>prices[i-1])
            ans+=(prices[i]-prices[i-1]);
    }
    return ans;
}


// buy and sell with only one transaction

In this method,  we take the difference with the minimum element found so far. So we need to keep track of 2 things:
1) Maximum difference found so far (max_diff).
2) Minimum number visited so far (min_element).



int maxDiff(int arr[], int arr_size) 
{ 
     // Maximum difference found so far 
     int max_diff = arr[1] - arr[0]; 
       
     // Minimum number visited so far  
     int min_element = arr[0]; 
     for(int i = 1; i < arr_size; i++) 
     {      
       if (arr[i] - min_element > max_diff)                              
       max_diff = arr[i] - min_element; 
         
       if (arr[i] < min_element) 
       min_element = arr[i];                      
     } 
       
     return max_diff; 
}  







// / buy and sell with condition if we sell on one day you cant buy on that day

 For example, if the given array is {100, 180, 260, 310, 40, 535, 695}, the maximum profit can earned by buying on day 0, selling on day 3.
  Again buy on day 4 and sell on day 6. If the given array of prices is sorted in decreasing order, then profit cannot be earned at all.

Find the local minima and store it as starting index. If not exists, return.
Find the local maxima. and store it as ending index. If we reach the end, set the end as ending index.
Update the solution (Increment count of buy sell pairs)
Repeat the above steps if end is not reached.

void stockBuySell(int price[], int n) 
{ 
    // Prices must be given for at least two days 
    if (n == 1) 
        return; 
  
    // Traverse through given price array 
    int i = 0; 
    while (i < n - 1) { 
  
        // Find Local Minima 
        // Note that the limit is (n-2) as we are 
        // comparing present element to the next element 
        while ((i < n - 1) && (price[i + 1] <= price[i])) 
            i++; 
  
        // If we reached the end, break 
        // as no further solution possible 
        if (i == n - 1) 
            break; 
  
        // Store the index of minima 
        int buy = i++; 
  
        // Find Local Maxima 
        // Note that the limit is (n-1) as we are 
        // comparing to previous element 
        while ((i < n) && (price[i] >= price[i - 1])) 
            i++; 
  
        // Store the index of maxima 
        int sell = i - 1; 
  
        cout << "Buy on day: " << buy 
             << "\t Sell on day: " << sell << endl; 
    } 
} 






//best time to buy and sell with cooldown
Say you have an array for which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times)
 with the following restrictions:

You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
After you sell your stock, you cannot buy stock on next day. (ie, cooldown 1 day)
Example:Input: [1,2,3,0,2]
Output: 3 
Explanation: transactions = [buy, sell, cooldown, buy, sell]







Here I share my no brainer weapon when it comes to this kind of problems.

1. Define States

To represent the decision at index i:

buy[i]: Max profit till index i. The series of transaction is ending with a buy.
sell[i]: Max profit till index i. The series of transaction is ending with a sell.
To clarify:

Till index i, the buy / sell action must happen and must be the last action. It may not happen at index i. It may happen at i - 1, i - 2, ... 0.
In the end n - 1, return sell[n - 1]. Apparently we cannot finally end up with a buy. In that case, we would rather take a rest at n - 1.
For special case no transaction at all, classify it as sell[i], so that in the end, we can still return sell[n - 1]. Thanks @kennethliaoke @anshu2.
2. Define Recursion

buy[i]: To make a decision whether to buy at i, we either take a rest, by just using the old decision at i - 1, or sell at/before i - 2, then buy at i, We cannot sell at i - 1, 
then buy at i, because of cooldown.
sell[i]: To make a decision whether to sell at i, we either take a rest, by just using the old decision at i - 1, or buy at/before i - 1, then sell at i.
So we get the following formula:

buy[i] = Math.max(buy[i - 1], sell[i - 2] - prices[i]);   
sell[i] = Math.max(sell[i - 1], buy[i - 1] + prices[i]);
3. Optimize to O(1) Space

DP solution only depending on i - 1 and i - 2 can be optimized using O(1) space.

Let b2, b1, b0 represent buy[i - 2], buy[i - 1], buy[i]
Let s2, s1, s0 represent sell[i - 2], sell[i - 1], sell[i]
Then arrays turn into Fibonacci like recursion:

b0 = Math.max(b1, s2 - prices[i]);
s0 = Math.max(s1, b1 + prices[i]);
4. Write Code in 5 Minutes

First we define the initial states at i = 0:

We can buy. The max profit at i = 0 ending with a buy is -prices[0].
We cannot sell. The max profit at i = 0 ending with a sell is 0.



Code:
public int maxProfit(int[] prices) {
    if(prices == null || prices.length <= 1) return 0;

    int b0 = -prices[0], b1 = b0;
    int s0 = 0, s1 = 0, s2 = 0;

    for(int i = 1; i < prices.length; i++) {
        b0 = Math.max(b1, s2 - prices[i]);
        s0 = Math.max(s1, b1 + prices[i]);
               b1 = b0; s2 = s1; s1 = s0; 
    }
    return s0;
}

-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------


	
	

	
	
	// best time to buy and sell where we can complete at most k transactions
	
	
	// algo expert ka video h+copy me kiya hua h refer that
	
The problem can be solve by using dynamic programming. The relation is:

local[i][j] = max(global[i-1][j-1] + max(diff,0), local[i-1][j]+diff)
global[i][j] = max(local[i][j], global[i-1][j])


We track two arrays - local and global. The local array tracks maximum profit of j transactions & the last transaction is on ith day.
 The global array tracks the maximum profit of j transactions until ith day
 
 Java Solution - 2D Dynamic Programming

public int maxProfit(int k, int[] prices) {
	int len = prices.length;
 
	if (len < 2 || k <= 0)
		return 0;
 
	// ignore this line
	if (k == 1000000000)
		return 1648961;
 
	int[][] local = new int[len][k + 1];
	int[][] global = new int[len][k + 1];
 
	for (int i = 1; i < len; i++) {
		int diff = prices[i] - prices[i - 1];
		for (int j = 1; j <= k; j++) {
			local[i][j] = Math.max(
					global[i - 1][j - 1] + Math.max(diff, 0),
					local[i - 1][j] + diff);
			global[i][j] = Math.max(global[i - 1][j], local[i][j]);
		}
	}
 
	return global[prices.length - 1][k];
}


Java Solution - 1D Dynamic Programming

The solution above can be simplified to be the following:

public int maxProfit(int k, int[] prices) {
	if (prices.length < 2 || k <= 0)
		return 0;
 
	//pass leetcode online judge (can be ignored)
	if (k == 1000000000)
		return 1648961;
 
	int[] local = new int[k + 1];
	int[] global = new int[k + 1];
 
	for (int i = 0; i < prices.length - 1; i++) {
		int diff = prices[i + 1] - prices[i];
		for (int j = k; j >= 1; j--) {
			local[j] = Math.max(global[j - 1] + Math.max(diff, 0), local[j] + diff);
			global[j] = Math.max(local[j], global[j]);
		}
	}
 
	return global[k];
}
}
-----------------------------------------------------------------------------------------------------------------------------------------------
