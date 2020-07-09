Given the string s, return the size of the longest substring containing each vowel an even number of times.
 That is, 'a', 'e', 'i', 'o', and 'u' must appear an even number of times.


 Input: s = "leetcodeisgreat"
Output: 5
Explanation: The longest substring is "leetc" which contains two e's.




Intuition
We do not need to know the exact count, we just need a flag indicating whether a vowel is even or odd.
So, we can track the status of each vowel using a bit mask. Since we only have 5 vowels in the English alphabet,
 we will have 32 possible combinations.

Now, if our mask is zero, then our string contains only even vowels. Also, if a mask is the same for indexes i and j,
the mask for substring [i +1, j] must be zero. Therefore, substring [i +1, j] also contains even vowels only.

Algorithm
As we go through our string, we update mask, and track the smallest index for each mask combination.
If we encounter the same mask later in the string, that means the string between smallest (exclusive) and current (inclusive) index
 meets the problem criteria.

 static constexpr char c_m[26] = {1,0,0,0,2,0,0,0,4,0,0,0,0,0,8,0,0,0,0,0,16,0,0,0,0,0};
int findTheLongestSubstring(string s) {
    int mask = 0, res = 0;
    vector<int> m(32, -1);
    for (int i = 0; i < s.size(); ++i) {
        mask ^= c_m[s[i] - 'a'];
        if (mask != 0 && m[mask] == -1)
            m[mask] = i;
        res = max(res, i - m[mask]);
    }
    return res;
}

for ex leetcodeisgreat=[0,2,0,0,0,16,16,18,26,26,26,26,24,25,25] ans==5(leetc)
