class Solution {
public:
    long long modi;
    long long dp[55][55][55];
    long long dfs(int n , int m , int i , int j , int moves , int mx){
        if(i>=n || j>=m || i<0 ||j<0)return 1;
        if(moves == mx)return 0;
        if(~dp[i][j][moves])return dp[i][j][moves];
        return  dp[i][j][moves] = (dfs( n , m , i + 1 , j , moves + 1 , mx) % modi +
                dfs( n , m , i , j + 1 , moves + 1 , mx) % modi +
                dfs( n , m , i - 1 , j , moves + 1 , mx) % modi +
                dfs( n , m , i , j - 1 , moves + 1 , mx) % modi) % modi;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        modi = 1e9 + 7;
        memset(dp , -1 ,sizeof dp);
        return dfs(m , n , startRow , startColumn , 0 , maxMove);
    }
};