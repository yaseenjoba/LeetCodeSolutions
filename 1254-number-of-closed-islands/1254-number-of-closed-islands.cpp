class Solution {
public:
    bool vis[102][102] , valid;
    void dfs( vector<vector<int>>& arr ,int i , int j , int n ,int m){
            if(i >= n || j>=m || i<0 ||j<0 || vis[i][j] || arr[i][j] == 1)return; 
            if((i == 0 || i == arr.size() - 1 || j == arr[0].size() - 1 || j == 0) && arr[i][j] == 0 && valid == true){
                valid = false;
            }
            vis[i][j] = true;
            dfs(arr, i + 1 , j , n, m);            
            dfs(arr , i - 1 , j ,n ,m);
            dfs(arr ,i  , j + 1,n , m);
            dfs(arr ,i  , j - 1, n ,m);
    }
    int closedIsland(vector<vector<int>>& arr) {
        memset(vis ,0 ,sizeof vis);
        int ans = 0;
        for(int i = 0; i < arr.size() ; i++){
                for(int j = 0; j < arr[0].size() ; j++){
                        if(!vis[i][j] && arr[i][j] == 0){
                            valid = true;
                            dfs(arr ,i , j, arr.size() , arr[0].size());
                            if(valid) ans++;
                        }
                        
                }
        }
        return ans;
    }
};