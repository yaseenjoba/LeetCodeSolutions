class Solution {
public:
 
    static bool sol(int i , int sum, int t , vector<vector<int>>&dp ,  vector<int>&num){
    if(i == num.size()){
      return sum == t;
    }
    if(sum > t)return false;
    if(~dp[i][sum])return dp[i][sum];
    return dp[i][sum] = sol(i + 1 , sum + num[i] , t,  dp , num) || sol(i + 1 , sum , t,  dp , num);
 }
  bool canPartition( vector<int> &num) {
    int sum = 0 ;
    for(auto i : num){
      sum+=i;
    }
    
    if(sum%2 !=0)return false;
    int n = num.size();
    vector<vector<int>>dp(n , vector<int>(100*n , -1));
    return sol(0 , 0 , sum/2 , dp , num);
  }
};