/*
9:08 - 9:19
Overall it was a dp:
f[i][j]=min(f[i-1][j],f[i][j-1])+something
WA, get the max...


*/class Solution {
  public:
      int minPathSum(vector<vector<int>>& grid) {
          int n = grid.size();
          if (n==0)return 0;
          int m = grid[0].size();
          if (m==0)return 0;
          vector<vector<int>>ans(n+1,vector<int>(m+1,0));
          for(int i=2;i<=n;i++)
              ans[i][0]=0x7FFFFFFF;
          for(int j=2;j<=m;j++)
              ans[0][j]=0x7FFFFFFF;
          for(int i=1;i<=n;i++)
              for(int j=1;j<=m;j++){
                  ans[i][j]=grid[i-1][j-1]+min(ans[i-1][j],ans[i][j-1]);
              }
          return ans[n][m];
      }
  };