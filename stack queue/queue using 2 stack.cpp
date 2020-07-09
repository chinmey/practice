void StackQueue :: push(int x)
 {
     s1.push(x);
 }

int StackQueue :: pop()
{


      if(s2.empty())
     {
         if(s1.empty())
      return -1;


          while(!s1.empty())
      {

          s2.push(s1.top());
          s1.pop();
      }

      }
      int d=s2.top();
      s2.pop();
      return d;


}
example : push 1,2,3 ---> q1:1 2 3  q2:empty
          pop        ----> q2: 3 2 1 now just do poping from 2
