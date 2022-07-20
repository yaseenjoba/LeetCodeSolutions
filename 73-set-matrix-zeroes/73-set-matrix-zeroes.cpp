class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        unordered_set<int>rows , cols;
        for(int i = 0 ; i < matrix.size() ;i++){
             for(int j = 0 ; j < matrix[0].size() ;j++){
                if(matrix[i][j] == 0){
                    rows.insert(i);                    
                    cols.insert(j);

                }
            }
        }
        for(auto j : rows){
            for(int i = 0 ; i < matrix[0].size() ;i++){
                matrix[j][i] = 0;
            }
        }
         for(auto j : cols){
            for(int i = 0 ; i < matrix.size() ;i++){
                matrix[i][j] = 0;
            }
        }
    }
};