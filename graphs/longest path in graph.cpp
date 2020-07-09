Given an arbitrary unweighted rooted tree which consists of N (2 <= N <= 40000) nodes. The goal of the problem is to
 find largest distance between two nodes in a tree. Distance between two nodes is a number of edges on a path between the nodes (there will be a unique path between any pair of nodes since it is a tree).
 The nodes will be numbered 0 through N - 1.
 
 
 The tree is given as an array P, there is an edge between nodes P[i] and i (0 <= i < N). Exactly one of the i’s will have P[i] equal to -1, it will be root node.
 
 If given P is [-1, 0, 0, 0, 3], then node 0 is the root and the whole tree looks like this: 
 
          0
       /  |  \
      1   2   3
               \
  
                4 
                
first part of problem is to make a adjacency list from the given vector

vector adj[A.size()];
int v=A.size();
int i;
for(i=0;i<v;i++)
{
if(A[i]==-1) continue;

    adj[i].push_back(A[i]);
    adj[A[i]].push_back(i);
}

now we simply need to find longest path in it this is done using 2 bfs method

In this post, an efficient solution is discussed. We can find longest path using two BFSs. The idea is based on the following fact: If we start BFS from any node x 
and find a node with the longest distance from x,
 it must be an end point of the longest path. It can be proved using contradiction. So our algorithm reduces to simple two BFSs. 
 First BFS to find an end point of the longest path and second BFS from this end point to find the actual longest path. 
 
 
 pair<int, int> Graph::bfs(int u) 
{ 
    //  mark all distance with -1 
    int dis[V]; 
    memset(dis, -1, sizeof(dis)); 
  
    queue<int> q; 
    q.push(u); 
  
    //  distance of u from u will be 0 
    dis[u] = 0; 
  
    while (!q.empty()) 
    { 
        int t = q.front();       q.pop(); 
  
        //  loop for all adjacent nodes of node-t 
        for (auto it = adj[t].begin(); it != adj[t].end(); it++) 
        { 
            int v = *it; 
  
            // push node into queue only if 
            // it is not visited already 
            if (dis[v] == -1) 
            { 
                q.push(v); 
  
                // make distance of v, one more 
                // than distance of t 
                dis[v] = dis[t] + 1; 
            } 
        } 
    } 
  
    int maxDis = 0; 
    int nodeIdx; 
  
    //  get farthest node distance and its index 
    for (int i = 0; i < V; i++) 
    { 
        if (dis[i] > maxDis) 
        { 
            maxDis = dis[i]; 
            nodeIdx = i; 
        } 
    } 
    return make_pair(nodeIdx, maxDis); 
} 
  
//  method prints longest path of given tree 
void Graph::longestPathLength() 
{ 
    pair<int, int> t1, t2; 
  
    // first bfs to find one end point of 
    // longest path 
    t1 = bfs(0); 
  
    //  second bfs to find actual longest path 
    t2 = bfs(t1.first); 
  
    cout << "Longest path is from " << t1.first << " to "
         << t2.first << " of length " << t2.second; 
} 
