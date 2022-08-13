class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>ans;
        unordered_map<string , int>target;
        for(auto &i : words){
            target[i]++;
        }
        int i = 0 ;
        int t = words[0].size();
        int w = words.size();
        int sz = s.size();
        while(i <= sz - t * w ){
            unordered_map<string , int>temp;
            for(int j = i ; j < i + t*w ;j+=t){
                string window = s.substr(j , t);
                temp[window]++;
            }
            if(temp == target)
                    ans.push_back(i);
            i++;
            
        }
        return ans;
    }
};