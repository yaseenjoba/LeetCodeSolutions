/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    long long bs(long long st , long long en){
        while(st<en){
            long long mid= st+(en-st+1)/2;

             if(guess(mid)==1 ||guess(mid)==0)
                st=mid;
             else
                en=mid-1;
        }
        return st;
    }
    int guessNumber(int n) {
        if(n==1)return 1;
        return bs(0,n);
    }
};