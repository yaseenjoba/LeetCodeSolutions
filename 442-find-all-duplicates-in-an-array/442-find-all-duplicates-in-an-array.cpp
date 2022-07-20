class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        unordered_map<int ,int>mm;
        for(auto &i : nums){
            mm[i]++;
        }
        vector<int>ans;
        for(auto j : mm){
            if(j.second == 2){
                ans.push_back(j.first);
            }
        }
        return ans;
    }
};