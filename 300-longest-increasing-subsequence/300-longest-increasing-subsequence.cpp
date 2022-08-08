class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      vector<int> v;
      for (int i = 0; i<nums.size(); i++) {
          auto p = lower_bound(v.begin(), v.end(), nums[i]);
          if (p == v.end())  v.push_back(nums[i]);
  		  else  *p = nums[i];
      }
      return v.size();
    }
};