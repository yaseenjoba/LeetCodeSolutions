class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char , int>lastPos;
        for(char i = 'a' ; i <= 'z';i++){
            lastPos[i] = -1;
        }
        for(char i = '1' ; i <= '9';i++){
            lastPos[i] = -1;
        }
        for(char i = 'A' ; i <= 'Z';i++){
            lastPos[i] = -1;
        }
        lastPos[' '] = -1;
        int l = 0;
        int ans = 0 ;
        for(int i = 0 ; i < s.size() ; i++){
            if(lastPos[s[i]] == -1)lastPos[s[i]] = i;
            else l = max(l , lastPos[s[i]] + 1) , lastPos[s[i]] = i;
            ans = max(i - l  + 1 , ans);
            cout<<l<<endl;
        }
        return ans;
    }
};