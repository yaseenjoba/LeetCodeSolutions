class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            if(a%2==0 && b%2==0){
                return a<b; 
            }
            if(a%2!=0 && b%2!=0){
                return a<b; 
            }
            if(a%2==0){
                return true;
            }
            return false;
            
            
        });
            return nums;
    }
};