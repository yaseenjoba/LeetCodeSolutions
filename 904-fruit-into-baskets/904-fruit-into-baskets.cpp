class Solution {
public:
    int totalFruit(vector<int>& arr) {
        unordered_map<int ,int>freq;/*O(1)*/
        int l = 0 , unique = 0 ,ans =0;
        for(int  r = 0 ; r < arr.size(); r++){
          freq[arr[r]]++;
          if(freq[arr[r]] == 1)unique++;
          if(unique == 2){
            ans = max(ans , r - l  + 1);
          }
          while(unique > 2){
            freq[arr[l]]--;
            if(freq[arr[l]] == 0)unique--;
            l++;
          }
          ans = max(ans , r - l  + 1);
        }
        return ans;
    }
};