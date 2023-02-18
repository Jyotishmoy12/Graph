void dfs(int r, int c, const int iR, const int iC, vector<vector<int>> &visited, vector<vector<int>> &grid, vector<pair<int, int>> &temp) {
    int row = grid.size();
    int col = grid[0].size();
    
    static vector<int> delRow {-1, 0, 1, 0};
    static vector<int> delCol {0, 1, 0, -1};
    
    visited[r][c] = 1;
    
    temp.push_back({r-iR, c-iC});
    
    for(int i=0;i<4;i++) {
        int nr = r + delRow[i];
        int nc = c + delCol[i];
        
        if(nr >= 0 && nr < row && nc >= 0 && nc < col && grid[nr][nc] == 1 && visited[nr][nc] == 0) {
            dfs(nr, nc, iR, iC, visited, grid, temp);
        }
    }
}
int countDistinctIslands(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    
    set<vector<pair<int, int>>> s;
    vector<vector<int>> visited(row, vector<int>(col, 0));
    
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            if(visited[i][j] == 0 && grid[i][j] == 1) {
                vector<pair<int, int>> temp;
                dfs(i, j, i, j, visited, grid, temp);
                s.insert(temp);
            }
        }
    }
    return s.size();
}
