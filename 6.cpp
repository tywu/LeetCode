/* ZigZag Conversion
* 2015.8.11 published.
* Author: tywu
* Runtime: 24ms 1158 test cases passed.
*/

/* Time : O(N)
*  Space: O(1)
*/
class Solution {
public:
    string convert(string s, int numRows) {
       if(numRows == 1 || s.length() < numRows) return s;
       const int strlen = s.length();
       const int base = 2*numRows-2;
       stringstream ss;

       for(int i = 0 ; i < numRows; ++i) {
           if (i== 0 || i == numRows -1) {
                for (int j = i; j <  strlen;j += base){
                    ss << s[j];
                }

           }else{
                for (int j = i; j < strlen; j += base){
                    ss << s[j];
                    int next = j + base - (2*i);
                    if ( next < strlen){
                        ss << s[next];
                    }
                }
            }
       }
       return ss.str();
    }
};
