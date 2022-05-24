class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        int stackSize = 0;
        int ans = 0 , j = 0;;
        st.push(-1);
        for(auto i: s){
            if(i == '('){
                st.push(j);
            }
            else{
                st.pop();
             
                if(st.empty()){
                    st.push(j);        
                }
                cout<<st.top()<<endl;
                ans = max(ans , j - st.top());
                
            }
            j++;
        }
        return ans;
    }
};