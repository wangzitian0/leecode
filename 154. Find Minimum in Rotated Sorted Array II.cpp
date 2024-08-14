/**
no idea, only O(n) for the case 3 1 3 3

 */

 class Solution {
 public:
     int findMin(vector<int>& nums) {
         while (nums.size() > 1 && nums[0] == nums.back())
             nums.pop_back();
         int low = 0, up = nums.size();
         while (up > 1 + low) {
             int mid = (low + up) / 2;
             if (nums[low] <= nums[mid]) {
                 low = mid;
             } else if (nums[low] > nums[mid]) {
                 up = mid;
             }
         }
         return nums[up % nums.size()];
     }
 };