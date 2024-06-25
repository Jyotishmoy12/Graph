class Solution {
    vector<int>parent;
    vector<int>rank;
    int findParent(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=findParent(parent[x]);
    }
    void Union(int x, int y){
        int x_parent=findParent(x);
        int y_parent=findParent(y);
        if(x_parent==y_parent) return;
        if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]+=1;
        }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {


    if(connections.size()<n-1) return -1;
    
    rank.resize(n, 0);
    parent.resize(n);

    for(int i=0;i<n;i++){
        parent[i]=i; // intialize parent vector
    } 
    int components=n;
    for(auto &v:connections){
        // if both the nodes doestnot have same parent then connect them
        if(findParent(v[0])!=findParent(v[1])){
            components--; // so using one component and conncet them
            Union(v[0], v[1]);
        }
    }
    return components-1;   
    }
};
