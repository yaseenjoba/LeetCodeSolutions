class Solution {
public:
    int n, m;
    bool valid(int i , int j){
        if(i<0 || j<0 || i>=n||j>=m)return false;
        return true;
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();        
        m = heights[0].size();
        int dis[n + 1][m + 1];
        priority_queue<pair<int, pair<int , int>>> q;
        memset(dis, '?', sizeof dis);
        dis[0][0] = 0;
        q.push({0, {0  , 0}});
        while (!q.empty()) {
            pair<int, int> u = q.top().second;
            int d = -q.top().first;
            q.pop();
            int i = u.first , j = u.second;
            if(valid(i - 1 , j)){
                int new_i = i - 1 , new_j = j;
                int c = max(d ,abs(heights[new_i][new_j] - heights[i][j]));
                if(c < dis[new_i][new_j]){
                    dis[new_i][new_j] = c;
                    q.push({-c , {new_i , new_j}});
                }
            }
             if(valid(i  , j - 1)){
                int new_i = i , new_j = j - 1;
                int c = max(d ,abs(heights[new_i][new_j] - heights[i][j]));
                if(c < dis[new_i][new_j]){
                    dis[new_i][new_j] = c;
                    q.push({-c , {new_i , new_j}});
                }
            }
            if(valid(i + 1 , j)){
                int new_i = i + 1 , new_j = j;
                int c = max(d ,abs(heights[new_i][new_j] - heights[i][j]));
                if(c < dis[new_i][new_j]){
                    dis[new_i][new_j] = c;
                    q.push({-c , {new_i , new_j}});
                }
            }
             if(valid(i , j + 1)){
                int new_i = i , new_j = j + 1;
                int c = max(d ,abs(heights[new_i][new_j] - heights[i][j]));
                if(c < dis[new_i][new_j]){
                    dis[new_i][new_j] = c;
                    q.push({-c , {new_i , new_j}});
                }
            }

        }
        return dis[n - 1][m - 1];

    }
};