class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int ,int>mm;
        int sum = 0 , ans = 0;
        int idx = 1;
        for(auto i : nums){
            sum+= i?1:-1;
            if(sum == 0){
                ans = max(idx , ans);
            }
            if(mm.count(sum)){
                ans = max(ans , idx - mm[sum]);
            }else{
                mm[sum] = idx;
            }
            idx++;
        }
        return ans;
    }
};