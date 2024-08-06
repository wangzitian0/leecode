/**
10 min think about the problem, very interesting problem.
5 min write code.
no idea about how to cover all interval.
then try to group by the interval.
then find that shot point should always in the begin point or end point.
so from left to right, for each interval, shot at the end point. auto remove other interval.

for a uncovered interval, at least need one shot, always shot at the end point.
the shot order do not matters, so we just shot from left, and shot one by one.
from left to right, shot at the first end point, problem become a smaller problem.

 */

class Solution {
private:

    static int cmp(const vector<int>& p, const vector<int>& q) {
        if (p[1] != q[1]) {
            return p[1] < q[1];
        }
        return p[0] < q[0];
    }
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), cmp);
        int curShot = points[0][1], ans = 1;
        for (int i = 0; i < points.size(); i++) {
            if (curShot>=points[i][0]) {
                continue;
            } else {
                curShot = points[i][1];
                ans++;
            }
        }
        return ans;
    }
};