class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int res = 0;
        for(auto i : nums){
            if(i%2 == 0)
                res+=i;
        }
        for(auto q : queries){
            if(nums[q[1]] %2 == 0){
                res-=nums[q[1]];
            }
            nums[q[1]]+=q[0];
            if(nums[q[1]] %2 == 0){
                res+=nums[q[1]];
            }
            ans.push_back(res);
        }
        return ans;
    }
};