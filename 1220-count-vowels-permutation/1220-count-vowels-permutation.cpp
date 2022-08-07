class Solution {
public:
    int dp[int(2e4 + 10)][26];
    int nn;
    int mod = 1e9 + 7;
    long long sol(int i, char last){
        if(i == nn)return 1;
        if(~dp[i][last  - 'a'])return dp[i][last  - 'a'];
        long long m1 = 0  , m2 = 0 , m3 = 0 , m4 =0  , m5 =0 , m6= 0;
        if(last == 'a'){
            m1  = sol(i  + 1  , 'e');
            m1%=mod;
        }else if(last == 'e'){
            m2 = sol(i + 1 , 'a')%mod + sol(i + 1 , 'i')%mod;
            m2%=mod;
        }else if(last == 'i'){
            m3 = (sol(i  + 1 , 'a')%mod + sol(i  + 1 , 'e')%mod + sol(i  + 1 , 'o')%mod + sol(i  + 1 , 'u')%mod)%mod;
            m3%=mod;
        }else if(last == 'o'){
            m4 = sol(i + 1 , 'i') + sol(i + 1 , 'u');
            m4%=mod;
        }else if(last == 'u'){
            m5 = sol(i  + 1 , 'a');
            m5%=mod;
        }else{
            m6 = sol(i  + 1 , 'a') + sol(i  + 1 , 'e') + sol(i  + 1 , 'o') + sol(i  + 1 , 'u') + sol(i + 1 ,'i' );
            m6%=mod;
        }
        return dp[i][last - 'a'] = (m1 +  m2 + m3 + m4 + m5 + m6) % mod;
        
        
    }
    int countVowelPermutation(int n) {
        nn = n;
        memset(dp , -1 ,sizeof(dp));
        return sol(0 , 'k');
    }
};