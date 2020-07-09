 // we are given a array in which each no occurs thrice accept one

 // we take count fro each , then do count%3 eleminating all triple entries
 int find(int *a,int n)
 {

     int c[64]={0};  64 bit are used to represent a number
     for(int j=0;j<n;j++)
     {

         int i=0;
         int no=a[i];
         while(no>0)
         {
             c[i]=c[i]+no&1;
             i++;
             no=no>>1;
         }
     }
     int p=1;
     int ans=0;
     for(i=0;i<64;i++)
        c[i]=c[i]%3;
     ans=ans+c[i]*p;
     p=p<<1;

 }
