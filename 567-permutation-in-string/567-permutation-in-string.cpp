class Solution {
public:
    bool checkInclusion(string pattern, string str) {
      if(pattern.size() > str.size())return false;
      vector<int>target(26 , 0) , freq(26 , 0);
      for(auto  i : pattern){
        target[i - 'a']++;
      }

      int l = 0 , r = pattern.size() - 1;
      for(int i = l ; i <= r ;i++){
        freq[str[i] - 'a']++;
      }

      while(r + 1 < str.size()){
        if(freq == target){
          return true;
        }
        r++;
        freq[str[r] - 'a']++;
        freq[str[l] - 'a']--;
        l++;
      }
      return freq == target;
    }
};