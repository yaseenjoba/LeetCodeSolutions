class Solution {
public:
    int characterReplacement(string str, int k) {
         int ans = 0;
        for(char c  = 'A' ; c <= 'Z' ; c++){
            int l = 0 , rep = k;
            for(int  r = 0;  r < str.size() ; r++){
                if(str[r] != c){
                  if(rep == 0){
                    while(rep == 0){
                      if(str[l]!=c)rep++;
                      l++;
                    }
                    rep--;
                  }else rep--;
                }
                ans = max(r - l + 1 , ans);
          }
        }
        return ans;
    }
};