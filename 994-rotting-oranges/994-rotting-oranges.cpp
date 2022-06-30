class Solution {
public:
    int x , y;
    bool check(int i  , int j ,vector<vector<int>>& grid){
        bool rotten  = false;
        if(i - 1 >= 0 && grid[i - 1][j] == 2)rotten = true;        
        if(j - 1 >= 0 && grid[i][j - 1] == 2)rotten = true;        
        if(i + 1 < x && grid[i + 1][j] == 2)rotten = true;
        if(j + 1 < y && grid[i][j + 1] == 2)rotten = true;
        return rotten;
    }
    int orangesRotting(vector<vector<int>>& grid) {
         x = grid.size();        
         y = grid[0].size();
        for(int m = 0 ; m < 1000 ; m++){
            int rotten = 0;
            int all = 0;
            vector<vector<int>>newgrid = grid;
            for(int i = 0 ; i <grid.size() ;i++){
                for(int j = 0 ; j <grid[i].size() ;j++){
                    all+= grid[i][j] != 0;
                    rotten+= grid[i][j] == 2;
                    if(grid[i][j] == 1 && check(i , j , grid)){
                        newgrid[i][j] = 2;
                    }
                }
            }
            grid = newgrid;
            if(rotten == all)return m;
        }
        return -1;
    }
};