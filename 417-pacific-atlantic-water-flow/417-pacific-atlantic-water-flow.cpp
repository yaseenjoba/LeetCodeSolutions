class Solution {
public:
   void dfs(vector<vector<int>>& grid , int i , int j , int prev , vector<vector<int>>&ocean)
    {
        if(i<0 || j<0 || i>=grid.size() || j>=grid[0].size()){
            return;
        }
        
        if(grid[i][j]<prev){
            return;
        }
        
        if(ocean[i][j]==-1){
            return;
        }
        
        ocean[i][j]=-1;
        
        dfs(grid,i+1,j,grid[i][j],ocean);
        dfs(grid,i,j+1,grid[i][j],ocean);
        dfs(grid,i-1,j,grid[i][j],ocean);
        dfs(grid,i,j-1,grid[i][j],ocean);
        
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& grid) {
         vector<vector<int>>ans;
        
        if(grid.size()==0){
            return ans;
        }
        
        int n = grid.size();
        int m = grid[0].size();
        
        vector<vector<int>>pacific(n,vector<int>(m,0));
        vector<vector<int>>atlantic(n,vector<int>(m,0));
        
        for(int j=0;j<m;j++)
        {
            dfs(grid,0,j,INT_MIN,pacific);
            dfs(grid,n-1,j,INT_MIN,atlantic);
        }
        
        for(int i=0;i<n;i++)
        {
            dfs(grid,i,0,INT_MIN,pacific);
            dfs(grid,i,m-1,INT_MIN,atlantic);
        }
        
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(pacific[i][j]==-1 and pacific[i][j]==atlantic[i][j])
                {
                   ans.push_back({i,j});
                }
            }
        }
        
        return ans;
    }
};