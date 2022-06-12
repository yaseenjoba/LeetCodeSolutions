class Solution {
public:
    bool isValid(long long x,long long num){
        return x*x <= num;
    }
    long long binarySearch(long long st , long long en,long long num){
        while(st<en){
            long long mid= st+(en-st+1)/2;

             if(isValid(mid,num))
                st=mid;
             else
                en=mid-1;
        }
        return st;
    }
    bool isPerfectSquare(long long num) {
        long long c = binarySearch(0,1e6,num);
        if(c*c == num){
            return true;
        }
        return false;
    }
};