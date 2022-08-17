class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
     vector<string>arr = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        set<string>s;
        for(auto i : words){
            string ans = "";
            for(auto c : i){
                ans+= arr[c - 'a'];
            }
            s.insert(ans);
        }
        return s.size();
    }
};