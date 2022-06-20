class Solution {
public:
    int minimumLengthEncoding(vector<string>& words) {
        map<string , int>mm;
        int ans = 0;
        for(auto i : words )mm[i]++;
        sort(words.begin() , words.end() , [&](string & a  , string & b){return a.size() > b.size();});
        for(auto i : words){
            int sz = i.size();
            if(mm[i]){
                ans+= sz + 1;
            }
            for(int j = sz - 1 ; j >= 0 ;j--){
                string t = i.substr(j, sz-j);
                mm[t] = 0;
            }
        }
        return ans;
        
    }
};