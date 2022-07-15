class Solution {
public:
    bool vis[51][51];
    int cnt = 0;
    void dfs(int i , int j , vector<vector<int>>& grid){
        if(i < 0 || i>=grid.size() || j < 0 || j >= grid[0].size() || grid[i][j] == 0 || vis[i][j])return;
        vis[i][j] = true;
        cnt++;
        dfs(i + 1 , j , grid);        
        dfs(i , j  + 1, grid);
        dfs(i , j - 1 , grid);
        dfs(i - 1 , j , grid);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0 ; i< grid.size(); i++){
            for(int j = 0 ;j <grid[0].size() ;j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cnt = 0;
                    dfs(i  , j , grid);
                    ans = max(ans , cnt);
                }
            }
        }
        return ans;
    }
};