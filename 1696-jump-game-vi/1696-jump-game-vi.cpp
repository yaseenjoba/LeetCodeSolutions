class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        priority_queue<pair<int, int>>pq;
        int n = nums.size();
        vector<int>arr(n , 0);
        for(int i = n - 1 ; i >= 0 ;i--){
            while(!pq.empty() && pq.top().second > i + k)
                pq.pop();
            arr[i] = nums[i];
            arr[i]+=  (!pq.empty()? pq.top().first :0);
            pq.push({arr[i] , i});
        }
        return arr[0];
    }
};