class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
        map<string, bool>exist;
        for(auto i : bank)exist[i] = true;
        queue<pair<string , int>>q;
        q.push({start , 0});
        map<string , bool>vis;
        while(!q.empty()){
            
            string str = q.front().first;
            int cost = q.front().second;
            if(str == end){
                return cost;
            }
            q.pop();
            if(vis[str])continue;
            vis[str] = true;
            for(int i = 0 ;i < str.size() ;i++){
                for(auto j : "ACGT"){
                    if(j != str[i]){
                        string temp = str.substr(0 , i) + string(1 , j) + str.substr(i + 1);
                        if(exist[temp]){
                            q.push({temp , cost + 1});
                        }
                    }
                }
                    
            }
            
        }
        return -1;
        
    }
};