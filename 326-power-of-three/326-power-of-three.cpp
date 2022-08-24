class Solution {
public:
    bool isPowerOfThree(int n) {
         if(n==0)return false;
        if(n<0) return false;
        int c = ceil((log(n) / log(3)));
        cout<<c<<endl;
        return pow(3,c) == n;
    }
};