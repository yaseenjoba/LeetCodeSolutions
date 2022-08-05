class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        map<int,int> m;
        int ans = 0,j = 0;
        for(int i=0;i<fruits.size();i++){
            m[fruits[i]]++;
            if(m.size()<=2){
                int cnt = 0;
                for(auto it:m){
                    cnt += it.second;
                }
                ans = max(ans,cnt);
            }
            else{
                while(m.size()>2){
                    if(m[fruits[j]]==1){
                        m.erase(fruits[j]);
                    }
                    else{
                        m[fruits[j]]--;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};