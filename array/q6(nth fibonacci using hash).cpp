#include<bits/stdc++.h>
using namespace std;
int  fib(int n,map<int,int> &m)
{
  if(m.find(n)!=m.end())
    return m[n];
  m[n]=fib(n-1,m)+fib(n-2,m);
  return m[n];

}
int main()
{
    int n=5;
    map<int,int>m;
    m[1]=0;
    m[2]=1;

   int j= fib(n,m);

   cout<<j;
    return 0;

}

/*  best method iterative solution
int fib(int n)
{
    int last[2]={0,1};
    int count=3;
    while(count<=n)
    {
        int next=last[0]+last[1];
        last[0]=last[1];
        last[1]=next;
        count++;
    }
    return last[1];
}*/
