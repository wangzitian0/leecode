/**
25 min
one number can represent two info, then lots of index and 0 1 2 3 problems.

 */
class Solution {

public:
    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                int count = 0;
                for (int ii = i - 1; ii <= i + 1; ii++)
                    if (ii >= 0 && ii < n) {
                        for (int jj = j - 1; jj <= j + 1; jj++)
                            if (jj >= 0 && jj < m) {
                                if (i == ii & j == jj) {
                                    continue;
                                }
                                if (board[ii][jj] == 1 || board[ii][jj] == 3) {
                                    count++;
                                }
                            }
                    }
                // 0 dead->dead  1 live->dead
                // 2 dead->live  3 live->live
                if (board[i][j] == 0) {
                    if (count == 3) {
                        board[i][j] = 2;
                    } else {
                        board[i][j] = 0;
                    }
                } else {
                    if (count < 2) {
                        board[i][j] = 1;
                    } else if (count == 2 || count == 3) {
                        board[i][j] = 3;
                    } else if (count > 3) {
                        board[i][j] = 1;
                    }
                }
            }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                board[i][j] /= 2;
            }
    }
};