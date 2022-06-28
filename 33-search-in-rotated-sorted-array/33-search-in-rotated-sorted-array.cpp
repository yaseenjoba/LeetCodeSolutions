class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0 , r = nums.size() - 1;
        int c  = nums[0];
        while(l < r){
            int mid = l + (r - l)/2;
            if(nums[mid] < c){
                r = mid;
            }else l = mid + 1;
        }
        int l1 = 0 , r1 = l - 1;
        int l2 = l , r2 = nums.size() - 1;
        while(l1 < r1){
            int mid = l1 + (r1 - l1)/2;
            if(nums[mid] >= target){
                r1 = mid;
            }else l1 = mid + 1;
        }
        if(nums[l1] == target){
            return l1;
        }
        while(l2 < r2){
            int mid = l2 + (r2 - l2)/2;
            if(nums[mid] >= target){
                r2 = mid;
            }else l2 = mid + 1;
        }
        if(nums[l2] == target){
            return l2;
        }
        return -1;
    }
};