class Solution {
public:
    string reverseWords(string s) {
        vector<string>v;
        string k = "";
        for(auto &i : s){
            if(i == ' '){
                v.push_back(k);
                k="";
                continue;
            }
            k+=i;
        }
        v.push_back(k);
        for(auto &i : v){
            reverse(i.begin() , i.end());
        }
        string ans = "";
        int ind = 0;
        for(auto &i : v){
            ans+= i;
            if(ind == v.size() - 1)break;
            ans+=" ";
            ind++;
        }
        return ans;
    }
};