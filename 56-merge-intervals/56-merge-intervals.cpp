class Solution {
public:
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
         if (intervals.size() < 2) {
          return intervals;
        }
        vector<vector<int>> mergedIntervals;
        sort(intervals.begin() , intervals.end() , [&](vector<int> &a , vector<int> &b ){return a[0] < b[0];});
        int start = -1 , end = -1; 
        for(auto i : intervals){
            if(start == -1){
              start = i[0] , end = i[1];
            }else if(i[0]  <= end){
              end = max(i[1] , end);
            }else{
              mergedIntervals.push_back({start , end});
              start = i[0] , end = i[1];
            }
        }
        mergedIntervals.push_back({start , end});
        return mergedIntervals;
    }
};