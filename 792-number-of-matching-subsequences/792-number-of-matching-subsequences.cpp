class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>v(26);
        for(int i = 0 ; i < s.size() ;i++){
            v[s[i] - 'a'].push_back(i);
        }
        int ans = 0;
        for(auto w : words){
            int prev = -1 , is = 1;
            for(auto i : w){
                auto x = upper_bound(v[i - 'a'].begin() , v[i - 'a'].end() , prev);
                if(x == v[i - 'a'].end()){
                    is = 0;
                    break;
                }
                prev = *x;
                
            }
            ans+= is;
        }
        return ans;
    }
};