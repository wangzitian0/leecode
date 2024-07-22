/**
12 min
a dp, if f[i][j] was square of k,
f[i][j], f[i-1][j-1], f[i][j-1], f[i-1][j] at least were square of k-1,
then use a array to record the max length of f[i][j], which equal to min
value of above f[][]s.

 */
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> maxSquare(n + 1, vector<int>(m + 1, 0));
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (matrix[i - 1][j - 1] == '1') {
                    int minLen = maxSquare[i - 1][j - 1];
                    minLen = min(minLen, maxSquare[i - 1][j]);
                    minLen = min(minLen, maxSquare[i][j - 1]);
                    maxSquare[i][j] = minLen + 1;
                    ans = max(ans, maxSquare[i][j] * maxSquare[i][j]);
                }
            }
        }
        return ans;
    }
};