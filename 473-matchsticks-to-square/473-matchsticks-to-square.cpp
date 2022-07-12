class Solution {
public:
    bool brute(vector<int>& sides,int idx,vector<int>& m){
        if(idx==m.size()){
            return (sides[0]==0 && sides[1]==0 && sides[2]==0 && sides[3]==0) ;
        }       
        for(int i=0;i<4;i++){
            if(sides[i]<m[idx]) continue;
            sides[i]-=m[idx];
            if(brute(sides,idx+1,m)) return true;
            sides[i]+=m[idx];
        }
       return false; 
    }
    bool makesquare(vector<int>& m) {
       int sum = 0;
        for(auto it: m) 
            sum+=it;
        if(sum%4!=0 || m.size()<=3) return false;
        sum/=4;
        vector<int> sides(4,sum);
        sort(m.rbegin(),m.rend());
        return brute(sides,0,m);    
    }
};