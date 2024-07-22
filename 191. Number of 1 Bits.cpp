/**
2min about
just use the lowbit.

 */

class Solution {
public:
    inline int lowbit(int n) { return n & (-n); }
    int hammingWeight(int n) {
        if (n == 0)
            return 0;
        return hammingWeight(n & (~lowbit(n))) + 1;
    }
};