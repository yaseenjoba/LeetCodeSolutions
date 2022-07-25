class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty())return {-1 ,-1};
        int l = 0 , r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] > target - 1){
                r = mid;
            }else l = mid + 1;
        }
        if(nums[l] != target){
            return {-1 ,-1};
        }
        int left = l;
        l = left , r = nums.size() - 1;
        while(l < r){
            int mid = l + (r - l + 1)/2;
            if(nums[mid] == target){
                l = mid;
            }else r = mid - 1;
        }
      
        return {left  , l};
    }
};