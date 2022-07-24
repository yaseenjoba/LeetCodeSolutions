class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        for(int i = 0 ; i < matrix.size() ; i++){
            auto x = upper_bound(matrix[i].begin() , matrix[i].end() , target - 1);
            if(x == matrix[i].end())continue;
            if(*x == target)return true;
        }
        return false;
    }
};