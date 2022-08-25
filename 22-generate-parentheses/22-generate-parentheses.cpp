class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        queue<pair<string , pair<int , int>>>q;
        q.push({"" , {0 , 0}});
        while(!q.empty()){
            pair<string , pair<int , int>>p = q.front();
            q.pop();
            if(p.second.first == n && p.second.second == n){
                ans.push_back(p.first);
            }
            if(p.second.first < n){
                q.push({p.first + '(' , {p.second.first + 1 , p.second.second}});
            }
             if(p.second.first > p.second.second && p.second.second < n){
                q.push({p.first + ')' , {p.second.first , p.second.second + 1}});
            }
        }
        return ans;
    }
};