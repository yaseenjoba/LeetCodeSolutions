class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size() , m = grid[0].size();
        queue<vector<int>>q;
        q.push({0 , 0 , k , 0});
        vector<vector<int>>vis(n , vector<int>(m  ,-1));
        while(!q.empty()){
            auto t = q.front();
            q.pop();
            if(t[0] >= n || t[0] < 0 || t[1] >=m || t[1] < 0)continue;
            if(t[0] == n - 1 & t[1] == m - 1)return t[3];
            if(grid[t[0]][t[1]]){
                t[2]--;
                if(t[2] < 0)continue;
            }
            if(vis[t[0]][t[1]] != -1 && vis[t[0]][t[1]] >= t[2]){
                continue;
            }
            vis[t[0]][t[1]]  =  t[2];
            q.push({t[0] + 1 , t[1] , t[2] , t[3] +  1});            
            q.push({t[0] , t[1] + 1 , t[2] , t[3] +  1});
            q.push({t[0] - 1 , t[1] , t[2] , t[3] +  1});
            q.push({t[0]  , t[1] - 1 , t[2] , t[3] +  1});
        }
        return -1;
    }
};