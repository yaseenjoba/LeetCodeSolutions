class Solution {
public:
    int dp[1001];
    vector<int>arr;
    int x;
    int sol(int sum){
        if(sum == x)return 1;        
        if(sum > x)return 0;
        if(~dp[sum])return dp[sum];
        int ans = 0;
        for(auto i : arr){
            ans += sol(sum + i);
        }
        return dp[sum] = ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        x = target;
        arr = nums;
        memset(dp , -1 ,sizeof dp);
        return sol(0);
    }
};