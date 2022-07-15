class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        vector<int>has;
        for(int i = 0 ;i < matrix[0].size() ;i++){
            int ones = 0;
            for(int j = 0 ; j < matrix.size() ;j++){
                if(matrix[j][i] == 0){
                    ones = 0;
                    continue;
                }
                matrix[j][i]+= ones;
                ones++;
            }
        }
        for(int i = 0 ;i < matrix.size() ;i++){
            sort(matrix[i].rbegin() , matrix[i].rend());
        }
        int cnt = 1 , ans = 0;
         for(int i = 0 ;i < matrix.size() ;i++){
            for(int j = 0 ; j < matrix[0].size() ;j++){
                ans = max(ans, matrix[i][j] * (j + 1));
            }
        }
        return ans;
    }
};