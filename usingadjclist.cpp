#include<iostream>
using namespace std;
int main(){
int n,m;
cin>>n>>m;
 vector<int>adj[n+1];
 fo(int i=0;i<m;i++){
   int u,v;
   cin>>u>>v;
   adj[u].push_back(v); // v is a neigbour of u
   adj[v].push_back(u); // for undirected graph for directed this line is not needed
 }
  return 0;
}

//sc- 0(2E)
