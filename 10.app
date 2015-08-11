/* Regular Expression Matching
*  2015.8.11 published.
*  Author: tywu
*  Runtime: 16ms 445 test cases passed.
*/

// T: O(MN), S: O(MN) ... bad.
class Solution {
public:
    bool isMatch(string s, string p) {
        int s_len = s.size();
        int p_len = p.size();
        vector<vector<bool>> dp(s_len+1, vector<bool>(p_len+1, false));
        dp[0][0] = true;
        for (int i = 1; i <= p_len; ++i)
            dp[0][i] = i > 1 && '*' == p[i - 1] && dp[0][i - 2];
        for(int i = 1; i <= s_len ; ++i){
            for(int j = 1; j <= p_len; ++j){
                if(p[j-1]!='*'){
                    dp[i][j] = dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || '.' == p[j - 1]);
                }else {
                    dp[i][j] = dp[i][j - 2] || (s[i - 1] == p[j - 2] || '.' == p[j - 2]) && dp[i - 1][j];
                }

            }
        }
        return dp[s_len][p_len];
    }
};
