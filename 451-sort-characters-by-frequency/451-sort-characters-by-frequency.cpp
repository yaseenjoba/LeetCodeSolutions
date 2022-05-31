class Solution {
public:
    string frequencySort(string s) {
        map<char , int>mm;
        for(auto &i : s )mm[i]++;
        vector<pair<int , char>>v;
        for(auto i : mm)
            v.push_back({i.second , i.first});
        sort(v.rbegin() , v.rend());
        string ans = "";
        for(auto i : v){
            ans+= string(i.first , i.second);
        }
        return ans;
    }
};