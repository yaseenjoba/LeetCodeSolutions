class Solution {
public:
    int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
        vector<pair<int, int>>v;
        for(int i = 0 ; i < plantTime.size() ;i++){
            v.push_back({plantTime[i] , growTime[i]});
        }
        sort(v.begin() , v.end() ,[&](pair<int, int>&a , pair<int, int> &b){
            return a.second > b.second;
        } );
        int ans = 0 , day = 0;
        for(auto i : v){
            day+=i.first;
            ans = max(day + i.second , ans);
        }
        return ans;
    }
};