class NumMatrix {
public:
    vector<vector<int>>mat;
    NumMatrix(vector<vector<int>>& matrix) {
        vector<vector<int>>v;
        for(auto i : matrix){
            v.push_back(i);   
        }
        for(auto &m : v){
            for(int i = 1;  i < m.size() ;i++){
                m[i]+=m[i - 1];
            }
        }
        mat = v;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ans = 0;
        for(int i = row1 ;  i <= row2 ;i++){
             int l = col1 -1;
             int  r = col2;
             ans+= mat[i][r] - (l < 0? 0 : mat[i][l]);
        }
        return ans;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */