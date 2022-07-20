class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeros = 0,mult = 1;
        for(auto i : nums){
            if(i == 0)zeros++;
            else mult*=i;
        }
        for(auto &i : nums){
            if(i == 0){
                if(zeros == 1){
                    i = mult;
                }else i = 0;
            }else if(zeros && i != 0){
                i = 0;
            }else i = mult/i;
        }
        return nums;
        
    }
};