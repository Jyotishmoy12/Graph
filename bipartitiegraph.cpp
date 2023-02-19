class Solution {
    //colors a component
    private:
    bool check(int start, int V, vector<int>adj[], int color[]){
       queue<int>q;
	    q.push(start);
	      color[start]=0; 
	    // initially color -1 
	    while(!q.empty()){
	        int node=q.front();
	        q.pop();
	        for(auto it :adj[node]){
	            //if the adjnode is not yet colored
	            // you will give the opposite color
	            if(color[it]==-1){
	                color[it]=!color[node];
	                q.push(it);
	            }
	            //colored case that means someone did coloured on some other path
	            else if(color[it]==color[node]){
	                return false;
	            }
	        }
	    }
	    return true; 
    }
public:
	bool isBipartite(int V, vector<int>adj[]){
	  int color[V];
	    for(int i=0;i<V;i++) color[i]=-1;
	   for(int i=0;i<V;i++){
	       if(color[i]==-1){
	           if(check(i, V, adj, color)==false){
	               return false;
	           }
	       }
	   } 
	   return true;
	}

};
