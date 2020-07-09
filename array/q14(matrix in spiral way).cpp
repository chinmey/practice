/* for photo look at gfg
basically we need to follow first row,last colomn,last row ,first column throughout*/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int row,col,i,j;
    cin>>row>>col;
    int mat[row][col];

    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            cin>>mat[i][j];
    }
    int k=0,l=0,last_row=row-1,last_col=col-1;

    while(k<=last_row&&l<=last_col)
    {
        for(i=l;i<=last_row;i++)    /*FIRST ROW*/
            cout<<mat[k][i];
        k++;  /*first row is printed,so moving to next row*/

           for(i=k;i<=last_col;i++)  /*LAST COL*/
            cout<<mat[i][last_col];
        last_col--;

        if(k<=last_row)            /*LAST ROW*/
        {
            for(i=last_col;i>=l;i--)
                cout<<mat[last_row][i];
           last_row--;
        }
        if(l<=last_col)          /*FIRST COL*/
        {
            for(i=last_row;i>=k;i--)
                cout<<mat[i][l];
            l++;
        }

    }

}


