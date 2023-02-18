class Solution {
    private:
    bool detect(int src, vector<int>adj[], int vis[]){
        vis[src]=1;
        queue<pair<int,int>>q;
        q.push({src, -1});
        while(!q.empty()){
            int node=q.front().first;
            int parent=q.front().second;
            q.pop();
            for(auto adjacentNode: adj[node]){
                if(!vis[adjacentNode]){
                    vis[adjacentNode]=1;
                    q.push({adjacentNode, node}); // adjacentNode it will work as node and node will act as parent
                    
                }//visited
                else if(parent!=adjacentNode){
                    return true;
            }
            }
            
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int v, vector<int> adj[]) {
      
      int vis[v]={0};
      for(int i=0;i<v;i++){
          if(!vis[i]){
              if(detect(i, adj, vis)) return true;
          }
      }
      return false;
    }
};
