// 21:22 - 21:36
class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPalin(n, vector<bool>(n, false));
        vector<int> ans(n, n + 1);
        for (int i = 0; i < s.size(); i++) {
            for (int j = 0; j <= i; j++) {
                isPalin[j][i] = true;
                if (s[j] != s[i])
                    isPalin[j][i] = false;
                if (j + 1 <= i - 1 && !isPalin[j + 1][i - 1])
                    isPalin[j][i] = false;
            }
            if (isPalin[0][i]) {
                ans[i] = 0;
            }
            for (int j = 0; j < i; j++)
                if (isPalin[j + 1][i]) {
                    ans[i] = min(ans[i], ans[j] + 1);
                }
        }
        return ans[n - 1];
    }
};