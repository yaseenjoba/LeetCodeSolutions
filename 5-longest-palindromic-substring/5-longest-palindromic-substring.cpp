class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = "";
        int sz = 0;
        for(int i = 0 ; i < s.size() ; i ++){
            int l  = i , r = i;
            // odd pal..
            while(l >=0 && r < n && s[l] == s[r]){
                if(r - l + 1 > sz){
                    sz =  r  - l + 1;
                    ans = s.substr(l , sz);
                }
                l--,r++;
            }
           
            //even pal..
            l = i , r = i + 1;
            while(l >=0 && r < n && s[l] == s[r]){
                if(r - l + 1 > sz){
                    sz = r -  l + 1;
                    ans = s.substr(l , sz);
                }
                l--,r++;
            }
        }
        return ans;
    }
};