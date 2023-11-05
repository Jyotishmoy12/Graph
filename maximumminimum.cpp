#include<bits/stdc++.h>
using namespace std;
int m,n;
bool isValid(int i, int j, int x, vector<vector<bool>>visited, vector<vector<int>>&arr, long long parent){
    // check out of bound condition
    // cell (i, j) is visited or absolute
    // diff between consicutive cell is greater than our assumed maximum
    // energy required if true
    // then return false
    if(i < 0 || j < 0 || i >= m || j>= n || visited[i][j] || abs((long long)arr[i][j]-parent)>x) return false;
    // check if we can reach at bottom right cell or not
    // if yes then return false
    if(i==m-1 && j==n-1)
    return true;
    visited[i][j] = true;
    // now traverse through all the four directions
    if(isValid(i+1, j, x, visited, arr, arr[i][j])) return true;
    if(isValid(i-1, j, x, visited, arr, arr[i][j])) return true;
    if(isValid(i, j+1, x, visited, arr, arr[i][j])) return true;
    if(isValid(i, j-1, x, visited, arr, arr[i][j])) return true;
    // other wise return false;
    return false;
}
// function to find the minimum value
int minimumEnergy(vector<vector<int>>&arr){
    int low=0, high=10000000;
    int res=arr[0][0];
    while(low<=high){
        int mid=(low+high)/2;
        vector<vector<bool>>visited(m, vector<bool>(n, false));
        if(isValid(0, 0, mid, visited, arr, arr[0][0])){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return res;
}
int main(){
      vector<vector<int> > arr = {
        { 1, 2, 1 },
        { 2, 8, 2 },
        { 2, 4, 2 },
    };
    m = arr.size(), n = arr[0].size();
 
    // Function Call
    cout << minimumEnergy(arr);
 
    return 0;
}
