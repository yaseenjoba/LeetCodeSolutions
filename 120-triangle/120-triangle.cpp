class Solution {
public:
    int dp[201][201];
    int sol(vector<vector<int>>& triangle ,int taken, int i){
        if(i>=triangle.size())return 0;
        if(~dp[i][taken])return dp[i][taken]; 
        return dp[i][taken] = triangle[i][taken] + min(
            sol(triangle ,taken + 1, i + 1) , sol(triangle ,taken, i + 1)
        ); 
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        memset(dp , -1 ,sizeof(dp));
        return sol(triangle , 0 , 0);
    }
};