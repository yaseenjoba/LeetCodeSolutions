class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int ,int>mm;
        for(auto i : arr)mm[i]++;
        vector<int>v;
        for(auto &i : mm){
            v.push_back(i.second);
        }
        sort(v.rbegin() , v.rend());
        int n = arr.size();
        int removed = 0;
        int ans = 0;
        for(auto i : v){
            removed+=i;
            ans++;
            if(removed  * 2 >= n){
                break;
            }
        }
        return ans;
    }
};