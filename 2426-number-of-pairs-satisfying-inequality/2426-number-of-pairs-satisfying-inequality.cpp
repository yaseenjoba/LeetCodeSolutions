#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ordered_multiset s;
        long long ans = 0;
        for(int i = 0 ; i < nums2.size() ;i++){
            ans+= s.order_of_key(nums1[i] - nums2[i] + 1);
            s.insert(nums1[i] - nums2[i]  - diff);
        }
        return ans;

    }
};