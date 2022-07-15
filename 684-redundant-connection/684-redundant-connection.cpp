class Solution {
public:
    vector<int>parent;
    int find_parent(int x){
        return parent[x] == -1 ? x : find_parent(parent[x]);
    }
    void unionf(int x  , int y){
        parent[find_parent(x)] = find_parent(y);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        vector<int>ans;
        int n = edges.size() + 1;
        parent.assign(n , -1);
        for(auto i : edges){
            int x = i[0] , y =i[1];
            if(find_parent(x) == find_parent(y)){
                ans = i;
                break;
            }
            unionf(x , y);
        }
        return ans;
    }
};