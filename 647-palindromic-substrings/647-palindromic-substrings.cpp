class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        int ans = n;
        for(int i = 0;i< n;i++){
            int l = i , r = i + 1;
            while(l >= 0 && r<n && s[l] == s[r])ans++,l--,r++;
            l = i - 1 , r = i + 1;
            while(l >= 0 && r<n && s[l] == s[r])ans++,l--,r++;
        }
        return ans;
    }
};