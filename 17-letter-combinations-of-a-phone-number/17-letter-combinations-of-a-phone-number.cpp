class Solution {
public:
    void sol(string str , int i , string& digits  , vector<string>&ans){
        if(i == digits.size()){
            ans.push_back(str);
            return;
        }
        char c = digits[i];
        if(c == '2'){
            string t = "abc";
            for(auto k : t){
                sol(str + k , i + 1 , digits , ans);
            }
        }
        else if(c == '3'){
            string t = "def";
            for(auto k : t){
                sol(str + k , i + 1 , digits , ans);

            }
        }else if(c == '4'){
            string t = "ghi";
            for(auto k : t){
                sol(str + k , i + 1 , digits , ans);
            }
        }else if(c == '5'){
            string t = "jkl";
            for(auto k : t){
                sol(str + k , i + 1 , digits , ans);
            }
        }else if(c == '6'){
            string t = "mno";
            for(auto k : t){
                sol(str + k , i + 1 , digits , ans);
            }
        }else if(c == '7'){
            string t = "pqrs";
            for(auto k : t){
                sol(str + k , i + 1 , digits , ans);
            }
        }else if(c == '8'){
            string t = "tuv";
            for(auto k : t){
                sol(str + k , i + 1 , digits , ans);
            }
        }else if(c == '9'){
            string t = "wxyz";
            for(auto k : t){
                sol(str + k , i + 1 , digits , ans);
            }
        }  
        
    }
    vector<string> letterCombinations(string digits) {
       vector<string>ans;
       if(digits.empty())return ans;
       sol("" , 0 , digits , ans);
        return ans;
    }
};