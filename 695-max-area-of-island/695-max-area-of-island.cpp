class Solution {
public:
    int cnt = 0;
    int vis[60][60];
    vector<vector<int>>gr;
    void dfs(int  i , int j){
        if(i >= gr.size() || j >= gr[0].size() || i <0 || j <0 || gr[i][j] == 0)return;
        if(vis[i][j])return;
        cnt++;
        vis[i][j] = 1;
        dfs(i + 1 , j);        
        dfs(i , j + 1);
        dfs(i - 1 , j);        
        dfs(i , j - 1);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        gr = grid;
        int ans = 0;
        for(int  i = 0 ; i < grid.size() ;i++){
            for(int  j = 0 ;j < grid[0].size() ;j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt= 0;
                    dfs(i , j);
                    ans = max(ans , cnt);
                }
            }
        }
        return  ans;
    }
};