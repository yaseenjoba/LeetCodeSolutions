class Solution {
public:
    int minDeletions(string s) {
        map<char , int>mm;
        for(auto i : s){
            mm[i]++;
        }
        vector<int>v;
        for(auto i : mm){
            v.push_back(i.second);
        }
        sort(v.begin() , v.end());
        int n = v.size();
        int mi = v[n - 1];
        int ans = 0;
        for(int j = n -2 ; j>=0 ; j--){
            if(v[j] > max(mi - 1 , 0)){
                ans+= v[j] - max(mi - 1 , 0);
                v[j] = mi - 1;
            }
            mi = max(v[j] , 0);
        }
        return ans;
    }
};