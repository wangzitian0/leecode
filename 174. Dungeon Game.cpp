/**
just a dp.

 */

 class Solution {
 public:
     int calculateMinimumHP(vector<vector<int>>& dungeon) {
         int n = dungeon.size();
         int m = dungeon[0].size();
         vector<vector<int>> ans(n, vector<int>(m, 1e9));
         ans[n - 1][m - 1] = 1;
         for (int i = n - 1; i >= 0; i--) {
             for (int j = m - 1; j >= 0; j--) {
                 if (i < n - 1)
                     ans[i][j] = min(ans[i][j], ans[i + 1][j]);
                 if (j < m - 1)
                     ans[i][j] = min(ans[i][j], ans[i][j + 1]);
                 ans[i][j] -= dungeon[i][j];
                 if (ans[i][j] <= 0)
                     ans[i][j] = 1;
             }
         }
         for (int i = 0; i < n; i++) {
             for (int j = 0; j < m; j++) {
                 cout << ans[i][j] << " ";
             }
             cout << endl;
         }
         return ans[0][0];
     }
 };