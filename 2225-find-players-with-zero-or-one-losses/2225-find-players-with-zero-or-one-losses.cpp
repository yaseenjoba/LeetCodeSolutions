class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int>deg;
        for(auto &i : matches){
            deg[i[1]]++;            
            deg[i[0]]=deg[i[0]] ;

        }
        vector<int>one , nothing;
        for(auto i : deg){
            if(i.second == 0){
                nothing.push_back(i.first);
            }else if(i.second == 1){
                one.push_back(i.first);
            }
        }
        return {nothing, one};
        
    }
};