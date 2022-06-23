class Solution {
public:

    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin() , courses.end() , [&](vector<int>&a  , vector<int>&b){return a[1] < b[1];});
        priority_queue<int>pq;
        int cur = 0;
        for(auto i : courses){
            if(cur + i[0]  <=  i [1]){
                pq.push(i[0]);
                cur += i[0];
            }else if(!pq.empty()  && pq.top() >= i[0]){
                cur-=pq.top();
                cur+=i[0];
                pq.pop();
                pq.push(i[0]);
            }    
        }
        return pq.size();
    }
};