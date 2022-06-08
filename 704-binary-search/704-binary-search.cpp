class Solution {
public:
    bool isValid(int x,vector<int>& nums,int target){
        return nums[x]>=target;
    }
//000000000000011111111111111
int bs(int st , int en,vector<int>& nums,int target){
    while(st<en){
        int mid= st+(en-st)/2;
         ///(st+end) /2 feeha b3d l m4akel [overflow ,
         if(isValid(mid,nums,target))
            en=mid;
         else
            st=mid+1;
    }
    return st;
}
    int search(vector<int>& nums, int target) {
        if(nums.size() == 1){
            if(nums[0] == target){
                return 0;
            }
            return -1;
        }
        int temp = bs(0,nums.size(),nums,target);
        return nums[temp]==target?temp:-1;
    }
};