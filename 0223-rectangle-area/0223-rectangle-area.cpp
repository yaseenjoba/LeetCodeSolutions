class Solution {
public:
    int area (int x1 , int y1 , int x2 , int y2){
        return abs(x1 -  x2) * abs(y1 - y2);
    }
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int x_overlap = min(ax2 , bx2) - max(ax1 , bx1);
        int y_overlap = min(ay2 , by2) - max(ay1 , by1);
        int area_overlap = 0;
        if(x_overlap > 0 && y_overlap >0)area_overlap =y_overlap*x_overlap;
        return 
            area(ax1 ,ay1 , ax2 , ay2) + area(bx1 ,by1 , bx2 , by2) - area_overlap;
    }
};