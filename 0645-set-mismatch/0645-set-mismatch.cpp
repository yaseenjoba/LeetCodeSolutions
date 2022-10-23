class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int , int>mm;
        for(auto i : nums){
            mm[i]++;
        }
        int twice = -1 , ans = -1;
        for(int i = 1; i <=nums.size() ;i++){
            if(mm[i] == 2)twice = i;
            if(mm[i] == 0)ans = i;
        }
        return {twice , ans};
    }
};