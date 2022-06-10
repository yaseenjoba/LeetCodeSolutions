class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        vector<int>v;
        for(auto i : nums){
            if(i!=0){
                v.push_back(i);
            }
        }
        for(int i = 0 ; i < v.size() ; i++){
            nums[i] =  v[i];
        }
        for(int i = v.size() ; i< nums.size() ;i++){
            nums[i] = 0;
        }
    }
};