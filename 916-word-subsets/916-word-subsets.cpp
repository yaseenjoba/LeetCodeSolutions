class Solution {
public:
    unordered_map<char , int> count(string &s){
        unordered_map<char , int>mm;
        for(auto i : s)mm[i]++;
        return mm;
    }
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> maxFreq;
        
        for(auto s : words2) {
            unordered_map<char, int> f = count(s);
            for(char c : s)
                maxFreq[c] = max(maxFreq[c], f[c]);
        }
        
        vector<string> ans;
        for(auto s : words1) {
            unordered_map<char, int> temp = maxFreq;
            for(auto c : s) {
                if(temp.find(c) == temp.end()) continue;
                temp[c]--;
                if(!temp[c]) temp.erase(c);
            }
            if(!temp.size()) ans.push_back(s);
        }
        
        return ans;
    }
};