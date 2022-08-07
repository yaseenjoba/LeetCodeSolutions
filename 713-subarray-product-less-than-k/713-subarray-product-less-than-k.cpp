class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& arr, int target) {
         int l = 0 , ans = 0;
         int curProduct = 1;
        for(int r = 0 ; r < arr.size() ; r++){
          curProduct*=arr[r];
          while(curProduct >= target && l <= r){
              curProduct/=arr[l];
              l++;
          }  
          ans+= r-l + 1;
        }
        return ans;
    }
};