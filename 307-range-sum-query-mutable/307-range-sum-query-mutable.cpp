class NumArray {
public:
   vector<int>tree;
    int n;
    vector<int>arr;
    int sum(int k){
        int s =0;
        while(k>=1){
            s+=tree[k];
            k-= k&-k;
        }
        return s;
    }
    void add(int k,int x){
        while(k<=n){
            tree[k] += x;
            k+=k&-k;
        }
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        tree.assign(n  + 1 , 0);
        arr = nums;
        int idx = 1;
        for(auto i : arr){
            add(idx++,i);
        }
    }
    
    void update(int index, int val) {
        int edit = val  - arr[index];
        add(index  + 1 , edit);
        arr[index] = val;
    }
    
    int sumRange(int left, int right) {
        left++ ,right++;
        return sum(right) - (left == 0 ? 0 : sum(left - 1));
        return 0;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */