class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()  > s2.size())return false;
        vector<int>f1(26 , 0);        
        vector<int>f2(26 , 0);
        for(auto i : s1)f1[i - 'a']++;

        for(int i = 0 ; i < s1.size() ;i++){
            f2[s2[i] - 'a']++;
        }
        if(f1 == f2)return true;
        for(int i = s1.size() ; i < s2.size() ;i++){
            f2[s2[i] - 'a']++;
            f2[s2[i - s1.size()] - 'a']--;
            if(i)
            if(f1 == f2)return true; 
        }
        return false;

    }
};