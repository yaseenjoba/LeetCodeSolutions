class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string str1 = "" , str2 = "";
        for(auto i : s){
            if(i == '#' && str1.size())str1.pop_back();
            else if(i !='#') str1.push_back(i);  
        }
         for(auto i : t){
            if(i == '#' && str2.size())str2.pop_back();
            else if(i !='#') str2.push_back(i);  
        }
        cout<<str1<<endl;
        cout<<str2<<endl;
        return str1 == str2;
        
    }
};