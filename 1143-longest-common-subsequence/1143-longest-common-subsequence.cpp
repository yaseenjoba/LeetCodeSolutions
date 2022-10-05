class Solution {
public:
    int dp[1001][1001];
    int sol(int i , int j , string &s1 , string &s2){
        if(i == s1.size())return 0;        
        if(j == s2.size())return 0;
        if(~dp[i][j])return dp[i][j];
        if(s1[i] == s2[j]){
            return dp[i][j] = 1 + sol(i + 1 , j + 1, s1 , s2);
        }else{
            return dp[i][j] = max(sol(i + 1 , j , s1 , s2) , sol(i , j + 1 , s1 ,s2));
        }
    }
    int longestCommonSubsequence(string s1, string s2) {
        memset(dp  ,-1, sizeof dp);
        return sol(0 , 0 ,s1 , s2 );
    }
};