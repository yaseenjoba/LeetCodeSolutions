class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int mx = 0;
        for(int i = 0; i<nums.size() - 2 ;i++){
            int a = nums[i] , b= nums[i + 1] , c = nums[i + 2];
            if(a + b > c && a+ c> b && c + b > a){
                mx = max(a + b + c , mx);
            }
        }
        return mx;
    }
};