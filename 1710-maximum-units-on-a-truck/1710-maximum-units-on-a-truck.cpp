class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin() , boxTypes.end(), [&](vector<int> &a , vector<int> &b){
            // if(a[0] == b[0]){
            //     return a[1] > b[1];
            // } 
            return a[1] > b[1];
        });
        int ans = 0;
        for(auto i : boxTypes){
            if(truckSize == 0)break;
            if(truckSize > i[0]){
                ans+= i[0]*i[1];
                truckSize-=i[0];
            }else{
                ans+= truckSize * i[1];
                truckSize = 0;
            }
            
        }
        return ans;
    }
};