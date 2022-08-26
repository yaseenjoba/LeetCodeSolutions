class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string str = to_string(n);
        sort(str.begin() , str.end());
        do{
            if(str[0]!='0'){
                int t = stoi(str);
                int x = log(t)/log(2);
                if(pow(2 , x) == t)return true;
            }
        }while(next_permutation(str.begin() , str.end()));
        return false;
    }
};