/* atoi
*  2015.8.11 published.
*  Author: tywu
*  Runtime: 8ms 1045 test cases passed.
*/

/* Time:  O(n)
*  Space: O(1)
*/

class Solution {
public:
    int myAtoi(string str) {
        int len = str.length();
        int cur = 0;
        int val = 0;
        int sign = 1;
        while(str[cur]==' ') cur++;
        if(str[cur] == '-'){
            sign = -1;
            cur++;
        }
        else if(str[cur] == '+') cur++;
        while(cur<len){
            if('0' <= str[cur] && str[cur] <= '9'){
                int add_val = (str[cur]-'0');
                if(INT_MAX/10 < val || INT_MAX-add_val < val*10){
                    if(sign<0) return INT_MIN;
                    else return INT_MAX;
                }
                val*=10;
                val += add_val;
                cur++;
            }
            else break;
        }
        if(sign <0) return -val;
        return val;
    }
};
