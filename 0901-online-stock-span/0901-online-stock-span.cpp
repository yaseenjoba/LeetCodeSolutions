class StockSpanner {
public:
    vector<int>v;
    stack<int>st;
    int i;
    StockSpanner() {
        i = 0;
    }
    // 70 70 60 70 60
    int next(int price) {
        v.push_back(price);
        while(!st.empty() && v[st.top()] <= price)
            st.pop();
        int ans = 0;
        if(st.empty())ans =  i + 1;
        else ans = i - st.top();
        st.push(i);
        i++;
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */