class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int i , int j, int n ,int m){
        if(i >=n || j>=m)return 0;
        if(i == n - 1 && j == m - 1)return 1;
        if(~dp[i][j])return dp[i][j];
        return dp[i][j] = dfs(i + 1 , j , n  , m) + dfs(i , j  + 1 , n , m);
    }
    int uniquePaths(int m, int n) {
        dp.assign(n , vector<int>(m , -1));
        return dfs(0 , 0 , n , m);
    }
};