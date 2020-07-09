Implement wildcard pattern matching with support for ‘?’ and ‘*’ for strings string and pattern. pattern may have * and ?

see tushar roy video for ease

’?’ : Matches any single character.
‘*’ : Matches any sequence of characters (including the empty sequence).

bool strmatch(char str[], char pattern[], 
              int n, int m) 
{ 
    // empty pattern can only match with 
    // empty string 
    if (m == 0) 
        return (n == 0); 
  
    // lookup table for storing results of 
    // subproblems 
    bool lookup[n + 1][m + 1]; 
  
    // initailze lookup table to false 
    memset(lookup, false, sizeof(lookup)); 
  
    // empty pattern can match with empty string 
    lookup[0][0] = true; 
  
    // Only '*' can match with empty string 
    for (int j = 1; j <= m; j++) 
        if (pattern[j - 1] == '*') 
            lookup[0][j] = lookup[0][j - 1]; 
  
    // fill the table in bottom-up fashion 
    for (int i = 1; i <= n; i++) 
    { 
        for (int j = 1; j <= m; j++) 
        { 
            // Two cases if we see a '*' 
            // a) We ignore ‘*’ character and move 
            //    to next  character in the pattern, 
            //     i.e., ‘*’ indicates an empty sequence. 
            // b) '*' character matches with ith 
            //     character in input 
            if (pattern[j - 1] == '*') 
                lookup[i][j] = lookup[i][j - 1] || 
                               lookup[i - 1][j]; 
  
            // Current characters are considered as 
            // matching in two cases 
            // (a) current character of pattern is '?' 
            // (b) characters actually match 
            else if (pattern[j - 1] == '?' || 
                    str[i - 1] == pattern[j - 1]) 
                lookup[i][j] = lookup[i - 1][j - 1]; 
  
            // If characters don't match 
            else lookup[i][j] = false; 
        } 
    } 
  
    return lookup[n][m]; 
} 
