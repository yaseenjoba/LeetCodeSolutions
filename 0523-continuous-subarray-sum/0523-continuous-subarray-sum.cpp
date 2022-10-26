class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        if(nums.size() == 1)return false;
        for(int i = 1; i< nums.size(); i++){
            nums[i]+=nums[i -  1];
        }
        unordered_map<int, int>mm;
        for(int i = 0; i < nums.size(); i++){
            if(i >= 1 && nums[i]% k == 0)return true;
            if (mm.count(nums[i] % k) && mm[nums[i] % k] + 2 <= i)return true;
            if(!mm.count(nums[i] % k))
                mm[nums[i] % k] = i;
        }
        return false;
    }
};