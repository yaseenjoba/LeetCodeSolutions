class Solution {
public:
    string reverseWords(string s) {
        stringstream ss (s);
        string str;
        vector<string>v;
        while(ss>>str){
            v.push_back(str);
        }
        reverse(v.begin() , v.end());
        string ans = "";
        for(auto  i  : v)ans+=i+" ";
        ans.pop_back();
        return ans;
    }
};