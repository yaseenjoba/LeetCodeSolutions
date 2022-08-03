class MyCalendar {
public:
    map<int ,int>mm;
    MyCalendar() {
        mm.clear();
    }
    
    bool book(int start, int end) {
      auto f  = mm.upper_bound(start);
      if(f!=mm.end() && (*f).second < end)return false;
      mm[end] = start;
      return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */