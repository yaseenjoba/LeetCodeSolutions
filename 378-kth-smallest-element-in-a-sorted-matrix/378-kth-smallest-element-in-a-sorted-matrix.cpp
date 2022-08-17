class Solution {
public:
  struct comp{
   bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }
  };
    int kthSmallest(vector<vector<int>>& lists, int k) {
         int result = -1;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, comp>
            pq;    int j = 0 ;
        for(auto i : lists){
          pq.push({i[0] ,{ 0 ,j++}});
        }
        while(k--){
           pair<int, pair<int ,int>>p = pq.top();
           pq.pop();
           result = p.first;
           if(p.second.first != lists[p.second.second].size() - 1){
             pq.push(make_pair(lists[p.second.second][p.second.first + 1] ,make_pair(p.second.first + 1,  p.second.second)));
           }
        }
    return result;
    }
};