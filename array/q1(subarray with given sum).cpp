/*subarray with sum same as given*/
#include<bits/stdc++.h>
using namespace std;
int main()
{

   int arr[5]={1,3,5,2,4};
    int i=0,j=0,k,r=14,s=0,f=0;
    for(k=0;k<5;k++)
    {
        s=s+arr[k];
        while(s>r)
        {
            s=s-arr[i];
            i++;
        }
        if(s==r)
        {
            f=1;
              break;
        }

        j++;
    }
    if(f!=1)
        cout<<"-1";
    else
        cout<<"value of i and j"<<i<<j;
        return 0;
        
    
}
