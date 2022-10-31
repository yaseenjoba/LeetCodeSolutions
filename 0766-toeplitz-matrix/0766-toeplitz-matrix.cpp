class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int t = 0 ; t < matrix[0].size(); t++){
            set<int>s;
            int i = 0 , j = t;
            while(i < matrix.size() && j < matrix[0].size()){
                s.insert(matrix[i][j]);
                i++,j++;
            }
            if(s.size() != 1)return false;
            
        }
         for(int t = 0 ; t < matrix.size(); t++){
            set<int>s;
            int i = t , j = 0;
            while(i < matrix.size() && j < matrix[0].size()){
                s.insert(matrix[i][j]);
                i++,j++;
            }
            if(s.size() != 1)return false;
            
        }
        return true;
    }
};