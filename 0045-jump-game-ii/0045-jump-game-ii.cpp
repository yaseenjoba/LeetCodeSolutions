class Solution {
public:
    int n ;
    int dp[10005];
    int sol(int i,  vector<int>& nums){
        if(i == n - 1){
            return 0;
        }
        else{
            if(~dp[i])return dp[i];
            int ans = 1e4;
            for(int j = 1 ; j <= nums[i]; j++){
                if(i + j >= n)break;
                ans =min(ans,  1 + sol(i + j, nums));
            }
            return dp[i] = ans;
        }
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        memset(dp, -1, sizeof dp);
        return sol(0 , nums);
    }
};