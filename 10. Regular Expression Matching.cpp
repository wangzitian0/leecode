/*
给一个正则式和一个字符串，判断模式是不是完全匹配的。

WA1, 对于"aab", "c*a*b"这组例子理解错了。进而发现以前对正则式*的理解是不对的。
.*表示任意长度任意字符，a*表示0个或者多个 a
*/
class Solution {
public:
    bool isMatch(string s, string p) {
        int slen = s.size(), plen = p.size();
        bool** f = new bool*[slen+1];
        for(int i = 0; i <= slen; ++i) {
            f[i] = new bool[plen];
            memset(f[i], 0, sizeof(bool)*(plen+1));
        }
        f[0][0]=true;
        for(int i=0;i<=slen;i++)
            for(int j=1;j<=plen;j++) {
                if(i&&(s[i-1]==p[j-1]||p[j-1]=='.'))
                    f[i][j]|=f[i-1][j-1];
                if(p[j-1]=='*') {
                    if(i&&(p[j-2]==s[i-1]||p[j-2]=='.'))
                        f[i][j]|=f[i-1][j]|f[i][j-2];
                    if(j>=2)f[i][j]|=f[i][j-2];
                }
            }
        return f[slen][plen];
    }
};