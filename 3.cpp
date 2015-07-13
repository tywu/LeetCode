/* Longest Substring Without Repeating Characters
*  2015.07.12 published.
*  Author: Tai-Yi Wu.
*  Runtime 68ms 981/981 passed.
*/

/*
*  Time : O(n)
*  Space: O(n)
*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i = 0, j = 0
        int max_substring_length=0;
        if(s.size()==0)return 0;
        if(s.size()==1)return 1;
        unordered_map<char,bool> table;
        while ( (i < s.size()) && (j < s.size()) ){
            if (!table[s[i]]){
                table[s[i]] = true;
                max_substring_length = max(max_substring_length,i-j+1);
                i++;
            }else{
                max_substring_length = max(max_substring_length,i-j);
                table[s[j]] = false;
                j++;
            }
        }
        return max_substring_length;
    }
};
