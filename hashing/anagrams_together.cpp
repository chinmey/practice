Given an array of strings, group anagrams together. 

/* the hashing approach to this method is very difficult to implemnet in c++ so we do it without hashing*/

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]

Following is another method to print all anagrams together. Take two auxiliary arrays, index array and word array. 
Populate the word array with the given sequence of words. Sort each individual word of the word array.
 Finally, sort the word array and keep track of the corresponding indices.
 After sorting, all the anagrams cluster together. Use the index array to print the strings from the original array of strings
 
 
 Let us understand the steps with following input Sequence of Words:

"cat", "dog", "tac", "god", "act"
1) Create two auxiliary arrays index[] and words[]. Copy all given words to words[] and store the original indexes in index[]

index[]:  0   1   2   3   4
words[]: cat dog tac god act
2) Sort individual words in words[]. Index array doesn’t change.

index[]:   0    1    2    3    4
words[]:  act  dgo  act  dgo  act
3) Sort the words array. Compare individual words using strcmp() to sort

index:     0    2    4    1    3
words[]:  act  act  act  dgo  dgo
4) All anagrams come together. But words are changed in words array. To print the original words, take index from the index array and use it in the original array. We get

"cat tac act dog god"


class Solution {
public:
    struct indword{
     int index;
     string st;
    };
    static  bool cmp(indword a,indword b)
    {
        string x=a.st;
        string y=b.st;
        
        int i,j;
        for(i=0;i<min(x.size(),y.size());i++)
        {
            if(x[i]==y[i])
                continue;
            else
                return x[i]<y[i];
        }
         return x.size() < y.size();
    }
    string sortt(string &str) 
{ 
   sort(str.begin(), str.end()); 
   return str; 
}
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>copy;/* to store copy of array of string*/
        
        int n=strs.size(),i,j;
        for(i=0;i<n;i++)
            copy.push_back(strs[i]);
        vector<vector<string>>v; /*answer vector*/
        
        
        indword arr[n];
        for(i=0;i<n;i++)
        {
            arr[i].index=i;
            arr[i].st=sortt(strs[i]);
        }
       
        sort(arr,arr+n,cmp);
    
        map<string,vector<int>>mm;
        for(i=0;i<n;i++)
        {
            mm[arr[i].st].push_back(arr[i].index);
        }
          for (auto it=mm.begin(); it!=mm.end(); it++)
    {
              vector<string>ans;
        for ( i=0; i<it->second.size(); ++i)
        {
           ans.push_back(copy[it->second[i]]);
        }   
        v.push_back(ans);
    }
        
    
        
        
        return v;
    }
};
