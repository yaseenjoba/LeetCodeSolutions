class Solution {
public:
    
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        sort(horizontalCuts.begin(), horizontalCuts.end());
		int mxh = horizontalCuts[0];
        for(int i=1; i<horizontalCuts.size(); i++){
            mxh = max(mxh, horizontalCuts[i] - horizontalCuts[i-1]);
        }
        
        verticalCuts.push_back(w);
        sort(verticalCuts.begin(), verticalCuts.end());
		int mxv = verticalCuts[0];
        for(int i=1; i<verticalCuts.size(); i++){
            mxv = max(mxv, verticalCuts[i] - verticalCuts[i-1]);
        }
		
        return (1LL*mxh*mxv) % 1000000007;
    }
};