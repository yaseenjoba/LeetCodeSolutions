class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& arr, long long  target) {
        set<vector<int>> ans;
        if(arr.size() < 4){
            vector<vector<int>>c;
            return c;
        }
        sort(arr.begin() , arr.end());
        for(int  i = 0 ; i < arr.size() ;i++){
          for(int  j = i + 1 ; j < arr.size() - 2 ;j++){
              long long c = (target - (arr[i]  + arr[j]));
              int l = j + 1 , r = arr.size() - 1;
              while(l < r){
                 if(arr[l] + arr[r] == c){
                   ans.insert({arr[i] , arr[j] , arr[l] , arr[r]});
                 }
                 if(arr[l] + arr[r] > c){
                     r--;
                 }else l++;
              }
          }
        }
        vector<vector<int>>t(ans.begin() ,ans.end());
        return t;
    }
};