class Solution {
public:
    vector<int> findOriginalArray(vector<int>& arr) {
    
        sort(arr.begin(), arr.end());
        // reverse(arr.begin() , arr.end());
        unordered_map<int ,int>mm;
        for(auto i : arr){
            mm[i]++;
        }
        vector<int>ans;
        for(auto i : arr){
           if(mm[i*2] && mm[i]){
               if(i == (i*2) && mm[i] == 1)continue;
               ans.push_back(i);
               mm[i]--;
               mm[i*2]--;               
           } 
        }
        if(ans.size()!= arr.size()/2 || (arr.size() & 1)){
            ans.clear();
            return ans;
        }
        return ans;
        
        
    }
};