class Solution {
public:
    string capitalizeTitle(string title) {
        vector<string>str;
        string word = "";
        for(auto &i : title){
            i = tolower(i);
        }
        for(auto &i : title){
            if(i ==' '){
               str.push_back(word);
               word = "";
               continue;
            }
           word+=i;
        }
        str.push_back(word);
        for(auto &i : str){
            if(i.size() > 2){
                i[0] = toupper(i[0]);
            } 
        }
        string ans = "";
        int j = 0;
        for(auto &i : str){
            ans+=i;
            if(j!=str.size() - 1)
                ans+=" ";
            j++;
        }
        return ans;
    }
};