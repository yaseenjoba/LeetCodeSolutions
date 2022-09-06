class Solution {
public:
    map<pair<int, int> , int>dp;
    int sol(int i , int sum ,int t, vector<int>&num){
        if(i == num.size())
            return sum == t;
        if(dp.count({i , sum}))return dp[{i , sum}];
        return dp[{i , sum}] = sol(i + 1 , sum + num[i] , t  , num ) + sol(i + 1 , sum - num[i] , t  , num );
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return sol(0  ,0 , target , nums);
    }
};