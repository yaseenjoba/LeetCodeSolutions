class Solution {
public:
    string w;
    bool check(int i, int j, vector<vector<char>>& board, int idx , string &str){
        if(idx == w.size())return true;
        if(i >=board.size() || j>=board[0].size() || i<0 ||j<0  || w[idx]!=board[i][j] || board[i][j] == ' ')return false;
        char temp = board[i][j];
        board[i][j] =' ';
        bool op1 =  check(i + 1 , j , board,idx  + 1 , str); 
        bool op2 =  check(i , j  + 1, board, idx + 1 , str);
        bool op3 =  check(i , j  - 1, board, idx + 1 , str); 
        bool op4 = check(i - 1 , j , board, idx  + 1 , str);
        board[i][j] = temp;
        return op1 || op2 || op3 || op4;

    }
    bool exist(vector<vector<char>>& board, string word) {
        w = word;
        string str = "";
        for(int i =0; i < board.size() ; i++){
            for(int j =0; j < board[0].size() ; j++){
                if(board[i][j] == w[0]){
                    if(check(i ,j ,board, 0 , str))return true;
                }
            } 
        }
        return false;
    }
};