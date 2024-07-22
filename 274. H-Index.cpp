/**
3 min
just binary search.

 */
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int low = 0, up = min(1001, (int)citations.size() + 1);
        while (low + 1 < up) {
            int mid = (low + up) / 2;
            int sum = 0;
            for (auto citation : citations) {
                if (citation >= mid) {
                    sum++;
                }
            }
            if (sum >= mid) {
                low = mid;
            } else {
                up = mid;
            }
        }
        return low;
    }
};