class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i =0;
        int j =numbers.size()-1;
        vector<int>ans;
        while(i<j){
            if(numbers[i]+numbers[j] == target){
                ans.push_back(i+1);                
                ans.push_back(j+1);
                break;
            }
            if(numbers[i]+numbers[j] > target){
              j--;
            }
             if(numbers[i]+numbers[j] < target){
              i++;
            }
        }
        return ans;
    }
};