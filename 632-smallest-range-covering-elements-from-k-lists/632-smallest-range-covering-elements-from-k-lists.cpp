class Solution {
public:
    struct valueCompare {
    bool operator()(const pair<int, pair<int, int>> &x, const pair<int, pair<int, int>> &y) {
      return x.first > y.first;
    }
  };
    vector<int> smallestRange(vector<vector<int>>& lists) {
             priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, valueCompare>
        minHeap;
        int rangeStart = 0, rangeEnd = numeric_limits<int>::max(),
        currentMaxNumber = numeric_limits<int>::min();
        // put the 1st element of each array in the min heap
        for (int i = 0; i < lists.size(); i++) {
          if (!lists[i].empty()) {
            minHeap.push(make_pair(lists[i][0], make_pair(i, 0)));
            currentMaxNumber = max(currentMaxNumber, lists[i][0]);
          }
        }
        while(minHeap.size() == lists.size()){
          pair<int , pair<int,  int>>node = minHeap.top();
          minHeap.pop();
          if(currentMaxNumber - node.first  < rangeEnd - rangeStart){
              rangeEnd = currentMaxNumber;
              rangeStart = node.first; 
          }
          node.second.second++;
          if(node.second.second < lists[node.second.first].size()){
            node.first = lists[node.second.first][node.second.second];
            minHeap.push(node);
            currentMaxNumber = max(currentMaxNumber , node.first);
          }

        }
        return {rangeStart , rangeEnd};

    }
};