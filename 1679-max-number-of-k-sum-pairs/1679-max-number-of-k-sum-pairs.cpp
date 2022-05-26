class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        map<int ,int>mm;
        for(auto i : nums)mm[i]++;
        int ans = 0;
        for(auto i : nums){
            if(mm[i]>=1 && mm[k - i]>=1){
                if(i == k -i && mm[i] == 1)continue;
                ans++;
                mm[i]--;
                mm[k-i]--;
            }
        }
        return ans;
    }
};