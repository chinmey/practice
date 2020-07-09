#include<bits/stdc++.h>
using namespace std;
int main()
{
     /*arr[]  = {9:00,  9:40, 9:50,  11:00, 15:00, 18:00}
    dep[]  = {9:10, 12:00, 11:20, 11:30, 19:00, 20:00}

All events sorted by time.
Total platforms at any time can be obtained by subtracting total
departures from total arrivals by that time.
 Time     Event Type     Total Platforms Needed at this Time
 9:00       Arrival                  1
 9:10       Departure                0
 9:40       Arrival                  1
 9:50       Arrival                  2
 11:00      Arrival                  3
 11:20      Departure                2
 11:30      Departure                1
 12:00      Departure                0
 15:00      Arrival                  1
 18:00      Arrival                  2
 19:00      Departure                1
 20:00      Departure                0

Minimum Platforms needed on railway station = Maximum platforms
                                              needed at any time */

     int arr[6]  = {900,  940, 950,  1100, 1500, 1800}    ;
     int  dep[6]  = {910, 1200, 1120, 1130, 1900, 2000}  ;
     sort(arr,arr+6);
     sort(dep,dep+6);
     int i=1,j=0,res=0,plat=1;

     while(i<6&&j<6)
     {
         if(arr[i]<=dep[j])
         {
             plat++;
             i++;
             if(res<plat)
                res=plat;
         }
         else{
            plat--;
            j++;
         }
     }
     cout<<res;



}
