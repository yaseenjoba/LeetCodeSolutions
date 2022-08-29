class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        int l = 0 , r = n - 1;
        while(l  < r){
            int mid = l  +(r - l)/2;
            if(arr[mid]  >= x){
                r = mid;
            }else l = mid + 1;
        }
        int low = max(0 , l - k);        
        int high = min(n - 1 , l + k);
        priority_queue<pair<int, int> , vector<pair<int, int>> , greater<pair<int , int>>>pq;
        for(int i = low ; i <=high ; i++){
            pq.push({abs(arr[i] - x) ,i});
        }
        vector<int>ans;
        while(k--){
            ans.push_back(arr[pq.top().second]);
            pq.pop();
        }
        sort(ans.begin() , ans.end());
        return ans;

    }
};