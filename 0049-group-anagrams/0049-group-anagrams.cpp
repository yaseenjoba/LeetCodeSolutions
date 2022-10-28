class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mm;
        for(auto i : strs){
            auto v = i;
            sort(v.begin() , v.end());
            mm[v].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto i : mm){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};