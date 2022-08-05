class Solution {
public:
    int totalFruit(vector<int>& arr) {
        map<int ,int>freq;/*O(1)*/
        int l = 0  ,ans = 0;
        for(int r = 0 ; r < arr.size(); r++){
          freq[arr[r]]++;
          if(freq.size() <= 2){
              int cnt = 0;
              for(auto i : freq){
                  cnt+= i.second;
              }
              ans = max(ans , cnt);
          }else{
              while(freq.size() > 2){
                if(freq[arr[l]] == 1){
                    freq.erase(arr[l]);
                }else {
                    freq[arr[l]]--;
                }
                l++;
              }
          }
       
        }
         return ans;
    }
};