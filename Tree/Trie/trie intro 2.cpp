/* display trie content*/

bool isLeafNode(struct TrieNode* root) 
{ 
    return root->isLeaf != false; 
} 
  
// function to display the content of Trie 
void display(struct TrieNode* root, char str[], int level) 
{ 
    // If node is leaf node, it indicates end 
    // of string, so a null character is added 
    // and string is displayed 
    if (isLeafNode(root))  
    { 
        str[level] = '\0'; 
        cout << str << endl; 
    } 
  
    int i; 
    for (i = 0; i < alpha_size; i++)  
    { 
        // if NON NULL child is found 
        // add parent key to str and 
        // call the display function recursively 
        // for child node 
        if (root->children[i])  
        { 
            str[level] = i + 'a'; 
            display(root->children[i], str, level + 1); 
        } 
    } 
} 
  
// Driver program to test above functions 
int main() 
{ 
    // Keys to be inserted in Trie 
    char keys[][8] = { "the", "a", "there", "answer", 
                       "any", "by", "bye", "their" }; 
  
    struct TrieNode* root = createNode(); 
  
    // Inserting keys in Trie 
    for (int j = 0; j < ARRAY_SIZE(keys); j++) 
        insert_node(root, keys[j]); 
  
    int level = 0; 
    char str[20]; 
  
    // Displaying content of Trie 
    cout << "Content of Trie: " << endl; 
    display(root, str, level); 
} 
