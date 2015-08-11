/* Reverse Integer
*  2015.8.11 published.
*  Author: tywu
*  Runtime: 8ms 1032 test cases passed.
*/

/* Time:  O(N), where N is digi-num.
*  Space: O(1)
*/
class Solution {
public:
    int reverse(int x) {
        if(x == INT_MIN) return 0;
        int val = 0;
        int sign = 1;
        if(x < 0) {
            sign = -1;
            x = -x;
        }
        while(x){
            if( val < INT_MAX/10 ||(val == INT_MAX/10 && x%10<=(INT_MAX - INT_MAX/10)) ) {
                val *= 10;
                val += x%10;
                x/=10;
            }
            else return 0;
        }
        if(sign < 0) return -val;
        return val;
    }
};
