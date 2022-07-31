class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0 , r = nums.size() - 1;
        int c = nums[0];
        while(l  < r){
            int mid = l + (r - l)/2;
            if(nums[mid] < c){
                r = mid;
            }else l = mid + 1;
        }
        return min(nums[l] , c);
    }
};