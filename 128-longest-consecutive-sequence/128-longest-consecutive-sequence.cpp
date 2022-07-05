class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s(nums.begin() , nums.end());
        unordered_set<int>vis;
        int ans = 0;
        for(auto i : nums){
            int x = i;
            if(vis.count(x))continue;
            int res = 0;
            while(s.count(x))vis.insert(x) , x++,res++;
            ans = max(ans , res);
        }
        return ans;
        
    }
};