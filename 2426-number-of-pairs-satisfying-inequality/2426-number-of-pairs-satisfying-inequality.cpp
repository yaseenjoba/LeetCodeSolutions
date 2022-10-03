#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int>arr1(nums1.size());        
        vector<int>arr2(nums1.size());
        int n = nums1.size();
        ordered_multiset s;
        for(int i = 0 ; i< nums2.size() ;i++){
            arr1[i] = nums1[i] - nums2[i];
            arr2[i] = arr1[i] + diff;
            s.insert(arr1[i]);
        }
        long long ans = 0;
        reverse(arr2.begin() ,arr2.end());
        for(auto i : arr2){
            s.erase(s.find_by_order(s.order_of_key(i - diff)));
            ans+=s.order_of_key(i + 1);

        }
        return ans;

    }
};