class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(x==parent[x]){
            return x;
        }
        return parent[x]=find(parent[x]);
    }

    void Union(int x, int y){
        int x_parent=find(x);
        int y_parent=find(y);
        if(x_parent==y_parent) return;

        if(rank[x_parent]>rank[y_parent]){
            parent[y_parent]=x_parent;
        }
        else if(rank[x_parent]<rank[y_parent]){
            parent[x_parent]=y_parent;
        }
        else{
            parent[x_parent]=y_parent;
            rank[y_parent]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
       parent.resize(26);
       rank.resize(26);
       for(int i=0;i<26;i++){
        // strating mein sab khud ke parent hote hain
        parent[i]=i;
       }
       // union of equal chars
       for(string &s: equations){
        if(s[1]=='='){
            //"a==b"
            Union(s[0]-'a', s[3]-'a');
        }
       }
       // find not equal to wale 
       for(string &s:equations){
        if(s[1]=='!'){
            //"a!=b" // a ka parent bhi a and b ka parent bhi a
            // so both the parents are same but it's a not equal to case
            // hence it will be false
            char first=s[0]; // a
            char second=s[3]; // b
            int parentOfFirst=find(first-'a');
            int parentOfSecond=find(second-'a');
            if(parentOfFirst==parentOfSecond){
                return false;
            }
        }
       }
       return true;
    }
};
