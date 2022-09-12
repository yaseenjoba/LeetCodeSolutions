class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin() , tokens.end());
        int l = 0 , r = tokens.size() -  1 , score = 0 , ans = 0;
        while(l <= r){
            int prevL = l , prevR = r;
            if(tokens[l] <= power){
                power-=tokens[l];
                score++;
                ans = max(ans , score);
                l++;
            }else if(score >=1){
                score--;
                power+=tokens[r--];
            }
            if(prevL == l && prevR == r)break;
        }
        return ans;
    }
};