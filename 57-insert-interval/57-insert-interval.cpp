class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
         vector<vector<int>> mergedIntervals;
        int pos = 0 ;
        while(pos < intervals.size() && intervals[pos][1] < newInterval[0]){
          mergedIntervals.push_back(intervals[pos]);
          pos++;
        }
        while(pos < intervals.size() && intervals[pos][0] <= newInterval[1]){
          newInterval[0] = min(intervals[pos][0], newInterval[0]);
          newInterval[1] = max(intervals[pos][1], newInterval[1]);
          pos++;
        }
        mergedIntervals.push_back(newInterval);
        while(pos < intervals.size()){
          mergedIntervals.push_back(intervals[pos++]);
        }

        return mergedIntervals;
    }
};