class Solution {
public:
    bool vis[400][400];
    vector<vector<char>> gr;
    void dfs(int i, int j){
        if( i >= gr.size() || j >= gr[0].size() || i < 0 || j < 0 || vis[i][j] || gr[i][j] =='0')return;
        vis[i][j] = true;
        dfs(i + 1 , j);        
        dfs(i - 1 , j);        
        dfs(i , j + 1);        
        dfs(i , j - 1);

    }
    int numIslands(vector<vector<char>>& grid) {
        gr = grid;
        int ans = 0;
        for(int i = 0 ; i < grid.size() ;i++){
            for(int j = 0; j< grid[0].size();j++){
                if(gr[i][j] == '1' && !vis[i][j]){
                    dfs(i , j);
                    ans++;
                }
            }
        }
        return ans;
    }
};