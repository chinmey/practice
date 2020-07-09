Node * build_help(int inorder[],int preorder[],int inorderStart,int inorderEnd,int preorderStart,int preorderEnd)
{
    if(inorderStart>inorderEnd)
        return NULL;
    int rootdata=preorder[preorderStart];
    for(int i=inorderStart;i<inorderEnd;i++)
    {
        if(inorder[i]==rootdata)
           int rootindex=i;
        break;
    } /* lins= left inorder start rpree=right preorder end*/
    int lins=inorderStart;

    int line=rootindex-1;

    int lpres= preorderStart+1;

    int lpree= line - lins+lpres//leftpreorder length=rightpreorder length
    int rpres= lpree+1;

    int rpree= preorderEnd
    int rins= rootindex+1;

    int rine=  inorderEnd;



    Node *root=new Node(rootdata); // create root

    root->left=build_help(inorder,preorder,lins,line,lpres,lpree);

    root->right=build_help(inorder,preorder,rins,rine,rpres,rpree);
    return root;
}
Node *build(int inorder[],int preorder[],int size)
{
    Node *root=build_help(inorder,preorder,0,size-1,0,size-1);
    return root;
}
coding ninja ka h(interview ke lie thik h par aise memory overload hoga)(working code neeche h)

yeh wala chal raha
   TreeNode* helper(int start,vector<int>&p,vector<int>&in,int ins,int ine)
    {
        if(start>=p.size()||ins>ine) return NULL;
        
        int index=0;
        for(int i=ins;i<=ine;i++)
        {
            if(in[i]==p[start])
                index=i;
        }
        TreeNode* temp=new TreeNode(p[start]);
        
        temp->left=helper(start+1,p,in,ins,index-1);
        temp->right=helper(index-ins+start+1,p,in,index+1,ine);
        return temp;
    }
    TreeNode* buildTree(vector<int>& p, vector<int>& in) {
        
        return helper(0,p,in,0,in.size()-1);
        
    }
    
--------------------------------------------------------------------------------------------------------------------------


this is a method we an use it to both inorder+pre and inorder+post

// Recursive function to construct a binary tree from given
// inorder and preorder sequence
Node* construct(int start, int end, vector<int> const &preorder,
				int &pIndex, unordered_map<int,int> &map)
{
	// base case
	if (start > end)
		return nullptr;

	// The next element in preorder[] will be the root node of subtree
	// formed by inorder[start, end]
	Node *root = newNode(preorder[pIndex++]);

	// get the index of root node in inorder[] to determine the
	// boundary of left and right subtree
	int index = map[root->key];

	// recursively construct the left subtree
	root->left = construct(start, index - 1, preorder, pIndex, map);

	// recursively construct the right subtree
	root->right = construct(index + 1, end, preorder, pIndex, map);

	// return current node
	return root;
}

// Construct a binary tree from inorder and preorder traversals
// This function assumes that the input is valid
// i.e. given inorder and preorder sequence forms a binary tree
Node* construct(vector<int> const &inorder, vector<int> const &preorder)
{
	// get number of nodes in the tree
	int n = inorder.size();

	// create a map to efficiently find the index of any element in
	// given inorder sequence
	unordered_map<int,int> map;
	for (int i = 0; i < n; i++)
		map[inorder[i]] = i;

	// pIndex stores index of next unprocessed node in preorder sequence
	// start with root node (present at 0'th index)
	int pIndex = 0;

	return construct(0, n - 1, preorder, pIndex, map);
}

-------------------------------------------------------------------------------------------------------------------

from inorder and postorder



// Function to create a new binary tree node having given key
Node* newNode(int key)
{
	Node* node = new Node;
	node->key = key;
	node->left = node->right = nullptr;

	return node;


// Recursive function to construct a binary tree from
// inorder and postorder traversals
Node* construct(int start, int end,
				vector<int> const &postorder, int &pIndex,
				unordered_map<int,int> &map)
{
	// base case
	if (start > end)
		return nullptr;

	// Consider the next item from the end of given postorder sequence
	// This value would be the root node of subtree formed by inorder[start, end]
	Node *root = newNode(postorder[pIndex--]);

	// search the index of current node in inorder sequence to determine
	// the boundary of left and right subtree
	int index = map[root->key];

	// recursively construct the right subtree
	root->right = construct(index + 1, end, postorder, pIndex, map);

	// recursively construct the left subtree
	root->left = construct(start, index - 1, postorder, pIndex, map);

	// return root node
	return root;
}

// Construct a binary tree from inorder and postorder traversals
// This function assumes that the input is valid
// i.e. given inorder and postorder sequence forms a binary tree
Node* construct(vector<int> const &inorder, vector<int> const &postorder)
{
	int n = inorder.size();

	// map is used to efficiently find the index of any element in
	// given inorder sequence
	unordered_map<int,int> map;
	for (int i = 0; i < inorder.size(); i++)
		map[inorder[i]] = i;

	// pIndex stores the index of next unprocessed node from the end
	// of postorder sequence
	int pIndex = n - 1;
	return construct(0, n - 1, postorder, pIndex, map);
}





