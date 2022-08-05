class Solution {
public:
    vector<int> findAnagrams(string str, string pattern) {
    vector<int> resultIndices;
    if(pattern.size() > str.size())return resultIndices;
    vector<int>freq(26 , 0) , target(26 , 0);
    for(auto i : pattern){
      target[i - 'a']++;
    }
    int r = pattern.size() - 1 , l = 0; 
    for(int i = l; i <= r ; i++){
      freq[str[i] - 'a']++;
    }
    while(r + 1 < str.size()){
      if(freq == target){
        resultIndices.push_back(l);
      }
      r++;
      freq[str[r] - 'a']++;
      freq[str[l++] - 'a']--;
    }
    if(freq == target){
        resultIndices.push_back(l);
    }
    return resultIndices;
    }
};