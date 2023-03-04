class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
    //Create an adjacency list of size N for storing the undirected graph.
        vector<int> adj[N]; 
        for(auto it : edges) {
            adj[it[0]].push_back(it[1]); 
            adj[it[1]].push_back(it[0]); 
        }

        //A dist array of size N initialised with a large number to 
        //indicate that initially all the nodes are untraversed.    
    
        int dist[N];
        for(int i = 0;i<N;i++) dist[i] = 1e9;
        // BFS Implementation.
        dist[src] = 0; 
        queue<int> q;
        q.push(src); 
        while(!q.empty()) {
            int node = q.front(); 
            q.pop(); 
            for(auto it : adj[node]) {
                if(dist[node] + 1 < dist[it]) {
                    dist[it] = 1 + dist[node]; 
                    q.push(it); 
                }
            }
        }
        // Updated shortest distances are stored in the resultant array ‘ans’.
        // Unreachable nodes are marked as -1. 
        vector<int> ans(N, -1);
        for(int i = 0;i<N;i++) {
            if(dist[i] != 1e9) {
                ans[i] = dist[i]; 
            }
        }
        return ans; 
    }
};




private:
    void findShortestPath(vector<int>adj[],int V,int node,vector<int>&vis,vector<int>&dist){
        vis[node] = 1;
        for(auto adjNode:adj[node]){
            if(dist[adjNode]>dist[node]+1)
                dist[adjNode] = dist[node]+1;
            if(!vis[adjNode]){
                findShortestPath(adj,V,adjNode,vis,dist);
            }
        }
        vis[node] = 0;
    return;
    }
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int>adj[N];
        for(auto edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>vis(N,0);
        vector<int>dist(N,INT_MAX);
        dist[src] = 0;
        findShortestPath(adj,N,src,vis,dist);
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i] = -1;
            }
        }
    return dist;
    }
