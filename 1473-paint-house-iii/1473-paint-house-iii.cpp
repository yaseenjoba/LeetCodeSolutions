class Solution {
public:
    int nn;
    int sz;
    int dp[101][101][101];
    int sol(int i , int last , int rest ,vector<int>& houses , vector<vector<int>>& cost){
        if(i == sz)return (rest == 0 ? 0 : 1e9);
        if(rest < 0)return 1e9;
        int ans = 1e9;
        if(~dp[i][rest][last])return dp[i][rest][last]; 
        if(houses[i] == 0){ // the house can be painted with any of colour 1 to n
            for(int j=0; j<nn; j++){
                ans = min(ans, cost[i][j] + sol(i + 1, j + 1, last == j+1?rest:rest - 1, houses, cost));
            }
        }else{
             ans = min(ans, sol(i + 1, houses[i], last == houses[i]?rest: rest - 1, houses, cost));
        }
        return dp[i][rest][last] = ans;
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        nn = n;
        sz = houses.size();
        memset(dp , -1 , sizeof dp);
        int ans = sol(0 , 0 , target, houses , cost);
        return ans == 1e9 ? -1:ans;
    }
};