void QueueStack :: push(int x)
{
  q1.push(x);
}
/*The method pop which return the element poped out of the stack*/
int QueueStack :: pop()
{
    if(q1.empty())
    return -1;
    int size=1;

    while(q1.size()!=size){
        int d=q1.front();
        q1.pop();
        q2.push(d);
    }
    int c=q1.front();
    q1.pop();
    swap(q1,q2);
    return c;



}
example : push 1,2,3 ---> q1:1 2 3  q2:empty
          pop        --->  q2: 1 2    q1 3
                         pop 3 and swap q1 q2
