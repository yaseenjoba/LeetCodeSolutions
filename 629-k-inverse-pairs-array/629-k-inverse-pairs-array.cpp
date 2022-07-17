class Solution {
public:
    int kInversePairs(int n, int K) {
        int dp[n + 1][K + 1];
        int mod = 1e9 + 7;
        memset(dp , 0 , sizeof dp);
        dp[0][0] = 0;
        for(int i=1;i<=K;i++){
            dp[1][i]=0;
        }
        for(int i=1;i<=n;i++){
            dp[i][0]=1;
        }
        for(int i=2;i<=n;i++){
            for(int j=1;j<=K;j++){
                dp[i][j]=(dp[i-1][j]+dp[i][j-1])%mod;
                if(j-i>=0){
                    dp[i][j]=(dp[i][j]-dp[i-1][j-i]+mod)%mod;
                }
            }         
        }
        return dp[n][K];
    }
};