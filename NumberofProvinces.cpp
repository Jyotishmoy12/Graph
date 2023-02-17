class Solution {
  private: 
    // dfs traversal function 
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        // mark the more as visited
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V]; 
        
        // to change adjacency matrix to list 
        for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                // self nodes are not considered
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        int vis[V] = {0}; 
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
        
    }
};



//DFS

#include <bits/stdc++.h> 
void dfs( unordered_map<int, vector<int>>&adj, int u, vector<bool>&visited){
    visited[u]=true;
    for(int &v:adj[u]){
       if(!visited[v]){
           dfs(adj, v, visited);
       } 
    }
}
int findNumOfStates(vector<vector<int>>& roads, int n) {
    vector<bool>visited(n,false);
    //make graph
    unordered_map<int, vector<int>>adj;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(roads[i][j]==1){
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
    }
    int count=0;
    for(int i=0;i<n;i++){
        if(!visited[i]){
           dfs(adj, i, visited);
           count++; 
        }
    }
    return count;
}
