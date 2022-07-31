class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN;
        int prod = 1;
        for(auto i : nums){
            prod*=i;
            ans = max(ans , prod);
            if(prod == 0){
                prod = 1;
            }
        }
        prod = 1;
        reverse(nums.begin() , nums.end());
        for(auto i : nums){
            prod*=i;
            ans = max(ans , prod);
            if(prod == 0){
                prod = 1;
            }
        }
        return ans;
        
    }
};