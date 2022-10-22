class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>ans;
        int sum = 0;
        int r ,l = 0;
        multiset<int>s;
        for(int i = 0; i < k;i++)s.insert(nums[i]);
        ans.push_back(*s.rbegin());
        for(int r = k ; r < nums.size() ;r++){
            s.insert(nums[r]);
            s.erase(s.find(nums[l++]));
            ans.push_back(*s.rbegin());           
        }
        return ans;
    }
};