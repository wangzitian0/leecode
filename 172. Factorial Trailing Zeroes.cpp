/**
about 10 min
min of factor 2 and 5

WA1: has a type
            int nn = n; // F**k

 */

class Solution {
public:
    int trailingZeroes(int n) {
        pair<int, int> ans; // factor of 2 and 5;
        for (int i = 1; i <= n; i++) {
            int nn = i;
            while (nn % 2 == 0) {
                ans.first++;
                nn /= 2;
            }
            while (nn % 5 == 0) {
                ans.second++;
                nn /= 5;
            }
        }
        return min(ans.first, ans.second);
    }
};