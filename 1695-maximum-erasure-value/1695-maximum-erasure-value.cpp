class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        map<int ,int>mm;
        auto sums = nums;
        int l = 0 , sum =0;
        for(int i = 1; i < nums.size() ;i++)sums[i]+=sums[i - 1];
        int ans = 0;
        for(int i = 0; i < nums.size() ;i++){
            if(mm.count(nums[i]) && mm[nums[i]] >= l){
                int oldl = l;
                l = mm[nums[i]];
                int sub;
                if(oldl - 1 < 0)sub = sums[l];
                else sub = sums[l] - sums[oldl - 1];
                sum -=sub; 
                l++;
            }
            sum+=nums[i];
            mm[nums[i]] = i;
            ans = max(ans , sum);
        }
        return ans;
    }
};