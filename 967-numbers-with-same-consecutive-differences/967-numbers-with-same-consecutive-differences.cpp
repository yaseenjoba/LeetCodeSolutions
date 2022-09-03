class Solution {
public:
    int req , inc;
    vector<int>ans;
    void dfs(int last, int n , string s){
        if(last < 0 || last >9)return;
        if(n == req){
            ans.push_back(stoi(s));
            return;
        }
        if(inc == 0){
             s+= (last + inc)+'0';
             dfs(last + inc , n + 1 , s);
            s.pop_back();
        }else{
            s+= (last + inc)+'0';
            dfs(last + inc , n + 1 , s);
            s.pop_back();
            s+= (last - inc)+'0';
            dfs(last - inc , n + 1 , s);
            s.pop_back();
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        req = n;
        inc = k;
        for(int i = 1;  i<= 9;i++){
            dfs(i , 1 , string(1 , i +'0'));
        }
        return ans;
    }
};