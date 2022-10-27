class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        vector<pair<int ,int>> idx1 , idx2;
        map<pair<int ,int> , int>mm;
        for(int i = 0 ;i < img1.size() ; i++){
            for(int j = 0 ;j < img2.size() ; j++){
                if(img1[i][j] == 1){
                    idx1.push_back({i, j});
                } 
                if(img2[i][j] == 1){
                    idx2.push_back({i, j});
                }
            }
        }
        int ans = 0;
        for(auto i : idx1){
                for(auto j : idx2){
                    int x = i.first - j.first;
                    int y = i.second - j.second;
                    mm[{x , y}]++;
                    ans = max(mm[{x , y}] , ans);
                }
        }
        return ans;
    }
};