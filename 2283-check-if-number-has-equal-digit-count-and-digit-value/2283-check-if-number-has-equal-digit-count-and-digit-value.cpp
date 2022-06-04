class Solution {
public:
    bool digitCount(string num) {
        map<int ,int>mm;
        for(auto i : num){
            mm[i - '0']++;
        }
        for(int i = 0 ; i < num.size() ;i++){
            // cout<<i<<" "<<mm[i]<<" "<<nums[i]
            if(mm[i] != num[i] - '0')return false; 
        }
        return true;
    }
};