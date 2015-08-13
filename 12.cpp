// int to rome

class Solution {
public:
    string intToRoman(int num) {
        const string THOUS[]  = {"","M","MM","MMM"};
        const string HUNDS[]  = {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM"};
        const string TENS[]   = {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC"};
        const string ONES[]   = {"","I","II","III","IV","V","VI","VII","VIII","IX"};
        string result;
        result += THOUS[(num/1000)%10];
        result += HUNDS[(num/100)%10];
        result += TENS[(num/10)%10];
        result += ONES[num%10];
        return result;
    }
};
