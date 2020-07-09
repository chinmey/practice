Clone an Undirected Graph

The idea is to do a BFS traversal of the graph and while visiting a node make a clone node of it (a copy of original node). 
If a node is encountered which is already visited then it already has a clone node.

struct GraphNode 
{ 
    int val; 
  
    //A neighbour vector which contains addresses to 
    //all the neighbours of a GraphNode 
    vector<GraphNode*> neighbours; 
}; 
  
// A function which clones a Graph and 
// returns the address to the cloned 
// src node 
GraphNode *cloneGraph(GraphNode *src) 
{ 
    //A Map to keep track of all the 
    //nodes which have already been created 
    map<GraphNode*, GraphNode*> m; 
    queue<GraphNode*> q; 
  
    // Enqueue src node 
    q.push(src); 
    GraphNode *node; 
  
    // Make a clone Node 
    node = new GraphNode(); 
    node->val = src->val; 
  
    // Put the clone node into the Map 
    m[src] = node; 
    while (!q.empty()) 
    { 
        //Get the front node from the queue 
        //and then visit all its neighbours 
        GraphNode *u = q.front(); 
        q.pop(); 
        vector<GraphNode *> v = u->neighbours; 
        int n = v.size(); 
        for (int i = 0; i < n; i++) 
        { 
            // Check if this node has already been created 
            if (m[v[i]] == NULL) 
            { 
                // If not then create a new Node and 
                // put into the HashMap 
                node = new GraphNode(); 
                node->val = v[i]->val; 
                m[v[i]] = node; 
                q.push(v[i]); 
            } 
  
            // add these neighbours to the cloned graph node 
            m[u]->neighbours.push_back(m[v[i]]); 
        } 
    } 
  
    // Return the address of cloned src Node 
    return m[src]; 
} 
