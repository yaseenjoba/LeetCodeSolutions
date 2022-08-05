class Solution {
public:
    string minWindow(string str, string pattern) {
    int ansL  = -1, ansR = -1 , ans = 1e9;
    int l = 0;
    unordered_map<char ,int>freq;
    for(auto i : pattern)freq[i]++;
    int matched = 0;
    for(int r = 0 ; r < str.size() ; r++){
        if(freq.count(str[r])){
          freq[str[r]]--;
          if(freq[str[r]] == 0)matched++;
        }
        while(matched == freq.size()){
          if(r - l + 1 < ans){
              ans = r - l + 1;
              ansL = l , ansR = r;
          }
           if(freq.count(str[l])){
             freq[str[l]]++;
             if(freq[str[l]] == 1)matched--;
           }
           l++;
        }
    }
    if(ans == 1e9)return "";
    return str.substr(ansL , ansR - ansL + 1);
    }
};