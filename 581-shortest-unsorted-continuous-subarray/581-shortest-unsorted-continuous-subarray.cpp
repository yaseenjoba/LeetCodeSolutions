class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        auto v = nums;
        sort(nums.begin() , nums.end());
        if(v == nums)return 0;
        vector<int>freq(nums.size() , 0);
        for(int i = 0 ; i < nums.size() ;i++){
           freq[i] = nums[i] != v[i];
        }
        int first = 0 , sec = 0;
        for(int i = 0 ; i < nums.size() ;i++)if(freq[i] == 1){first = i; break;}
        for(int i = 0 ; i < nums.size() ;i++)if(freq[i] == 1){sec = i;}
        return sec - first + 1;
    }
};