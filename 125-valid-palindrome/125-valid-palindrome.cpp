class Solution {
public:
    bool isPalindrome(string s) {
        string ans = "";
        for(auto &i : s){
            if((i >= 'A' && i<='Z') || (i>='a' && i<='z') || (i>='0' && i<='9')){
                ans+=tolower(i);
            }
        }
        string ss = ans;
        reverse(ss.begin() , ss.end());
        return ss == ans;
    }
};