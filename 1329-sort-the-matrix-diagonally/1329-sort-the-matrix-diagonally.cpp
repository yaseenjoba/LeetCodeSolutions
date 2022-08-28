class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        for(int c  =0 ; c < mat[0].size() ; c++){
            vector<int>v;
            int col = c;
            int r = 0;
            while(r < mat.size() && col < mat[0].size()){
                v.push_back(mat[r][col]);
                r++,col++;
            }
            sort(v.rbegin() , v.rend());
            col = c , r = 0;
            while(r < mat.size() && col < mat[0].size()){
                mat[r][col] = v.back();
                v.pop_back();
                r++,col++;
            }
            
        }
         for(int r  = 1 ; r < mat.size() ; r++){
            vector<int>v;
            int col = 0;
            int row = r;
            while(row < mat.size() && col < mat[0].size()){
                v.push_back(mat[row][col]);
                row++,col++;
            }
            sort(v.rbegin() , v.rend());
            col = 0 , row = r;
            while(row < mat.size() && col < mat[0].size()){
                mat[row][col] = v.back();
                v.pop_back();
                row++,col++;
            }
        }
        return mat;
    }
};