class Solution {
public:
    int ans , d ,kk;
    vector<vector<int>>adj;    
    vector<int>vis;
    vector<vector<int>>cost;
    void dfs(int u , int level , int co){
        if(u == d && (level - 2)<=kk){
            ans = min(ans  , co);
        }
        vis[u] = true;
        for(auto v : adj[u]){
            if(vis[v])continue;
            dfs(v , level + 1 , co + cost[u][v]);
        }
        vis[u] = false; 
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        cost.assign(n + 1, vector<int>(n + 1 , false));
        adj.resize(n + 1);
        vis.resize(n + 1);
        for(auto v : flights){
            cost[v[0]][v[1]] = v[2];
            adj[v[0]].push_back(v[1]);
        }
        d = dst;
        ans = 1e9;
        queue<pair<int ,pair<int, int>>>q;
        vector<int>mini(n + 1 , 1e9);
        
        q.push({src , {k + 1 , 0}});
        while(!q.empty()){
            pair<int, pair<int, int>>p = q.front();
            q.pop();
            if(mini[p.first] < p.second.second)continue;
            mini[p.first] = min(mini[p.first] , p.second.second);
            if(p.first == dst){
                ans = min(ans , p.second.second);
            }
            for(auto i : adj[p.first]){
                if(p.second.first == 0)break;
                q.push({i ,{ p.second.first - 1, mini[p.first] + cost[p.first][i]}});
            }
        }
        return ans==1e9?-1:ans;
    }
};