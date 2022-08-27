class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        if(nums.size() < 3)return 0;
        int n = nums.size();
        return max(nums[n - 1]*nums[n - 2]*nums[n - 3] , nums[n - 1]*nums[0]*nums[1]);
    }
};