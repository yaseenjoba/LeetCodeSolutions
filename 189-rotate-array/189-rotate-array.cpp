class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        deque<int> q(nums.begin() , nums.end());
        while(k--){
            int x = q.back();
            q.pop_back();
            q.push_front(x);
        }
        for(int i = 0 ; i < nums.size() ;i++){
            nums[i] = q[i];
        }
        
    }
};