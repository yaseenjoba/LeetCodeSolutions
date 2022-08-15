class Solution {
public:
    int romanToInt(string s) {
        map<char,int>mp;
        mp['I'] = 1;       
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;
        int value = 0;
        for(int i = 0;i<s.size()-1;i++){
            if(mp[s[i]]<mp[s[i+1]]){
                value-=mp[s[i]];
            }else value+=mp[s[i]];
        }
        value+=mp[s[s.size()-1]];
        return value;

        
        
    }
};