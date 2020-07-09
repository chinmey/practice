
/*this is an important technique while using two stack one can get next smaal and next greatre value too*/

Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.

The first call to next() will return the smallest number in BST. Calling next() again will return the next smallest number in the BST, and so on.

idea is to initaialse a stack will all left values while poppig add all values right to our current element
stack<TreeNode*>s;

void pushall(TreeNode *a)
{
    while(a!=NULL)
    {
        s.push(a);
        a=a->left;
    }
}
BSTIterator::BSTIterator(TreeNode *root) {
  pushall(root);
}

/** @return whether we have a next smallest number */
bool BSTIterator::hasNext() {
return !s.empty();
}

/** @return the next smallest number */
int BSTIterator::next() {
TreeNode* t=s.top();
s.pop();
pushall(t->right);
return t->val;
}

-------------------------------------------------------------------------------------------------------------------------------

order of people heights ( normal solution is n2 , segment tree solution is nlogn that is accepted not this one)

You are given the following :

A positive number N
Heights : A list of heights of N persons standing in a queue
Infronts : A list of numbers corresponding to each person (P) that gives the number of persons who are taller than P and standing in front of P
You need to return list of actual order of persons’s height

Input : 
Heights: 5 3 2 6 1 4
InFronts: 0 1 2 0 3 2     ans ===5 3 2 1 6 4 

We can start arranging peoples from smaller to higher heights. As we can see people with smallest height(index i) will come at index InFront[i] ( considering 0 based indexing) because all the people infront of it will have larger heights . Same we can do for all.

So by observation we can say that, person with ith smallest height will be arranged at (i+1)th empty location starting from first.

For above example :
Heights(InFronts)  : 1(3) , 2(2) ,3(1) ,4(2) ,5(0) , 6(0)

Empty locations are : – – – – – –

[1] for 1(3) it will be at 4th empty location
– – – 1 – –

[2] for 2(2), at 3rd empty location , because there are 2 persons with height>2 in front of 2.
– – 2 1 – –

[3] for 3(1) at 2nd empty location
– 3 2 1 – –

[4] for 4(2) at 3rd empty location
– 3 2 1 – 4

[5] 5(0) at 1st empty location
5 3 2 1 – 4

[6] 6(0) at 1st empty location
5 3 2 1 6 4

int find(vector<int>&A,int t)
{
    int c=0;
    
    for(int i=0;i<A.size();i++)
    {
        
        if(A[i]==-1) c++;
        
        if(c==t+1) return i;
    }
    return 0;
}
vector<int> Solution::order(vector<int> &A, vector<int> &B) {
    
    
    int n=A.size();
    
    map<int,int>mp;
    
    for(int i=0;i<n;i++)
    {
        mp[A[i]]=B[i];
    }
     /*for (auto j : mp) 
        cout << j.first << "   " << j.second  
             << endl; */
    vector<int> v(A.size(), -1);
    for(auto it=mp.begin();it!=mp.end();it++)
    {
        int t=it->second;
        
        int pos=find(v,t);
        
        v[pos]=it->first;
    }
    return v;
}

-------------------------------------------------------------------------------------------------------------------------
vector<int> Solution::order(vector<int> & arr, vector<int> & heights) {
    vector<pair<int, int> > a;
    for(int i = 0; i < arr.size(); i++){
        pair<int, int> temp = {arr[i], heights[i]};
        a.push_back(temp);
    }
    sort(a.begin(), a.end());
    arr.clear();
    for(int i = a.size()-1; i >=0; i--){
        arr.insert(arr.begin()+ a[i].second, a[i].first);
    }
    return arr;
}

