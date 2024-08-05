/**
21:05 - 21:15
just scan.

 */

 class Solution {
 public:
     bool containsNearbyDuplicate(vector<int>& nums, int k) {
         unordered_map<int, int>g;
         for(int i=0;i<nums.size();i++){
             if(g[nums[i]]>0) {
                 return true;
             } else {
                 g[nums[i]]=0;
             }
             g[nums[i]]++;
             if (i>=k) {
                 g[nums[i-k]]--;
             }
         }
         return false;
     }
 };