class Solution {
public:
    vector<int>adj[100001];
    vector<string>v;
    bool vis[100001];
    void dfs(int i , map<int , string>& d){
        vis[i] = true;
        v.push_back(d[i]);
        for(auto u : adj[i]){
            if(vis[u])continue;
            dfs(u , d);
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        map<string , int>hash; 
        map<int , string>hashBack;
        map<string , string>forp;
        int idx = 1;
        for(auto i : accounts){
            for(int j = 1; j < i.size() ;j++){
                forp[i[j]] = i[0];
                if(hash.count(i[j]))continue;
                hash[i[j]] = idx++;
                hashBack[hash[i[j]]] = i[j];
            }
        }
        
          for(auto i : accounts){
            for(int j = 1; j < i.size() ;j++){
                   for(int k = 1; k < i.size() ;k++){
                       if(j == k)continue;
                        adj[hash[i[j]]].push_back(hash[i[k]]);                        
                        adj[hash[i[k]]].push_back(hash[i[j]]);
                }
            }
        }
        vector<vector<string>>ans;
        for(int i = 1 ; i < idx ;i++){
            if(!vis[i]){
                v.clear();
                v.push_back(forp[hashBack[i]]);
                dfs(i , hashBack);
                sort(v.begin() + 1 , v.end());
                ans.push_back(v);
            }
        }
        return ans;
        
    }
};