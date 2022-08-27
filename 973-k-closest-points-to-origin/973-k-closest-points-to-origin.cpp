class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>>pq;
        for(auto i : points){
            pq.push({(i[0] * i[0]) + (i[1] *i[1] ), {i[0] , i[1]}});
        }
        for(int i = k ; i< points.size();i++){
            pq.pop();
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            ans.push_back({pq.top().second.first , pq.top().second.second});
            pq.pop();
        }
        return ans;
    }
};