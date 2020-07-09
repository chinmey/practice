#include<bits/stdc++.h>
using namespace std;  /*in heap  i-1/2 is parent and 2i+1 ans 2i+2 is childern*/
 vector<int> /*minheap*/ h;
void insertKey(int k)
{
    int i=h.size();
    h.push_back(k);
    while(i!=0&&h[i]<h[(i-1)/2])
    {
        swap(h[i],h[(i-1)/2]);
        i=(i-1)/2;
    }
/* i-1/2 gives parent*/
}
void show()
{
    for(int i=0;i<h.size();i++)
        cout<<h[i]<<"  ";
}

    void MinHeapify(int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int smallest = i;
    if (l < h.size() && h[l] < h[i])
        smallest = l;
    if (r < h.size()&& h[r] < h[smallest])
        smallest = r;
    if (smallest != i)
    {
        swap(h[i], h[smallest]);
        MinHeapify(smallest);
    }
}

 void build_minheap ()
    {
        for( int i = (h.size()-1)/2 ; i >= 0 ; i--)
        MinHeapify ( i);
    }

/* int extractmin()
 {
     if(h.size()==0)
     {
         cout<<"heap is empty";
         return 0;
     }
     if(h.size()==1)
     {
         int ans=h[0];
         vector<int> :: iterator it;
         it=h.begin();
         h.erase(it);
         return ans;
     }
     int ans=h[0];
     swap(h[0],h[h.size()-1]);
      vector<int> :: iterator it;
      int x=h.size()-1;
      it=h.begin()+x;
      h.erase(it);

    MinHeapify(0);
    return ans;

 }*/
 
 int extract()
{
    if(heap.size()==0)
    {
        cout<<"empty";
        return 0;
    }
    if(heap.size()==1)
    {
        int n=heap[0];
        heap.pop_back();
        return n;
    }
    int root=heap[0];
    swap(heap[0],heap[heap.size()-1]);
    heap.pop_back();
    build_max();
    return root;
}
 void decreaseKey(int i,int new_val)
 {
     h[i]=new_val;
     while(i!=0&&h[i]<h[(i-1)/2])
     {
         swap(h[i],h[(i-1)/2]);
          i=(i-1)/2;

     }

 }
 void deleteKey(int i)
{
    decreaseKey(i, INT_MIN);
    extractmin();
}


int main()
{


    h.push_back(10);
     h.push_back(9);
     h.push_back(8);
     h.push_back(5);
     h.push_back(4);
     h.push_back(2);
    build_minheap();


    int ans=extractmin();
    cout<<ans<<endl;
    show();


    show();




}
