/**
// 20:45 - 20:53
just a two pointer scan.
for loop in the left enum.
pointer in the right enum, move to left, and become less.
- once less than 0, it's time to move left point to right.
- record the ans if the condition was meet.

 */

// 20:45 - 20:53
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int postPos = -1, sum = 0;
        int ans = nums.size() + 1;
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            while (sum >= target) {
                ans = min(ans, i - postPos);
                sum -= nums[++postPos];
            }
        }
        if (ans == nums.size() + 1) {
            return 0;
        }
        return ans;
    }
};