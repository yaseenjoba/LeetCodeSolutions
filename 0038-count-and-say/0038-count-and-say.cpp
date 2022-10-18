class Solution {
public:
    string spill(string x){
        int i = 0;
        string ans = "";
        while(i < x.size()){
            int cnt = 0;
            int t = x[i];
            while(t == x[i])i++,cnt++;
            ans+=to_string(cnt) + x[i - 1];
        }
        return ans;
    }
    string countAndSay(int n) {
        string str = "1";
        n--;
        while(n--){
            str = spill(str);
        }
        return str;
    }
};