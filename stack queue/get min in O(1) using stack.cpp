{
#include<bits/stdc++.h>
using namespace std;
class _stack{
stack<int> s;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int q;
       cin>>q;
        _stack *a = new _stack();
       while(q--){
       int qt;
       cin>>qt;
       if(qt==1)
       {
           //push
           int att;
           cin>>att;
           a->push(att);
       }
       else if(qt==2)
       {
           //pop
           cout<<a->pop()<<" ";
       }
       else if(qt==3)
       {
           //getMin
           cout<<a->getMin()<<" ";
       }
       }
       cout<<endl;
   }
}

}
/*This is a function problem.You only need to complete the function given below*/
/*
The structure of the class is as follows
class _stack{
stack<int> s;
stack<int> s2;
int minEle;
public :
    int getMin();
    int pop();
    void push(int);
};
*/
/*returns min element from stack*/
stack<int>s2;
int _stack :: getMin()
{
   if(s.empty())
   return -1;
   else
   return s2.top();
}
/*returns poped element from stack*/
int _stack ::pop()
{
  if(s.empty())
  return -1;
  else
  {
      int d=s.top();
      s.pop();
      if(d==s2.top())
      s2.pop();
      return d;
  }

}
/*push element x into the stack*/
void _stack::push(int x)
{

  s.push(x);
  if(s2.empty())
  s2.push(x);
  if(s2.top()>x)
  s2.push(x);



}
