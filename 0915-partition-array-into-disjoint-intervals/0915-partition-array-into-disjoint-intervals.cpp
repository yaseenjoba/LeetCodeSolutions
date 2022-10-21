class Solution {
public:
    int partitionDisjoint(vector<int>& nums) {
        multiset<int>left , right;
        for(auto i : nums){
            right.insert(i);
        }
        for(auto &i : nums){
            left.insert(i);
            right.erase(right.find(i));
            if(*left.rbegin() <= *right.begin()){
                return left.size();
            }
        }
        return -1;
    }
};