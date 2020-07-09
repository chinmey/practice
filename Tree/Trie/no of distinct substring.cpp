Given a string of length N of lowercase alphabet characters. The task is to complete the function countDistinctSubstring(),
 which returns the count of total number of distinct substrings of this string.
 
 
 2
ab
ababa

Output:
4
10

The idea is create a Trie of all suffixes of given string. Once the Trie is constricted, our answer is total number of nodes in the constructed 
Trie.
 For example below diagram represent Trie of all suffixes for “ababa”. Total number of nodes is 10 which is our answer.
 #define alpha 26
struct Node{
    bool end;
    Node *children[26];
};

Node *get()
{
    Node *t=new Node();
    
    t->end=false;
    
    for(int i=0;i<alpha;i++)
    {
        t->children[i]=NULL;
    }
    
return t;
}

void insert(Node *root,string key)
{
    int n=key.length(),i;
    Node *p=root;
    for(i=0;i<n;i++)
    {
        int index=key[i]-'a';
        if(!p->children[index])
        p->children[index]=get();
        p=p->children[index];
    }
    p->end=true;
}
 
 int count(Node *node)
{
     if (node == NULL) 
        return 0; 
  
    int res = 0; 
    for (int i = 0; i < alpha; i++) 
    { 
        
        if (node->children[i] != NULL) 
            res += count(node->children[i]); 
    } 
  
    
    return (1 + res); 
}
 
int countDistinctSubstring(string s)
{
    Node *root=get();
    
    int n=s.length();
    
    int i;
    for(i=0;i<n;i++)
    insert(root,s.substr(i));
    int ans=count(root);
    
    /* for(i=0;i<n;i++)
     {
        root= remove(root,s.substr(i));
     }*/  // this part is done to free memory not important in question look at remove function from trie intro 1
     
     
    
   return ans;
}

-------------------------------------------------------------------------------------------------------------------------------

word boogle
(using trie look at gfg)
Given a dictionary, a method to do a lookup in the dictionary and a M x N board where every cell has one character. Find all possible words that can be formed by a sequence of adjacent characters. Note that we can move to any of 8 adjacent characters, but a word should not have multiple instances of the same cell.

1. Create an Empty trie and insert all words of given dictionary into trie

      After insertion, Trie looks like (leaf nodes are in RED )
                       root
                    /       
                    G   F     Q
                 /  |   |     |
                O   E   O     U
                    |   |     |
                    E    R     I
                    |         |  
                    K         Z 
                    |   
                    S   
2. After that we have pick only those character in boggle[][] which are child of root of Trie
Let for above we pick ‘G’ boggle[0][0] , ‘Q’ boggle[2][0] (they both are present in boggle matrix)
3. search a word in a trie which start with character that we pick in step 2

1) Create bool visited boolean matrix (Visited[M][N] = false )
2) Call SearchWord() for every cell (i, j) which has one of the
   first characters of dictionary words. In above example,
   we have 'G' and 'Q' as first characters.

SearchWord(Trie *root, i, j, visited[][N])
if root->leaf == true 
   print word 

if we have seen this element first time then make it visited.
   visited[i][j] = true
   do
      traverse all child of current root 
      k goes (0 to 26 ) [there are only 26 Alphabet] 
      add current char and search for next character 

      find next character which is adjacent to boggle[i][j]
      they are 8 adjacent cells of boggle[i][j] (i+1, j+1), 
      (i+1, j) (i-1, j) and so on.
   
   make it unvisited visited[i][j] = false 
