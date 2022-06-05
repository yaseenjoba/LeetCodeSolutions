class Solution {
public:
    vector<vector<string>>ans;
    bool can(int col , int r, int n , vector<string> &mat){
        int itc =col;
        while(itc >= 0){
            if(mat[itc][r] == 'Q')return false;
            itc--;
        }
        itc = col;
        int itr  = r;
        while(itc >= 0 && itr >= 0){
            if(mat[itc][itr] == 'Q')return false;
            itc--;
            itr--;
        }
        itc = col;
        itr  = r;
        while(itc >= 0  && itr < n){
            if(mat[itc][itr] == 'Q')return false;
            itc--;
            itr++;
        }
        return true;
    }
    void sol(int col , int n , vector<string> mat){
        if(col == n){
            ans.push_back(mat);
            return;
        }
        for(int r = 0; r < n;r++){
            if(can(col , r ,n, mat)){
                mat[col][r] = 'Q';
                sol(col + 1 , n , mat);
                mat[col][r] = '.';
            }
        }
    }
    int totalNQueens(int n) {
         vector<string>c;
        c.assign(n , string(n , '.'));
        sol(0 , n , c);
        return ans.size();
    }
};