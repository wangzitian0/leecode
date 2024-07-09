/*
8:57-9:20
Overall it was a dp:
f[i][j]=f[i-1][j]+f[i][j-1]


*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n = obstacleGrid.size();
        if(n==0)return 0;
        int m = obstacleGrid[0].size();
        if(m==0)return 0;
        vector<vector<int>>ans;
        ans.assign(n+1,vector<int>(m+1,0));
        ans[0][1]=1;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(obstacleGrid[i-1][j-1])
                    ans[i][j]=0;
                else ans[i][j]=ans[i-1][j]+ans[i][j-1];
        return ans[n][m];
    }
};