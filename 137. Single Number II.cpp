/**
30min
have an easy idea is the maintenance pow of 3, rather than the xor of 2.
used a stupid way to got the bits.

 */

// first  0    1    0
// second 0    0    1
// first:
// 001->1
// 101->0
// 011->0
// 000->0
// 100->1
// 010->0
// second:
// 001->0
// 101->1
// 011->0
// 000->0
// 100->0
// 010->1
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        pair<int, int> ans;

        for (int num : nums) {
            pair<int, int> cur = ans;
            cur.first = (~ans.first & ~ans.second & num) |
                        (ans.first & ~ans.second & ~num);
            cur.second = (ans.first & ~ans.second & num) |
                        (~ans.first & ans.second & ~num);
            ans = cur;
        }

        return ans.first;
    }
};