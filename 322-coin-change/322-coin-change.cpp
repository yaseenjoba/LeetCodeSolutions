
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        long long dp[10005];
        dp[0] =0;
        for(int i= 1;i<=amount;i++){
            dp[i] = INT_MAX;
            for(auto c : coins){
                if(i - c >=0)
                dp[i] = min(dp[i],dp[i -c] +1); 
            }
        }
        if(dp[amount] == INT_MAX){
            return -1;
        }
        return dp[amount];
    }
};