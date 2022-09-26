class Solution {
public:
    vector<int>adj[28];
    int vis[27];
    int idx;
    void dfs(int u){
        vis[u] = idx;
        for(auto v : adj[u]){
            if(vis[v] !=-1)continue; 
            dfs(v);
        }
    }
    bool equationsPossible(vector<string>& equations) {
        idx = 0;
        memset(vis , -1 , sizeof vis);
        for(auto i : equations){
            if(i[1] == '='){
                adj[i[0] - 'a'].push_back(i[3] - 'a');
                adj[i[3] - 'a'].push_back(i[0] - 'a');  
            }    
        }
        for(auto i : equations){
            if(i[1] == '=' && vis[i[0] - 'a'] == -1){
               idx++;
               dfs(i[0] - 'a');
            }    
        }
        for(auto i : equations){
            if(i[1] == '!' && i[0] == i[3])return false;
            if(i[1] == '!' && vis[i[0] - 'a'] == vis[i[3] - 'a'] && vis[i[3] - 'a']!=-1){
               return false;
            }    
        }
        return true;
        
    }
};