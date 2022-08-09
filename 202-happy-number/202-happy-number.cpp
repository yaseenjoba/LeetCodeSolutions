class Solution {
public:
    bool isHappy(int num) {
     int slow = num , fast = num;
    do{
      slow = SquareSum(slow);
      fast = SquareSum(SquareSum(fast));
      if(fast == 1)return true;
    }while(slow != fast);
    return false;
  }
  int SquareSum(int x){
    int sum = 0;
    while(x > 0){
      int d = x%10;
      sum+= d*d;
      x/=10;
    }
    return sum;
  }
};