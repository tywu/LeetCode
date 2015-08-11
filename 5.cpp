/* Longest Palindromic Substring
* 2015.8.10. published.
* Author: tywu
* Runtime: 4ms 88 test cases.
*/

/*
*  Time:  O(n)
*  Space: O(1)
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() < 2)
            return s;
        int len = s.size();
        int max_left = 0, max_len = 1;
        int left, right;
        for (int start = 0; start < len && len - start > max_len / 2;) {
            left = right = start;
            while (right < len - 1 && s[right + 1] == s[right])
                ++right;
            start = right + 1;
            while (right < len - 1 && left > 0 && s[right + 1] == s[left - 1]) {
                ++right;
                --left;
            }
            if (max_len < right - left + 1) {
                max_left = left;
                max_len = right - left + 1;
            }
        }
        return s.substr(max_left, max_len);
    }
};
