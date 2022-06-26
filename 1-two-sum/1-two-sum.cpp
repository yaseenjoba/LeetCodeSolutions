class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int>mm;
        int j =1;
        for(auto i : nums){
            mm[i] = j++;
        }
        vector<int>ans;
        for(int i=0;i<nums.size();i++){
            if(mm.count(target - nums[i])){
               if(i == mm[target - nums[i]] - 1)continue;
               ans.push_back(i);
               ans.push_back(mm[target - nums[i]] - 1);
               return ans;
            }
        }
        return ans;
    }
};