#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        ordered_multiset s;
        vector<int>ans;
        for(int i = nums.size() - 1 ; i >=0; i--){
            s.insert(nums[i]);
            ans.push_back(s.order_of_key(nums[i]));
        }
        reverse(ans.begin() ,ans.end());
        return ans;
    }
};