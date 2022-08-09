
class Solution {
public:
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin() , arr.end());
        unordered_map<long long  , long long >freq;
        int mod = 1e9 + 7;
        freq[arr[0]] = 1;
        for(int i = 1 ; i < arr.size() ;i++){
            long long  count =  1;
            for(auto j : freq){
                int c = j.first;
                if(arr[i] % c == 0 && freq.count(arr[i] / c)){
                    count+= freq[c] * freq[arr[i] / c];
                }
            }
            freq[arr[i]] = count;
        }
        long long  ans = 0;
        for(auto  i : freq){
            ans += i.second%mod;
            ans%=mod;
        }
        return ans;
    }
};