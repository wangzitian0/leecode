/*
参考这个题目吧，基本上一摸一样，10. Regular Expression Matching

DP 的时候注意下边边角角就好了
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        bool **f = new bool*[n+1]();
        for(int i=0;i<=n;i++){
            f[i] = new bool[m+1]();
        }
        f[0][0]=true;
        for(int i=0;i<=n;i++)
            for(int j=1;j<=m;j++) {
                if(i && (s[i-1]==p[j-1] || p[j-1]=='?'))
                    f[i][j]|=f[i-1][j-1];
                if(p[j-1]=='*') {
                    if(i)f[i][j]|=f[i-1][j];
                    f[i][j]|=f[i][j-1];
                }
            }
        return f[n][m];
    }
};