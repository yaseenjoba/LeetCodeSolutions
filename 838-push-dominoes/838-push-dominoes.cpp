class Solution {
public:
    string pushDominoes(string s) {
         if(s.size() == 1)
            return s;
        string fans = "";
        while(1){
            string ans = "";
            for(int i = 0; i < s.size(); i++){
                if(i == 0){
                    if(s[i] == '.' and s[i + 1] == 'L') ans += s[i + 1];
                    else ans += s[i];
                }
                else if(i == s.size() - 1){
                    if(s[i] == '.' and s[i - 1] == 'R') ans += s[i - 1];
                    else ans += s[i];
                }
                else{
                    if(s[i] == '.' and s[i - 1] == 'R' and s[i + 1] != 'L') ans += s[i - 1];
                    else if(s[i] == '.' and s[i + 1] == 'L' and s[i - 1] != 'R') ans += s[i + 1];
                    else ans += s[i];
                }
            }
            s = ans;
            if(s == fans) break;
            else fans = s; 
        }
        return fans;
    }
};