class Solution {
    char dfsFindminChar(unordered_map<int, vector<char>>&adj, char curr_ch, vector<int>&visited){
        visited[curr_ch-'a']=1; //mark it visited
        char minChar= curr_ch;
        for(char &v: adj[curr_ch]){
            if(visited[v-'a']==0){
                minChar=min(minChar, dfsFindminChar(adj, v, visited));
            }
        }
        return minChar;
    }
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
       int n=s1.length();
       int m= baseStr.length();
       unordered_map<int, vector<char>>adj;
       for(int i=0;i<n;i++){
         char u=s1[i];
         char v=s2[i];
         adj[u].push_back(v);
         adj[v].push_back(u);
       }
       string result;
       for(int i=0;i<m;i++){
           char ch= baseStr[i];
           vector<int>visited(26,0); //for this ch none of its visited now
           char minChar= dfsFindminChar(adj, ch, visited); //calling dfs in every character then find the minimum of them and push them in the result string
           result.push_back(minChar);

       }
       return result;
    }
};
