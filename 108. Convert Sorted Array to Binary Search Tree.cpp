/**
11:32 - 11:40
use the number at the position mid = (S+T)/2;
recursively resolve it.

 */

 /**
  * Definition for a binary tree node.
  * struct TreeNode {
  *     int val;
  *     TreeNode *left;
  *     TreeNode *right;
  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  * };
  */
 class Solution {
 private:
     TreeNode* buildBST(vector<int>& nums, int numsS, int numsT) {
         if(numsS>=numsT)return nullptr;
         int numsMid = (numsS+numsT)/2;
         TreeNode* cur = new TreeNode(nums[numsMid]);
         cur->left = buildBST(nums,numsS,numsMid);
         cur->right = buildBST(nums,numsMid+1,numsT);
         return cur;
     }
 public:
     TreeNode* sortedArrayToBST(vector<int>& nums) {
         return buildBST(nums, 0, nums.size());
     }
 };