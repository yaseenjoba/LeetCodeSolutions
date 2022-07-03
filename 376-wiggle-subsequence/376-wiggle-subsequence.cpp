class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)return 1;
        int diff = nums[1] - nums[0];
        int ans =  diff!=0?2:1;
        for(int  i = 2 ; i< nums.size() ;i++){
            int curr = nums[i] - nums[i - 1];
            if((curr< 0 && diff >= 0) || (curr>0 && diff <= 0)){
                ans++;
                diff = curr;
            }
        }
        return ans;
    }
};