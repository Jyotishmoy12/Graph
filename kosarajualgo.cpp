class Solution
{
	public:
	
	void dfsTreversal(int u, vector<vector<int>>&adjReversed, vector<bool>&visited){
	    visited[u]=true;
	    for(int &v:adjReversed[u]){
	        if(!visited[v]){
	            dfsTreversal(v, adjReversed, visited);
	        }
	    }
	}
	
	void dfsFillStack(int u, vector<vector<int>>&adj, vector<bool>&visited, stack<int>&st){
	    visited[u]=true;
	    // first push all the childrens of u in stack
	    for(int &v:adj[u]){
	        if(!visited[v]){
	            dfsFillStack(v, adj, visited, st);
	        }
	    }
	    // then push the main node
	    st.push(u);
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
     // store order of dfs in stack
     // topo sort
     stack<int>st;
     vector<bool>visited(V, false);
     for(int i=0;i<V;i++){
         if(!visited[i]){
             dfsFillStack(i, adj, visited, st);
         }
     }
     // make a reverse graph
     vector<vector<int>>adjReversed(V);
     for(int u=0;u<V;u++){
         // connections from u to v
         for(int &v:adj[u]){
             adjReversed[v].push_back(u);
         }
     }
     // call dfs based on stack order
     int cntScc=0;
     visited=vector<bool>(V, false);
     
     while(!st.empty()){
         int node=st.top();
         st.pop();
         if(!visited[node]){
             dfsTreversal(node, adjReversed, visited);
             cntScc++;
         }
     }
     return cntScc++;
    }
