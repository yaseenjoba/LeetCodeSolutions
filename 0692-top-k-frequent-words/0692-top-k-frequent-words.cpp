class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string , int>mm;
        for(auto &i : words){
            mm[i]++;
        }
        vector<pair<int,  string>>s;
        for(auto i : mm){
            s.push_back({i.second , i.first});
        }
        sort(s.begin() , s.end() , [&](pair<int , string>&a , pair<int ,string>&b){
                if(a.first == b.first){
                    return a.second > b.second;
                } 
            return a.first < b.first;
        });
        vector<string>ans;
        while(k--){
            ans.push_back(s.back().second);
            s.pop_back();
        }
        return ans;
    }
};