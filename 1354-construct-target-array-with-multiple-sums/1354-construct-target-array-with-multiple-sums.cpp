class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<int>pq;
        long long sum = 0;
        for(auto i : target){
            pq.push(i);
            sum+=i;
        }
        while(pq.top() != 1){
            int x = pq.top();
            pq.pop();
            sum-=x;
            if(sum >= x || sum <= 0)return false;
            x %= sum;
            sum+= x;
            pq.push(x?x:sum);
        }
        return true;
    }
};