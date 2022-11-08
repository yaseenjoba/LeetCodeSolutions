class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
        for(auto i : s){
            if(!st.empty() && tolower(st.top()) == tolower(i)){
                if((islower(st.top()) && isupper(i)) || (isupper(st.top()) && islower(i))){
                    st.pop();
                    continue;
                }
            }
            st.push(i);
        }
        string str = "";
        while(!st.empty()){
            str+=st.top();
            st.pop();
        }
        reverse(str.begin() , str.end());
        return str;
    }
};