class Solution {
public:
    vector<vector<int>>ans;
	void dfs ( vector<int> &candidates, int target, vector<int> &cur_path, int start )
	{
		if ( target < 0 ) return;
		if ( target == 0 )
		{
			ans.push_back(cur_path);
			return;
		}
		
		for ( ; start < candidates.size(); ++start )
		{
			cur_path.push_back( candidates[start] );
			dfs ( candidates, target - candidates[start], cur_path, start );
			cur_path.pop_back();
		}
	}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>curr;
        dfs(candidates ,target , curr , 0);
        vector<vector<int>>res(ans.begin() , ans.end());
        return res;
    }
};