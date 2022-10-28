class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int ans1 = 0 ;
        for(int i = min(start , destination) ; i<max(start , destination); i++){
            ans1+= distance[i];
        }
        int ans2 = 0;
        int i = max(start , destination) , n = distance.size();
        while(i != min(start , destination)){
            ans2+=distance[i];
            i++;
            i%=n;
        }
        return min(ans1 ,ans2);
        
    }
};