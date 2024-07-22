/**
5 min
f[i] = min(f[i-1], f[i-2]+nums[i])

 */

 class Solution {
 public:
     int rob(vector<int>& nums) {
         vector<int>ans(nums.size() + 1);
         for (int i = 1; i <= nums.size(); i++) {
             ans[i] = max(ans[i-1], ans[i]);
             if (i >= 2) {
                 ans[i] = max(ans[i], ans[i-2] + nums[i-1]);
             } else {
                 ans[i] = max(ans[i], nums[i-1]);
             }
         }
         return ans[nums.size()];
     }
 };