What is the time complexity of the following code :

    int a = 0;
    for (i = 0; i < N; i++) {
        for (j = N; j > i; j--) {
            a = a + i + j;
        }
    }

Total number of runs = N + (N - 1) + (N - 2) + ... 1 + 0

= N * (N + 1) / 2

= 1/2 * N^2 + 1/2 * N

O(N^2) times. 

----------------------------------------------------------------------------------------
int searchNumOccurrence(vector<int> &V, int k, int start, int end) {
    if (start > end) return 0;
    int mid = (start + end) / 2;
    if (V[mid] < k) return searchNumOccurrence(V, k, mid + 1, end);
    if (V[mid] > k) return searchNumOccurrence(V, k, start, mid - 1);
    return searchNumOccurrence(V, k, start, mid - 1) + 1 + searchNumOccurrence(V, k, mid + 1, end);
}

It might seem at the first look that the program is O(log N). 
However, the last case 

return searchNumOccurrence(V, k, start, mid - 1) + 1 + searchNumOccurrence(V, k, mid + 1, end);


is the bottleneck step. 
Assuming all the values in the array are the same, we get the following relation : 

T(N) = 2 * T(N/2) + constant
= 4 * T(N/4) + constant ( 2 * constant = another constant )
= 8 * T(N/8) + constant
…
= N * T(N/N) + constant
= N + constant
= O(N)
------------------------------------------------------------------------------------------------
int findMinPath(vector<vector<int> > &V, int r, int c) {
  int R = V.size();
  int C = V[0].size();
  if (r >= R || c >= C) return 100000000; // Infinity
  if (r == R - 1 && c == C - 1) return 0;
  return V[r][c] + min(findMinPath(V, r + 1, c), findMinPath(V, r, c + 1));
}


Note that in every function call, we end up making 2 calls.

So, the function calls ends up looking like a tree :

                   F(0,0)
                /          \ 
            F(0, 1)         F(1, 0)
             /    \         /       \ 
          F(0, 2)  F(1,1)  F(1, 1)  F(2, 0)
             ....
The function calls end up making a complete binary tree.

  Number of calls on Level 0 = 1
  Number of calls on Level 1 = 2
  Number of calls on Level 2 = 4
  ...
  Number of calls on level i = 2^i. 
Total number of calls = 1 + 2 + 4 + ... 2^i + ... 2^(M + N - 2)  
                      = O(2^(M + N))
------------------------------------------------------------------------------------------------------



