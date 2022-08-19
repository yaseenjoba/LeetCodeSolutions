class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int>left , right;
        for(auto &i : nums)left[i]++;
        for(auto i : nums){
            if(left[i] == 0)continue;
            left[i]--;
            if(right[i - 1]){
                right[i - 1]--;
                right[i]++;
            }else if(left[i + 1] && left[i + 2]){
                left[i + 1]--;
                left[i + 2]--;
                right[i + 2]++;
            }else return false;
        } 
        return true;
    }
};