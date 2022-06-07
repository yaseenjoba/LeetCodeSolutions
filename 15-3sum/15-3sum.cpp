class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>ans;
        sort(nums.begin() , nums.end());
        for(int i = 0  ; i < nums.size() ;i++){
            int  l = i + 1 , r = n - 1;
            if(i > 0 && nums[i] == nums[i - 1])continue;
            while(l < r){
                int sum = nums[i] + nums[l] + nums[r];
                if(sum > 0){
                    r--;
                }else if(sum < 0){
                    l++;
                }else{
                    ans.push_back({nums[i] , nums[l] , nums[r]});
                    l++;
                    while(l < n && nums[l] == nums[l - 1] )l++;
                }
            }
            
        }
        return ans;
    }
};