class Solution {
public:
    static int sol(int i , int sum1 , int sum2 , vector<vector<int>>&dp ,const vector<int>&num){
        if(i == num.size()){
          return abs(sum1 - sum2);
        }
        int diff = abs(sum1 - sum2);
        if(~dp[i][diff])return dp[i][diff];
        return  dp[i][diff] = min(sol( i + 1 , sum1 + num[i] , sum2 , dp , num) , sol( i + 1 , sum1 , sum2 + num[i] , dp ,num));
      }
    int lastStoneWeightII(vector<int>& num) {
         int n = num.size();
      vector<vector<int>>dp(n , vector<int>(n*100 , -1));
      return sol(0 , 0 , 0 , dp  ,num);
    }
};