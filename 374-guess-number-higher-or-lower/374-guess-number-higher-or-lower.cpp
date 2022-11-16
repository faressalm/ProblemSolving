/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(n==1)
            return 1;
        int start = 1;
        int mid = n/2;
        while(guess(mid)!=0){
            if(guess(mid)==-1){
                n = mid-1;
            }else{
                start = mid+1;
            }
            mid = start + (n-start)/2;
        }
        return mid;
    }
};