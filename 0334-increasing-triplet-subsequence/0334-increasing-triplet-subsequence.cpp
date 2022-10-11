class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        if(nums.size()<3)return false;
        multiset<int>left, right;
        left.insert(nums[0]);
        for(int i = 2;i<nums.size() ;i++){
            right.insert(nums[i]);
        }
        for(int i =1; i<nums.size() - 1 ;i++){
            if(*left.begin() < nums[i] && *right.rbegin() > nums[i]){
                return true;
            }
            right.erase(right.find(nums[i + 1]));
            left.insert(nums[i]);
        }
        return false;
    }
};