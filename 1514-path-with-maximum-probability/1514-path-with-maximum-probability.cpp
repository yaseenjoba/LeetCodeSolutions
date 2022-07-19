class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& p, int start, int end) {
        vector<vector<pair<int ,double>>>adj(n  + 1 , vector<pair<int ,double>>());
        for(int i = 0 ; i < edges.size() ; i++){
            vector<int>v = edges[i];
            adj[v[0]].push_back({v[1] , p[i]});            
            adj[v[1]].push_back({v[0] , p[i]});
        }
        priority_queue<pair<double ,int>>pq;
        pq.push({1 , start});
        vector<double>dis(n + 1 , 0);
        while(!pq.empty()){
            int u = pq.top().second;            
            double c = pq.top().first;
            pq.pop();
            for(auto i : adj[u]){
                int v =  i.first ;
                double e = i.second;
                if(c * e > dis[v]){
                    dis[v] = c*e;
                    pq.push({dis[v] , v});
                }
            }
        }
        return dis[end];
    }
};