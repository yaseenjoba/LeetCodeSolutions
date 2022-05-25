class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        //sort by the first element.
        sort(env.begin() , env.end(),[&](vector<int>&a , vector<int>&b){
            if(a[0]==b[0]) return a[1] > b[1];
            return a[0] < b[0];
        });
        vector<int>v;
        for(int i = 0 ; i < env.size() ; i++){
            //find LIS using second element;
            int x = env[i][1];
            int indx  = lower_bound(v.begin() , v.end() , x) - v.begin();       
            if(indx >= v.size())v.push_back(x);
            else v[indx] = x;
        }
        int ans = v.size();
        return ans;
        
        
    }
};