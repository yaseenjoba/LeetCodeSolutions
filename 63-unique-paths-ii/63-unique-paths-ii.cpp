class Solution {
public:
    int  dp[105][105];
    int ans = 0;
    int n ,m;
    vector<vector<int>>grid;
    int dfs(int i , int j){
        if(i>=m||j>=n)return 0;
        if(i == m - 1 && j == n - 1)return 1;
        if(grid[i][j] == 1)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        return dp[i][j] = dfs(i + 1 ,j) + dfs(i , j + 1);
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        m = obstacleGrid.size();
        n = obstacleGrid[0].size();
        grid = obstacleGrid;
        memset(dp , -1 , sizeof dp);
        if(grid[m - 1][n- 1] == 1)return 0;
        return dfs(0,0);;
    }
};