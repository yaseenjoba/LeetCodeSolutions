class Solution {
public:
	int dp[1009][1009];

	// step 0: helper return max score
	int helper(vector<int>& nums, vector<int>& mul, int l, int i){
		// step 2: base condn.
		if(i == mul.size()){
			return 0;
		}

		if(dp[l][i] != INT_MIN){
			return dp[l][i];
		}

		// no. of moves of l +  no. of moves of r = no. of moves of i;
		// i = l + (nums.size() - 1 - r)
		int r = l + nums.size() - 1 - i;

		// step1: assume function returns what we want and call
		return dp[l][i] = max((mul[i] * nums[l]) + helper(nums, mul, l + 1, i + 1), 
				   (mul[i] * nums[r]) + helper(nums, mul, l, i + 1));
	}

	int maximumScore(vector<int>& nums, vector<int>& mul) {

		for(int i = 0; i < 1009; i++){
			for(int j = 0; j < 1009; j++){
				dp[i][j] = INT_MIN;
			}
		}

		return helper(nums, mul, 0, 0);
	}
};