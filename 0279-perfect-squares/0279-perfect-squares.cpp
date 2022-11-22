class Solution {
public:
    vector<int>v;
    int dp[100001];
    int sol(int sum){
        if(sum < 0)return 1e9;
        if(sum == 0) return 0;
        if(~dp[sum])return dp[sum];
        int ans = 10000;
        for(auto i : v){
            if(sum >= i){
                ans = min(ans , 1 + sol(sum - i));
            }
        }
        return dp[sum] = ans;
    }
    int numSquares(int n) {
        for(int i = 1; i<= 100 ;i++){
            v.push_back(i*i);
        }
        memset(dp, -1 ,sizeof dp);
        return sol(n);
    }
};