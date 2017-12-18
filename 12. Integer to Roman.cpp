/*
数字转罗马数字

没啥技巧，仔细看看 wiki 就好

*/

class Solution {
public:
    string intToRoman(int num) {
        string c[4][10]={
            {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
            {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
            {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
            {"", "M", "MM", "MMM"},
        };
        string ans;
        int p[4]={}, pos=0;
        while(num) {
            p[pos++] = num%10;
            num /= 10;
        }
        while(--pos>=0)
            ans += c[pos][p[pos]];
        return ans;
    }
};