class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>indegree(numCourses , 0);
        vector<vector<int>>adj(numCourses , vector<int>());
        for(auto i : prerequisites){
            indegree[i[0]]++;
            adj[i[1]].push_back(i[0]);
        }
        queue<int>q;
        for(int i = 0 ; i < numCourses ; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int>ans;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            ans.push_back(u);
            for(auto i : adj[u]){
                indegree[i]--;
                if(indegree[i] == 0)
                    q.push(i);
            }
        }
        if(ans.size() == numCourses){
            return ans;
        }
        ans.clear();
        return ans;
    }
};