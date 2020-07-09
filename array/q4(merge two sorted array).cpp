/*basically use merge sort algo*/

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int lc,rc;/*size of two given array*/

    cin>>lc>>rc;

    int l[lc],r[rc],a[lc+rc],i=0,j=0,k=0,q;
    for(q=0;q<lc;q++)
        cin>>l[q];
      for(q=0;q<rc;q++)
        cin>>r[q];

    while(i<lc&&j<rc)
    {
        if(l[i]<r[j])
            a[k++]=l[i++];
        else
            a[k++]=r[j++];
    }
    while(i<lc)
         a[k++]=l[i++];
    while(j<rc)
        a[k++]=r[j++];

     for(q=0;q<lc+rc;q++)
        cout<<a[q]<<" ";
}
