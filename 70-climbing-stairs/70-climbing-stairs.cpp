class Solution {
public:
    int nn;
    int dp[50];
    int sol(int i){
        if(i>=nn){
            if(i == nn)return 1;
            return 0;
        }
        if(~dp[i])return dp[i];
        return dp[i] = sol(i + 1)+        
        sol(i + 2);
    }
    int climbStairs(int n) {
        nn=n;
        memset(dp , -1 , sizeof dp);
        return sol(0);
    }
};