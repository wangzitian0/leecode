/**
10 min
bfs or dfs

 */

 class Solution {
 private:
     int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
     vector<vector<int>> flag;
     int n, m;
     void dfs(int x, int y, int curFlag, const vector<vector<char>>& grid) {
         flag[x][y] = curFlag;
         for (int d = 0; d < 4; d++) {
             int dx = x + dir[d][0];
             int dy = y + dir[d][1];
             if (dx >= 0 && dx < n && dy >= 0 && dy < m && grid[dx][dy] == '1' &&
                 flag[dx][dy] == 0) {
                 dfs(dx, dy, curFlag, grid);
             }
         }
     }

 public:
     int numIslands(vector<vector<char>>& grid) {
         n = grid.size();
         m = grid[0].size();
         flag.assign(n, vector<int>(m, 0));
         int curFlag = 0;
         for (int i = 0; i < n; i++)
             for (int j = 0; j < m; j++) {
                 if (grid[i][j] == '1' && flag[i][j] == 0) {
                     dfs(i, j, ++curFlag, grid);
                 }
             }
         return curFlag;
     }
 };