class Solution {
public:
    int findUnsortedSubarray(vector<int>& arr) {
         int l = 0 , r = arr.size() - 1;;
        while(r > 1 && arr[r] >= arr[r - 1])r--;
        while(l < r && arr[l] <= arr[l + 1])l++;
        if(r <= l)return 0;
        int mi = 1e9  , mx = -1e9;
        for(int i = l ; i<=r;i++){
            mi = min(mi , arr[i]);
            mx = max(mx , arr[i]);
        }
        while(l > 0 && arr[l -1] > mi)l--;
        while(r < arr.size() - 1 && arr[r + 1] < mx)r++;
        return r - l + 1;
    }
};