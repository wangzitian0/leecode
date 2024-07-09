/*
9:45 -9:56
WA1: understand wrong, the condition is that can reaching last index.
WA2: wrong idea about index. last index was n-1.....
*/class Solution {
  public:
      bool canJump(vector<int>& nums) {
          int n = nums.size();
          int max_pos = 0;
          for (int i=0;i<n;i++)
          if(max_pos<i){
              return false;
          } else {
              max_pos = max(max_pos, i+nums[i]);
          }
          return max_pos>=n-1;
      }
  };