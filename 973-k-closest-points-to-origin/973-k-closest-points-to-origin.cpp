class Point {
 public:
  int x = 0;
  int y = 0;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  int distFromOrigin() const {
    // ignoring sqrt
    return (x * x) + (y * y);
  }

  const bool operator<(const Point& p) { return p.distFromOrigin() > this->distFromOrigin(); }
};

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
       vector<Point>p;
        for(auto i : points){
            p.push_back(Point(i[0] , i[1]));
        }
        vector<Point>maxHeap(p.begin() , p.begin() + k);
        make_heap(maxHeap.begin(), maxHeap.end());
        for(int i = k ; i < p.size() ; i++){
            if(p[i].distFromOrigin() < maxHeap.front().distFromOrigin()){
                pop_heap(maxHeap.begin() , maxHeap.end());
                maxHeap.pop_back();
                maxHeap.push_back(p[i]);
                push_heap(maxHeap.begin() , maxHeap.end());
            }
        }
        
        vector<vector<int>> ans;;
        for(auto i : maxHeap){
            ans.push_back({i.x , i.y});
        }
        return ans;
    }
        
};