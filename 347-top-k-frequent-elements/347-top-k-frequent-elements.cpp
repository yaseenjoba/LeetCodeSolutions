class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int ,int>mm;
        for(auto i : nums)mm[i]++;
        vector<pair<int, int>>v;
        for(auto i : mm){
            v.push_back({i.second , i.first});
        }
        priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int , int>>>minHeap(v.begin() , v.begin() + k);
        for(int i = k ; i < v.size() ;i++){
            if(v[i].first > minHeap.top().first){
                minHeap.pop();
                minHeap.push(v[i]);
            }
        }
        vector<int>ans;
        while(!minHeap.empty()){
            ans.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return ans;
        
    }
};