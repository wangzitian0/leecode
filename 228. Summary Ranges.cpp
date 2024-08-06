/**
10 min.
just scan.

 */


 class Solution {
 public:
     vector<string> summaryRanges(vector<int>& nums) {
         vector<string> ans;
         int lastPos = 0;
         for (int i = 0; i < nums.size(); i++) {
             if (i + 1 == nums.size() || nums[i + 1] != nums[i] + 1) {
                 string cur = to_string(nums[lastPos]);
                 if (i - lastPos > 0) {
                     cur += "->" + to_string(nums[i]);
                 }
                 ans.push_back(cur);
                 lastPos = i + 1;
             }
         }
         return ans;
     }
 };