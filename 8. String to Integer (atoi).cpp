/*
标准库函数 Atoi 的实现。

各种边边角角
WA1， 没考虑"+-2"
WA2,  没考虑"    010"
WA3， 没考虑"   +0 123"
WA4,  没考虑"2147483648"，超界限直接返最大值
WA5,  没考虑"  - 321"
WA6,  没考虑"      -11919730356x"
*/
class Solution {
public:
    int myAtoi(string str) {
        int len = str.size(), ans=0, number=0, f=0;
        int ZW=2147483647, FW=-ZW-1;
        for(int i=0;i<len;i++) {
            if(str[i]>='0'&&str[i]<='9') {
                if(!f)f=1;
                if(ans <= ZW/10 && ans >= FW/10 &&
                   (f>0&&ans*10 <= ZW - f*(str[i] - '0') ||
                   f<0&&ans*10 >= FW - f*(str[i] - '0'))) {
                    number = 1;
                    ans = ans*10 + f*(str[i] - '0');
                } else if (f>0)
                    return ZW;
                else
                    return FW;
            } else if(str[i]=='-'||str[i]=='+') {
                if(f)return 0;
                number = 1;
                f=str[i]=='-'?-1:1;
            } else if(str[i]!=' '|| (str[i]==' '&&number))
                return ans;
        }
        return ans;
    }
};