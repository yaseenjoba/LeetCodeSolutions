class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int , int>freq;
        sort(arr1.begin() , arr1.end());
        for(auto & i : arr1){
            freq[i]++;
        }
        vector<int>v;
        for(auto i : arr2){
            while(freq[i]--){
                v.push_back(i);
            }
        }
        for(auto i : arr1){
            if(freq[i] > 0){
                v.push_back(i);
            }
        }
        return v;
    }
};