class Solution {
public:
    bool isPalindrome(string &s , int l ,int r , bool go){
            while(l <= r && l>=0){
                if(s[l] == s[r]){
                    l++,r--;
                }else if(go){
                    return isPalindrome(s, l + 1 , r , false) || isPalindrome(s, l , r - 1 , false);
                }else return false;
                
            }
        return true;
    }
    bool validPalindrome(string s) {
        return isPalindrome(s , 0 , s.size() - 1 , true);
    }
};