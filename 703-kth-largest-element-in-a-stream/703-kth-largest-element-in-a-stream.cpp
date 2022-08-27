class KthLargest {
public:
    priority_queue<int , vector<int> , greater<int>>pq;
    int kk;
    KthLargest(int k, vector<int>& nums) {
        kk = k;
        for(auto i : nums)
            add(i);
    }
    
    int add(int val) {
        pq.push(val);
        while((int)pq.size() > kk)pq.pop();
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */