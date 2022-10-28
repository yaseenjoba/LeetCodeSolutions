class Solution {
public:
    void countSort(string &str){
        string ans = "";
        vector<int>freq(26 , 0);
        for(auto i : str)freq[i - 'a']++;
        for(int i = 0 ;i < 26 ;i++){
            ans+= string(freq[i] , i + 'a');
        }
        str = ans;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string , vector<string>>mm;
        for(auto i : strs){
            auto v = i;
            countSort(v);
            mm[v].push_back(i);
        }
        vector<vector<string>>ans;
        for(auto i : mm){
            ans.push_back(i.second);
        }
        return ans;
        
    }
};