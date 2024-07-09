/*
9:20 - 9:24
Overall it was a dp:
f[i][j]=f[i-1][j]+f[i][j-1]


*/
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>ans(n+1,vector<int>(m+1,0));
        ans[1][0]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                ans[i][j]=ans[i-1][j]+ans[i][j-1];
        return ans[n][m];
    }
};