/*  Palindrome Number
*   2015.8.11 published.
*   Author: tywu
*   Runtime: 72ms 11506 test cases passed.
*/

// Time : O(N) where N is x's digi-num. 
// Space: O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
        return false;
        int num=x;
        int a=0;
        while(x) {
            a=a*10 + x%10;
            x=x/10;
        }
        return a==num;
    }
};
