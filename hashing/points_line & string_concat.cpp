Given N point on a 2D plane as pair of (x, y) co-ordinates, we need to find maximum number of point which lie on the same line.

Input : points[] = {-1, 1}, {0, 0}, {1, 1}, 
                    {2, 2}, {3, 3}, {3, 4} 
Output : 4
Then maximum number of point which lie on same
line are 4, those point are {0, 0}, {1, 1}, {2, 2},
{3, 3}
A={0,1,2,3}   B={0,1,2,3}
 int Solution::maxPoints(vector<int> &A, vector<int> &B) {
    
    
    int n = A.size();
if(n==0)
    return 0;
if(n==1)
    return 1;
    
map<pair<double,double>,int> mp;
double x1,y1,x2,y2;
double m,c;
int soln=1;

for(int i=0;i<n-1;i++){
        x1 = A[i];
        y1 = B[i];
    for(int j=0;j<n;j++){
        if(j==i)
            continue;
            
        x2 = A[j];
        y2 = B[j];
        
        if(x2==x1){
            m=INT_MAX;
            c = x1;
        }
        else{
            m = (y2-y1)/(x2-x1);
            c = y1-m*x1;
        }
        pair<double, double> p;
        p.first=m;
        p.second=c;
        
        if(mp.find(p)==mp.end()){
            mp[p]=2;
            soln = max(soln,mp[p]);
        }
        else{
            mp[p]+=1;
            soln = max(soln,mp[p]);
        }
    }
    
    mp.clear();
}
    
return soln; 
    
    
}

      





----------------------------------------------------------------------------------------------------------------------------------------------------
You are given a string S, and a list of words L i.e array/vector of strings (Words in list L are all of the same length).
 Find the starting indices of the substrings in string S, which contains all the words present in
 list L.

The order of words of list L appearing inside string S does not matter i.e if string S is “barfooapplefoobar” and list of words (L) is [“foo”, “bar”]
 then we have to look for substrings “foobar”, “barfoo” in string S.
 
 Input : S: "barfoothefoobarman" 
        L: ["foo", "bar"]                     
Output : 0 9
Explanation : 
// at index 0 : barfoo
// at index 9 : foobar 

Input : S: "catbatatecatatebat"
        L: ["cat", "ate", "bat"] 
Output : 0 3 9
Explanation : 
// at index 0 : catbatate
// at index 3 : batatecat
// at index 9 : catatebat    

Input : S : "abcdababcd"
        L : ["ab", "ab", "cd"]
Output : 0 2 4 
Explanation :
// at index 0 : abcdab
// at index 2 : cdabab
// at index 4 : ababcd

Input : S : "abcdababcd"
        L : ["ab", "ab"]
Output : 4

Declare a map (hash_map) which stores all words of List L corresponding to their occurrences inside list L.
Traverse through all possible substrings in string S which are equal to size_L(total number of characters produced if all the words in list L are concatenated).
Create a temporary map (temp_hash_map) and initialize it with original map(hash_map) for every possible substring.
Extract the words from the substring and if the word is present in temp_hash_map we decrease it’s corresponding count, 
if it’s not present in temp_hash_map we simply break.
After traversing the substring we traverse temp_hash_map and look for any key which has it’s count > 0. If we found no such key it means that all 
the words in list L were found in substring and store the given starting index of the substring, 
if we find a key which has it’s count > 0 it means we did not traversed whole substring because we came across a word which was not in temp_hash_map.


// Returns an integer vector consisting of starting 
// indices of substrings present inside the string S 
vector<int> findSubstringIndices(string S,  
                            const vector<string>& L) 
{ 
  
    // Number of a characters of a word in list L. 
    int size_word = L[0].size(); 
  
    // Number of words present inside list L. 
    int word_count = L.size(); 
  
    // Total characters present in list L. 
    int size_L = size_word * word_count; 
  
    // Resultant vector which stores indices. 
    vector<int> res; 
  
    // If the total number of characters in list L 
    // is more than length of string S itself. 
    if (size_L > S.size()) 
        return res; 
  
    // Map stores the words present in list L 
    // against it's occurrences inside list L 
    unordered_map<string, int> hash_map; 
  
    for (int i = 0; i < word_count; i++)  
        hash_map[L[i]]++;     
  
    for (int i = 0; i <= S.size() - size_L; i++) { 
        unordered_map<string, int> temp_hash_map(hash_map); 
  
        int j = i,count=word_count; 
  
        // Traverse the substring 
        while (j < i + size_L) { 
  
            // Extract the word 
            string word = S.substr(j, size_word); 
  
  
            // If word not found or if frequency of current word is more than required simply break. 
            if (hash_map.find(word) == hash_map.end()||temp_hash_map[word]==0) 
                break; 
  
            // Else decrement the count of word from hash_map 
            else
               { temp_hash_map[word]--;count--;}  
  
  
            j += size_word; 
        } 
       
        // Store the starting index of that substring when all the words in the list are in substring 
        if (count == 0) 
            res.push_back(i); 
    } 
  
    return res; 
} 
