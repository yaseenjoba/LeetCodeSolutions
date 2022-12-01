class Solution {
public:
    bool halvesAreAlike(string s) {
        int counta =0;
        int countall =0;
        for(int i=0;i<s.size();i++){
            if(tolower(s[i]) == 'a'||tolower(s[i]) == 'e'||tolower(s[i]) =='i'||tolower(s[i]) == 'o'||tolower(s[i]) == 'u'){
                countall++;
                if(i<(s.size()/2)){
                    counta++;
                }
            }
        }
        return 2*counta == countall;
    }
};