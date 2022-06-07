class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<double>v;
        for(auto i : nums1){
            v.push_back(i);
        }
        for(auto i : nums2){
            v.push_back(i);
        }
        sort(v.begin() , v.end());
        if(v.size() %2){
            return v[v.size()/2];
        }else{
            int r  = v.size()/2;
            int l = r - 1;
            return (v[l] + v[r])/2;
        }
        
    }
};