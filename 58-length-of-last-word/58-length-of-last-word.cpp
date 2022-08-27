class Solution {
public:
    int lengthOfLastWord(string str) {
        int i;
        for(i = str.size() - 1 ; i >=0 ; i--){
            if(str[i]!=' ')break;
        }
        int ans =0;
        while( i >= 0  && str[i]!=' '){
            ans++;
            i--;
        }
        return ans;
    }
};