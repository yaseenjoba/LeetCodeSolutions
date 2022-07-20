class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int , bool>mm;
        for(auto i : nums)mm[i] = true;
        for(int i = 1 ; i <= nums.size() + 1 ;i++){
            if(!mm[i])return i;
        }
        return -1;
    }
};