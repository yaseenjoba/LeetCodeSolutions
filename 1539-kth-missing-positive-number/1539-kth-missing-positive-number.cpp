class Solution {
public:
    int findKthPositive(vector<int>& nums, int k) {
        vector<int> missingNumbers;
        int i = 0 ;
        while(i < nums.size()){
          if( nums[i] > 0 && nums[i] <= nums.size() && nums[i] != nums[nums[i] - 1]){
            swap(nums[i] , nums[nums[i] - 1]);
          }else i++;
        }
        unordered_set<int>extraNumbers;
        for(int i = 0 ;i < nums.size() && missingNumbers.size() < k; i++){
          if(nums[i] != i + 1){
            missingNumbers.push_back(i + 1);
            extraNumbers.insert(nums[i]);
          }

        }
        for (i = 1; missingNumbers.size() < k; i++) {
          int candidateNumber = i + nums.size();
          if (extraNumbers.find(candidateNumber) == extraNumbers.end()) {
            missingNumbers.push_back(candidateNumber);
          }
        }
        return missingNumbers[k - 1];
    }
};