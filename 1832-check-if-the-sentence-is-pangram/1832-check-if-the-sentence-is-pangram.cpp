class Solution {
public:
    bool checkIfPangram(string sentence) {
        map<char,bool>mp;
        for(int i=0;i<sentence.size();i++){
            mp[sentence[i]] = true;
        }
        for(char i = 'a';i<='z'; i++){
            if(mp[i] == false){
                return false;
            }
        }
        return true;
    }
};