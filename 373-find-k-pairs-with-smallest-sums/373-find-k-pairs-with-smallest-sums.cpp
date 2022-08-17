class Solution {
public:
    struct comp{
       bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
          return x.first > y.first;
        }
      };
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
         vector<vector<int>> result;
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp> pq;    
        for(int i = 0 ; i < nums1.size() && i < k ;i++){
          pq.push({ nums1[i] + nums2[0], {i , 0}});
        }
        while(!pq.empty()&& k--){
          int i = pq.top().second.first;
          int j = pq.top().second.second;
          result.push_back({nums1[i] ,nums2[j]});
          pq.pop();
          if(j + 1 < nums2.size()){
            pq.push({nums1[i] +nums2[j + 1] , {i , j + 1} });
          }
        }
        return result;
    }
};