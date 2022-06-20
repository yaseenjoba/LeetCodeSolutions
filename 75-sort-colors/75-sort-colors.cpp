class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int>v(3,  0);
        for(auto i : nums){
            v[i]++;
        }
        for(auto &i : nums){
            if(v[0]) i = 0 , v[0]--;            
            else if (v[1]) i = 1 , v[1]--;
            else if(v[2]) i = 2 , v[2]--;
        }
    }
};