class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int>mm;
        for(auto i  :arr)mm[i]++;
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int, int>>>pq;
        for(auto i : mm){
            pq.push({i.second  , i.first});
        }
        while(k--){
            int x = pq.top().first;
            pq.pop();
            x--;
            if(x!=0){
                pq.push({x , pq.top().first});
            }
        }
        return pq.size();
    }
};