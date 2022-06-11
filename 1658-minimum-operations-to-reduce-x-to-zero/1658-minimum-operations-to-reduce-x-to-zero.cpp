class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        long long ans = 1e9;
         long long sum = 0;
         long long op = 1;
        map< long long,  long long>mm;
         long long n = nums.size();
        for(int i = n - 1 ; i >=0 ;i--){
            sum+=nums[i];
            mm[sum] = op++;
            
        }
        if(mm.count(x)){
            ans = mm[x];
        }
         long long taken = 0;
        mm[0] = 0;
        for(int i = 0 ; i< n ; i++){
            taken+=nums[i];
            mm[sum]  = -1;
            sum-=taken;
            if(mm.count(x - taken) && mm[x - taken]!=-1){
                ans = min(mm[x - taken] + i + 1 , ans);
            }
        }
        if(ans == 1e9){
            return -1;
        }
        return ans;
        
    }
};