class Solution {
public:
    int removePalindromeSub(string s) {
        if(s.size() == 0)return 0;
        string str = s;
        reverse(str.begin() , str.end());
        if(str == s)return 1;
        if(s == string(s[0] , s.size())){
            return 1;
        }
        return 2;
    }
};