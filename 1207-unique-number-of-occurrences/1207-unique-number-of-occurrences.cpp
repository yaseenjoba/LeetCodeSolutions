class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int freq[3000];
        memset(freq,-1,sizeof freq);
        for(int i=0;i<arr.size();i++){
            freq[arr[i]+1000]++;
        }
        bool t[2000];
    memset(t,false,sizeof t);

        for(int i=0;i<3000;i++){
            if(freq[i]==-1)continue;
            if(t[freq[i]]==true){
                return false;
            }
            t[freq[i]]=true;
        }
        return true;
    }
};