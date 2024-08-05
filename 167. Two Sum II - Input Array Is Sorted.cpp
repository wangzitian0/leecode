/**
20:32 - 20:42
just a two pointer scan.
for loop in the left enum.
pointer in the right enum, move to left, and become less.
- once less than 0, it's time to move left point to right, which will make the sum bigger.

 */


class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<vector<int>> edge(n, vector<int>());
        vector<int> du(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0 && ratings[i - 1] < ratings[i]) {
                edge[i - 1].push_back(i);
                du[i]++;
            }
            if (i + 1 < n && ratings[i] > ratings[i + 1]) {
                edge[i + 1].push_back(i);
                du[i]++;
            }
        }
        queue<int> que;
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            if (du[i] == 0) {
                que.push(i);
                ans[i] = 1;
            }
        }
        while (!que.empty()) {
            int cur = que.front();
            que.pop();
            for (int i = 0; i < edge[cur].size(); i++) {
                int tar = edge[cur][i];
                ans[tar] = max(ans[tar], ans[cur] + 1);
                du[tar]--;
                if (du[tar] == 0) {
                    que.push(tar);
                }
            }
            edge[cur].clear();
        }
        int resp = 0;
        for (auto as : ans) {
            resp += as;
        }
        return resp;
    }
};