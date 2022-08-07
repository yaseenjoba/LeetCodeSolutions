class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        sort(arr.begin() , arr.end());
        int bestDiff = INT_MAX;
        for(int i = 0 ; i  < arr.size() ; i++){
            int l = i + 1 , r = arr.size() - 1;
            while(l < r){
                int curr = target - arr[i] - arr[l] - arr[r];
                if(curr == 0){
                    return arr[i] + arr[l] + arr[r];
                }
                if(abs(curr) < abs(bestDiff)){
                    bestDiff = curr;
                }
                if(curr < 0) r--;
                else l++;
            }
        }
        return target - bestDiff;
    }
};