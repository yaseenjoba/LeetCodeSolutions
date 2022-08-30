class Solution {
public:
    
    struct valueCompare {
        char operator()(const pair<int, int> &x, const pair<int, int> &y) {
              return y.second > x.second;
            }
         };
    int leastInterval(vector<char>& tasks, int k) {
          int intervalCount = 0;
    unordered_map<char, int> taskFrequencyMap;
    for (char chr : tasks) {
      taskFrequencyMap[chr]++;
    }

    priority_queue<pair<char, int>, vector<pair<char, int>>, valueCompare> maxHeap;

    // add all tasks to the max heap
    for (auto entry : taskFrequencyMap) {
      maxHeap.push(entry);
    }

    while (!maxHeap.empty()) {
      vector<pair<char, int>> waitList;
      int n = k + 1;  // try to execute as many as 'k+1' tasks from the max-heap
      for (; n > 0 && !maxHeap.empty(); n--) {
        intervalCount++;
        auto currentEntry = maxHeap.top();
        maxHeap.pop();
        if (currentEntry.second > 1) {
          currentEntry.second--;
          waitList.push_back(currentEntry);
        }
      }
      // put all the waiting list back on the heap
      for (auto it = waitList.begin(); it != waitList.end(); it++) {
        maxHeap.push(*it);
      }
      if (!maxHeap.empty()) {
        intervalCount += n;  // we'll be having 'n' idle intervals for the next iteration
      }
    }

    return intervalCount;
    }
};