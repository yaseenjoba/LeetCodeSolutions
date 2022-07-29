class Solution {
public:
    bool check(string & str , string &p){
        unordered_map<char , char>mm;       
        unordered_map<char , char>mm1;

        for(int  i = 0 ; i < str.size() ; i++){
            if(mm.count(str[i])){
                if(mm[str[i]] != p[i]){
                    return false;
                }
            }
            if(mm1.count(p[i])){
                if(mm1[p[i]] != str[i]){
                    return false;
                }
            }
            mm[str[i]] = p[i];
            mm1[p[i]] = str[i];
        }
        string t = "";
        for(auto i : str){
            t+= mm[i];
        }
        return t == p;
        
    }
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(auto s : words){
            if(check(s , pattern)){
                ans.push_back(s);
            }
        }
        return ans;
    }
};