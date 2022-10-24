class Solution {
public:
    int sol(vector<int>& freq , vector<string>& arr , int i){
        if(i == arr.size())return 0;
        int m1 = 0,  m2 = 0;
        vector<int>f(26 , 0);
        bool is = false;
        for(auto i : arr[i]){
            f[i - 'a']++;
            if(freq[i - 'a'] !=0 || f[i -'a'] == 2){
                is = true;
                break;
            }
        }
        
        if(!is){
            for(int i = 0 ;i<26;i++){
                freq[i]+=f[i];
            }
            m1 = arr[i].size() + sol(freq, arr , i  + 1);
            for(int i = 0 ;i<26;i++){
                freq[i]-=f[i];
            }
        }
        m2 = sol(freq, arr , i + 1);
        return max(m1 ,m2);
    }
    int maxLength(vector<string>& arr) {
        vector<int>freq(26 , 0);
        return sol(freq , arr , 0);
    }
};