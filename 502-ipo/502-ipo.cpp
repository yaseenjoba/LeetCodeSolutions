class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<pair<int  ,int> , vector<pair<int, int>>>maxProfit;
        priority_queue<pair<int  ,int> , vector<pair<int, int>> , greater<pair<int, int>>>minCapital;
        int n = profits.size();
        for(int i = 0 ; i  < n ;i++){
            minCapital.push({capital[i] , i});
        }
        int have = w;
        for(int i = 0 ; i <k ;i++){
            while(!minCapital.empty() && minCapital.top().first <= have){
                maxProfit.push({profits[minCapital.top().second] , minCapital.top().second});
                minCapital.pop();
            }
            if(maxProfit.empty())break;
            have+=maxProfit.top().first;
            maxProfit.pop();
        }
        return have;

    }
};