class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        int idx = 0;
        for(auto i : s){
            if(i == '('){
                st.push(idx);
            }else if(i == ')'){
                if(!st.empty())st.pop();
                else s[idx] = '#';
            }
            idx++;
        }
        while(!st.empty()){
            s[st.top()] = '#';
            st.pop();
        }
        string ans = "";
        for(auto i : s){
            if(i!='#'){
                ans+=i;
            }
        }
        return ans;
    }
};