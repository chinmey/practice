

Given a set of reviews provided by the customers for different hotels and a string containing “Good Words”, 
you need to sort the reviews in descending order according to their “Goodness Value” (Higher goodness value first). 
We define the “Goodness Value” of a string as the number of “Good Words” in that string.


S = "cool_ice_wifi"
R = ["water_is_cool", "cold_ice_drink", "cool_wifi_speed"]

Output:
ans = [2, 0, 1]
Here, sorted reviews are ["cool_wifi_speed", "water_is_cool", "cold_ice_drink"]




#define alpha 26

struct TrieNode{
    bool end;
    TrieNode *children[alpha];
};

TrieNode*  get()
{
    TrieNode *t=new TrieNode();
    
    t->end=false;
    
    for(int i=0;i<alpha;i++)
    t->children[i]=NULL;
    return t;
}
void insert(TrieNode* root,string key)
{
    TrieNode* t=root;
    int n=key.size();
    
    for(int i=0;i<n;i++)
    {
        int index=key[i]-'a';
        
        if(!t->children[index])
        {
            t->children[index]=get();
        }
        t=t->children[index];
    }
    t->end=true;
}

bool search( TrieNode *root, string key) 
{ 
     TrieNode *pCrawl = root; 

    for (int i = 0; i < key.length(); i++) 
    { 
        int index = key[i] - 'a'; 
        if (!pCrawl->children[index]) 
            return false; 

        pCrawl = pCrawl->children[index]; 
    } 

    return (pCrawl != NULL && pCrawl->end); 
}

vector<int> Solution::solve(string A, vector<string> &B) {
    
    TrieNode* root=get();
    
    int n=A.size();
    int i,j;
    string s;
    for(i=0;i<n;i++)
    {
        if(A[i]=='_')
        {
            /*cout<<s<<endl;*/
            insert(root,s);
            s.erase();
            
        }
        else
        s=s+A[i];
    }
    insert(root,s);
    
    vector<pair<string,int>>v;
    
    int t=B.size();
    int count=0;
    for(i=0;i<t;i++)
    {
        string str=B[i];
     count=0;
     int m=str.size();
     string xx;
     for(j=0;j<m;j++)
     {
         if(str[j]=='_')
         {
             bool a=search(root,xx);
             if(a) count++;
             xx.clear();
         }
         else
         xx=xx+str[j];
         
     }
     if(search(root,xx)) count++;
     
        pair<string, int> temp = {str, count};
        v.push_back(temp);
     
        
        
    }
    
    for(auto it=v.begin();it!=v.end();it++)
    cout<<it->first<<" "<<it->second<<endl;
    
    
    int gg=v.size();
    
    for(i=0;i<gg-1;i++)
    {
        for(j=i+1;j<gg;j++)
        {
            if(v[i].second <v[j].second)
            {
                pair<string,int>tt={v[i].first,v[i].second};
                v[i].first=v[j].first;
                v[i].second=v[j].second;
                
                v[j].first=tt.first;
                v[j].second=tt.second;
            }
        }
    }
        vector<int>ans;
           map<string,int>mp;
    
    for(i=0;i<B.size();i++)
    mp[B[i]]=i;
    
      for(auto it=v.begin();it!=v.end();it++){
         /* cout<<it->first<<" "<<it->second<<endl;*/
          
          int v=mp[it->first];
          ans.push_back(v);
      }
   
    
 

    return ans;
    
    
}

