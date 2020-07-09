
find lps of string(lcs of string and reverse) and subtract it from string length/** better*/


#include<bits/stdc++.h>
using namespace std;
int minimum(char *str)
{
    int n=strlen(str);
    int  table[n][n];
     memset(table, 0, sizeof(table));

     int l,h,gap;
     for(gap=1;gap<n;gap++)
     {
         for(l=0,h=gap;h<n;l++,h++)
         {
             if(str[l]==str[h])
             {
                 table[l][h]=table[l+1][h-1];
             }
             else
             {
                 table[l][h]=min(table[l+1][h],table[l][h-1])+1;
             }
         }
     }
     return table[0][n-1];

}
int main()
{
    char str[] = "helppreanadkada";
    printf("\nLength is: %d\n", minimum( str ) );
    return 0;
}
