#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
class MedianFinder {
public:
    ordered_multiset s;
    MedianFinder() {
        s.clear();
    }
    
    void addNum(int num) {
        s.insert(num);
    }
    
    double findMedian() {
        if(s.size() % 2 == 0){
            int l = s.size()/2 - 1;
            int r = s.size()/2;
            return  1.0*(*s.find_by_order(l) + *s.find_by_order(r))/2.0;
        }
        return *s.find_by_order(s.size()/2);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */