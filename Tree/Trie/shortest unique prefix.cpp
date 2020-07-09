Given an array of words, find all shortest unique prefixes to represent each word in the given array. Assume that no word is prefix of another

Input: arr[] = {"zebra", "dog", "duck", "dove"}
Output: dog, dov, du, z
Explanation: dog => dog
             dove = dov 
             duck = du
             z   => zebra 
             
             
An Efficient Solution is to use Trie. The idea is to maintain a count in every node. Below are steps.

1) Construct a Trie of all words. Also maintain frequency of every node (Here frequency is number of times node is visited during insertion). 
Time complexity of this step is O(N) where N is total number of characters in all words.

2) Now, for every word, we find the character nearest to the root with frequency as 1. The prefix of the word is path from root to this character. To do this, we can traverse Trie starting from root. For every node being traversed, we check its frequency. 
If frequency is one, we print all characters from root to this node and don’t traverse down this node

          root
                / \
         (d, 3)/   \(z, 1)
              /     \
          Node1     Node2
           / \          \
     (o,2)/   \(u,1)     \(e,1)
         /     \          \
   Node1.1    Node1.2     Node2.1
      /  \         \            \
(g,1)/    \ (t,1)   \(c,1)       \(b,1)
    /      \         \            \ 
   Leaf   Leaf       Node1.2.1     Node2.1.1
   (dog)  (dot)        \               \
                         \(k, 1)          \(r, 1)
                          \                \   
                          Leaf           Node2.1.1.1
                          (duck)              \
                                                \(a,1)
                                                 \
                                                 Leaf
                                                 (zebra)
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class Trienode
{   
public:
    Trienode* children[26];
    int freq;
};
Trienode* newnode()
{
    Trienode* temp= new Trienode();
    for(int i=0;i<26;i++)
    {
        temp->children[i]=NULL;
    }

    temp->freq=0;
    return temp;
}
void Insert(Trienode* root,string key)
{
    Trienode* temp=root;
    
    for(int i=0;i<key.length();i++)
    {
        int index = key[i]-'a';
        
        if(!temp->children[index])
            temp->children[index] = newnode();
        
        
        (temp->children[index]->freq)++;
        temp=temp->children[index];
    }
}

int Search(Trienode* root,string key)
{   
    Trienode* temp=root;
    for(int i=0;i<key.length();i++)
    {
        int index = key[i]-'a';
        temp=temp->children[index];
        
        if(temp->freq==1)return i;
    }
    
    return key.length();
    
}

void prefix(vector<string> &A) {
    
    Trienode* root= newnode();
    for(int i=0;i<A.size();i++)
    {
        Insert(root,A[i]);
    }
    

    vector<string>ans;
    for(int i=0;i<A.size();i++)
    {
        int j = Search(root,A[i]);
        
        cout<<A[i]<<"----"<<A[i].substr(0,j+1)<<endl;
    }
    
}

int main()
{
    vector<string> arr={"geeksgeeks","geeksquiz","geeksforgeeks","geeksfforgeeks"}; 
    prefix(arr);
    
    return 0;
}

--output--
geeksgeeks----geeksg
geeksquiz----geeksq
geeksforgeeks----geeksfo
geeksfforgeeks----geeksff
