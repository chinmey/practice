if we observe bit from rightmost side the bit at ith position gets flipeed after  2^i position

    0=0000
    1=0001
    2=0010
    3=0011
    4=0100
at i=1 gets flipped at 2^i which is 2 ,similarly at i=2 get flipped at 4 we would use this

int count(int n)
{

    int ans=0;
    int i=0;
    while((1<<i)<=n) // while n is greater than or equal to 2^i
    {
       bool k=0;
       int change=(1<<i);
       for(int j=0;j<=n;j++)
       {
           ans=ans+k;
           if(change==1)
           {

            k=!k; // when change is 1 we flip the bit
           change=(1<<i); // again set change to 2^i
           }
           else
            change--;

       }
       i++;
    }
    return ans;
}

